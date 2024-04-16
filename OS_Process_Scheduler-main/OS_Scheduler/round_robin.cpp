#include "round_robin.h"

#include <vector>
#include <iostream>
#include <thread> // Include the thread library
#include <chrono> // Include chrono for time-related functions
#include <mutex>


using namespace std;

extern QVector<int> inProgress;

class Processes {
public:
    static int noOfProcess;
    int arrivalTime = 0;
    int burstTime = 0;
    int nextBurstTime = 0;

    int waiting = 0;
    int turnaround = 0;

public:
    Processes(int arrivalTime, int burstTime) {
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->nextBurstTime = burstTime;
        noOfProcess++;
    }

    void executeProcess() {
        nextBurstTime--;
    }

    static int getNoOfProcess() {
        return noOfProcess;
    }
};

class GanttChart{
public:
    static int n;
    int id;
    int start;
    int end;

    GanttChart(int id,int start){
        this->id = id;
        this->start = start;
    }

    void setEnd(int end){
        this->end = end;
        n++;
    }
};

class RoundRobin {
public:
    static int quantum;
    static int timer;
    static int lastArrivedProcessIndex;
    static int avgWait;
    static int avgTurn;
    static int RunningProcess;
    static vector<GanttChart> runningProcesses;
    static vector<Processes> queueOfAllProcesses;
    static vector<bool> firstExecution;
    static vector<int> readyQueue;
    static vector<bool> complete;
    //static std::mutex mtx; // Mutex for synchronization

public:

    static void addProcess(int arrivalTime, int burstTime) {
   //     std::lock_guard<std::mutex> lock(mtx); // Lock the mutex to avoid data races
        Processes p(arrivalTime, burstTime);
        queueOfAllProcesses.push_back(p);

        complete.push_back(0);
        readyQueue.push_back(0);
        firstExecution.push_back(1);
    }


    static void updateData() {
        cout << endl <<"At time = " << timer<<endl;
        cout << "Running Process is: " << RoundRobin::RunningProcess<<endl;
        for (int j = 0; j < Processes::noOfProcess; j++)
        {
            cout << "Next Burst of process " << j + 1 <<" = "<< RoundRobin::queueOfAllProcesses[j].nextBurstTime<<endl;
        }

        cout << "Ready Queue " << endl;
        for (int j = 0; j < Processes::noOfProcess; j++)
        {
            cout << RoundRobin::readyQueue[j]<<" ";
        }
        cout << endl;
    }

    static void enqueueProcess()
    {
        int i = 0;
        for (i = 0; (i < Processes::getNoOfProcess() - 1) && (readyQueue[i + 1] != 0); i++)
        {
            int temp = readyQueue[i];
            readyQueue[i] = readyQueue[i + 1];
            readyQueue[i + 1] = temp;
        }
        firstExecution[i - 1] = 0;
    }
    static void updateQueue()
    {
        int firstEmptyInReadyQueue = 0;
        for (int i = 0; i < Processes::getNoOfProcess(); i++)
        {
            /* Update the first place in ready queue */
            if (readyQueue[i] == 0)
            {
                firstEmptyInReadyQueue = i;
                break;
            }
        }
        readyQueue[firstEmptyInReadyQueue] = lastArrivedProcessIndex + 1; /* plus one because process names start from 1 */
        int i = firstEmptyInReadyQueue-1;
        while (firstExecution[readyQueue[i]]==0) {
            int temp = readyQueue[i];
            readyQueue[i] = readyQueue[i+1];
            readyQueue[i + 1] = temp;
            i--;
        }
    }

    static void checkNewArrival()
    {
        //std::lock_guard<std::mutex> lock(mtx); // Lock the mutex to avoid data races
        if (timer <= queueOfAllProcesses[Processes::getNoOfProcess() - 1].arrivalTime) /* As arrival time is sorted */
        {
            bool newArrival = false;
            for (int j = (lastArrivedProcessIndex + 1); j < Processes::getNoOfProcess(); j++)
            {
                if (queueOfAllProcesses[j].arrivalTime <= timer)
                {
                    if (lastArrivedProcessIndex < j)
                    {
                        lastArrivedProcessIndex = j;
                        newArrival = true;
                    }
                }
            }
            /* if a process arrives add it to the queue */
            if (newArrival)
                updateQueue();
        }
    }

