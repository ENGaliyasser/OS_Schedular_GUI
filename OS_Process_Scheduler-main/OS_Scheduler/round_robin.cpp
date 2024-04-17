/**********************************************/
/* @author : Mohamed Abdel Hamid              */
/**********************************************/
#include <iostream>
#include "round_robin.h"
using namespace std;

/****** Externed vector from mainwindow used for live ganttchart ***/
extern QVector<int> inProgress;

/**************** Processes Class APIs implementation **************/
/* Description : A Class used to define a proccess data needed     */
/* Process Constructor */
Processes::Processes(int arrivalTime, int burstTime) {
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->nextBurstTime = burstTime;
    noOfProcess++;
}

void Processes::executeProcess() {
    nextBurstTime--;
}
int Processes::getNoOfProcess() {
    return noOfProcess;
}
/************* End of Processes Class APIs implementation *********/

/*************** GanttChart Class APIs implementation *************/
/* Description :
 * A Class used to define the needed data to draw
 * the static ganttchart
*/

/* Process Constructor */
GanttChart::GanttChart(int id,int start){
    this->id = id;
    this->start = start;
}
void GanttChart::setEnd(int end){
    this->end = end;
    n++;
}
/*********** End of GanttChart Class APIs implementation *********/

/************** RoundRobin Class APIs implementation *************/
/* Description :
 * A Class used to define the needed data and functions for the
 * the ROUNDROBIN Alogorithm
*/

void RoundRobin::addProcess(int arrivalTime, int burstTime) {
    Processes p(arrivalTime, burstTime);
    queueOfAllProcesses.push_back(p);
    complete.push_back(0);
    readyQueue.push_back(0);
    firstExecution.push_back(1);
}

/* Used for testing */
void RoundRobin::updateData() {
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

/* Enqueue a process in the ready queue */
void RoundRobin::enqueueProcess(){
    int i = 0;
    for (i = 0; (i < Processes::getNoOfProcess() - 1) && (readyQueue[i + 1] != 0); i++)
    {
        int temp = readyQueue[i];
        readyQueue[i] = readyQueue[i + 1];
        readyQueue[i + 1] = temp;
    }
    firstExecution[i - 1] = 0;
}

void RoundRobin::updateQueue()
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

void RoundRobin::checkNewArrival(){
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

bool RoundRobin::isEndOfSched() {
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

/* SCHEDULER */
void RoundRobin::startScheduling() {
    timer = queueOfAllProcesses[0].arrivalTime;
    for(int i=0;i<timer;i++){
        inProgress.push_back(0);
    }
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
                RoundRobin::updateData();
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
                checkNewArrival();
            }

            // Enqueue the process after preemption
            enqueueProcess();

        }
    }
    cout<<endl<<"Finish"<<endl;
}

void RoundRobin::findAvgAndWait() {
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
}
/************ End of RoundRobin Class APIs implementation *************/
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

QVector<Process> round_robin::RR(QVector<Process> p, int tq,float &w_time) {

    QVector< Process > re;
    RoundRobin::readyQueue.clear();
    RoundRobin::runningProcesses.clear();
    RoundRobin::firstExecution.clear();
    RoundRobin::complete.clear();
    RoundRobin::queueOfAllProcesses.clear();
    Processes::noOfProcess=0;
    RoundRobin::quantum = 0;
    RoundRobin::timer = 0;
    RoundRobin::lastArrivedProcessIndex = 0;
    RoundRobin::avgWait = 0;
    RoundRobin::avgTurn = 0;
    GanttChart::n = 0;
    RoundRobin::RunningProcess = 0;
    for(int i=0; i<p.size();i++){

        RoundRobin::addProcess(p[i].get_process_arrival_time(), p[i].get_process_burst_time());
    }

    RoundRobin::quantum = tq;

    RoundRobin::startScheduling();


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