    static bool isEndOfSched() {
        /* Termination Conditions */
        bool allFinish = true;

        for (int i = 0; i < Processes::getNoOfProcess(); i++)
        {
            if (queueOfAllProcesses[i].nextBurstTime != 0) {
                allFinish = false;
                cout<<"\nisEnd\n";
                break;

            }
        }
        return allFinish;
    }

    static void startScheduling() {
        timer = queueOfAllProcesses[0].arrivalTime;
        lastArrivedProcessIndex = -1;
        /* Execute first processes */
        for (int i = 0; i < Processes::getNoOfProcess(); i++)
        {
            if (queueOfAllProcesses[i].arrivalTime == timer) {
                readyQueue[i] = i + 1;
                lastArrivedProcessIndex++;
            }
        }

        while (1) {

            cout<<"No of Procecss "<<Processes::getNoOfProcess()<<endl;

            if (RoundRobin::isEndOfSched())
                break;


            // Loop till no process in queue
            for (int i = 0; (i < Processes::getNoOfProcess()) && (readyQueue[i] != 0); i++)
            {

                int ctr = 0; /* This counter to indicate the end of time slice */

                /* Loop till prosses being executed which at queue[0] finishes
                   or time slice ended
                */

                RunningProcess = readyQueue[0] - 1;
                bool isSched=0;
                int timeBefore=timer;
                while ((ctr < quantum) && ((queueOfAllProcesses[RoundRobin::RunningProcess]).nextBurstTime > 0))
                {
                    isSched=1;
                    queueOfAllProcesses[RoundRobin::RunningProcess].executeProcess(); /* reduce burst time as it being executed */
                    timer += 1;
                    ctr++;

                    inProgress.push_back((RoundRobin::RunningProcess)+1);
                    // Checking and Updating the ready queue until all the processes arrive
                    checkNewArrival();
                    //inProgress.push_back(RoundRobin::RunningProcess);
                    RoundRobin::updateData();
                    //if(ctr!= quantum)
                        //std::this_thread::sleep_for(std::chrono::seconds(1));
                }
                if(isSched){
                    runningProcesses.push_back(GanttChart(RunningProcess+1,timeBefore));
                    runningProcesses[GanttChart::n].setEnd(timer);
                }

                for(int i=0 ; i<RoundRobin::runningProcesses.size();i++){
                    cout << RoundRobin::runningProcesses.size()<<" " <<RoundRobin::runningProcesses[i].id<<" "<< RoundRobin::runningProcesses[i].start<<" "<<" "<< RoundRobin::runningProcesses[i].end<<endl;
                }
                cout << endl;

                // If a process is completed then store its exit time
                // and mark it as completed
                if ((queueOfAllProcesses[RoundRobin::RunningProcess].nextBurstTime == 0) && (complete[RoundRobin::RunningProcess] == false))
                {
                    queueOfAllProcesses[RoundRobin::RunningProcess].turnaround = timer - queueOfAllProcesses[RoundRobin::RunningProcess].arrivalTime;
                    queueOfAllProcesses[RoundRobin::RunningProcess].turnaround = timer - queueOfAllProcesses[RoundRobin::RunningProcess].arrivalTime;
                    complete[RoundRobin::RunningProcess] = true;
                }

                // checks whether or not CPU is idle
                bool idle = true;
                if (readyQueue[Processes::getNoOfProcess() - 1] == 0)
                {
                    for (int i = 0; (i < Processes::getNoOfProcess()) && (readyQueue[i] != 0); i++)
                    {
                        if (complete[readyQueue[i] - 1] == false)
                        {
                            idle = false;
                        }
                    }
                }
                else
                    idle = false;

                if (idle)
                {
                    timer++;
                    //RunningProcesses.push_back(0);
                    checkNewArrival();
                }

                // Enqueue the process after preemption
                enqueueProcess();

            }
            //std::this_thread::sleep_for(std::chrono::seconds(1));

        }
cout<<endl<<"Finish"<<endl;
    }

    static void findAvgAndWait() {
        /* Calculate turnaround and waiting time */
        for (int i = 0; i < Processes::getNoOfProcess(); i++)
        {
            queueOfAllProcesses[i].waiting = queueOfAllProcesses[i].turnaround - queueOfAllProcesses[i].burstTime;   /* Wait Time = Turnaround - Burst Time  */
        }

        for (int i = 0; i < Processes::getNoOfProcess(); i++)
        {
            avgWait += queueOfAllProcesses[i].waiting;
            avgTurn += queueOfAllProcesses[i].turnaround;
        }
        avgWait /= Processes::noOfProcess;
        avgTurn /= Processes::noOfProcess;
        //cout << "\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time"
        //     << endl;
        // for (int i = 0; i < Processes::getNoOfProcess(); i++)
        // {
        //     cout << i + 1 << "\t\t" << queueOfAllProcesses[i].arrivalTime << "\t\t"
        //          << queueOfAllProcesses[i].burstTime << "\t\t" << queueOfAllProcesses[i].waiting << "\t\t" << queueOfAllProcesses[i].turnaround << endl;
        // }
        // cout << "\nAverage wait time : " << (avgWait / Processes::getNoOfProcess())
        //      << "\nAverage Turn Around Time : " << (avgTurn / Processes::getNoOfProcess());

    }

    // Function to add a process every 1 second
    static void addProcessPeriodically() {
        while (true) {
            int arrival, burst;
            cout << "Process " << Processes::noOfProcess + 1 << endl;
            cout << "Enter Arrival Time:\n ";
            cin >> arrival;
            cout << "Enter burst Time:\n ";
            cin >> burst;

            RoundRobin::addProcess(arrival, burst);
            // Sleep for 1 second
            std::this_thread::sleep_for(std::chrono::seconds(20));
        }
    }
};

// Definition of static member variables
int Processes::noOfProcess = 0;
int RoundRobin::quantum = 0;
int RoundRobin::timer = 0;
int RoundRobin::lastArrivedProcessIndex = 0;
int RoundRobin::avgWait = 0;
int RoundRobin::avgTurn = 0;
int GanttChart::n = 0;
vector<Processes> RoundRobin::queueOfAllProcesses;
vector<int> RoundRobin::readyQueue;
vector<GanttChart> RoundRobin::runningProcesses;
vector<bool> RoundRobin::firstExecution;
vector<bool> RoundRobin::complete;
int RoundRobin::RunningProcess = 0;

//std::mutex RoundRobin::mtx; // Initialize static mutex

QVector<Process> round_robin::RR(QVector<Process> p, int tq,float &w_time) {

    QVector< Process > re;

    for(int i=0; i<p.size();i++){

        RoundRobin::addProcess(p[i].get_process_arrival_time(), p[i].get_process_burst_time());
    }

    RoundRobin::quantum = tq;

    // Create a thread to add processes periodically
    //std::thread addProcessThread(&RoundRobin::addProcessPeriodically);

    RoundRobin::startScheduling();



    // Join the thread
    //addProcessThread.join();


    for(int i=0 ; i<RoundRobin::runningProcesses.size();i++){
        cout<<RoundRobin::runningProcesses[i].id<<" " << RoundRobin::queueOfAllProcesses[RoundRobin::runningProcesses[i].id-1].arrivalTime <<" "
             <<0<<" "
             <<RoundRobin::runningProcesses[i].start<<" "
             <<RoundRobin::runningProcesses[i].end;
        cout<<endl;
        re.push_back(Process(RoundRobin::runningProcesses[i].id,

                             RoundRobin::runningProcesses[i].end-RoundRobin::runningProcesses[i].start,
                     RoundRobin::queueOfAllProcesses[RoundRobin::runningProcesses[i].id-1].arrivalTime,
                             0,
                             RoundRobin::runningProcesses[i].start,
                             RoundRobin::runningProcesses[i].end));
    }


   RoundRobin::findAvgAndWait();
    //printf("\n\nTurnAround Time:%f \n", avgtt / n);
   w_time = RoundRobin::avgWait;


    return re;

}

