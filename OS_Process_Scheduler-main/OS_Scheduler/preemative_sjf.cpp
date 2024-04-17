#include "preemative_sjf.h"
#include "mainwindow.h"

vector<Pro> proc; // Define proc
int totalTime = 0; // Define totalTime
GanntChart GanttChart;
int globaldraw;

QVector<int> CurrentProcess;
extern QVector<int> inProgress;
void findWaitingTime( )
{
    //vector<int> Remaning_Time(n);
    //vector<int> Comparing_Time(n);
    totalTime = 0;
    GanntChartSection currentsection;
    for (int i = 0; i < proc.size(); i++){
        totalTime += proc[i].bt;
    }

    // Copy the burst time into Remaning_Time[] at the beginning
    for (int i = 0; i < proc.size(); i++) {
        proc[i].Remaning_Time = proc[i].bt;
        //Comparing_Time[i] = proc[i].bt;
    }
    int complete = 0, currentTime = 0, min_remaining_time = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    //GanttChart.clear();
    // Process until all processes get completed
    while (complete != proc.size()) {
        // Find process with minimum remaining time among the processes that arrive until the current time
        for (int j = 0; j < proc.size(); j++) {
            if ((proc[j].art <= currentTime) &&
                (proc[j].Remaning_Time < min_remaining_time) && proc[j].Remaning_Time > 0) {
                min_remaining_time = proc[j].Remaning_Time;
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            currentTime++;
            continue;
        }

        // Reduce remaining time by one
        proc[shortest].Remaning_Time--;
        //GanttChart.push_back(proc[shortest].pid);
        cout<<proc[shortest].pid;
        //MainWindow mainwindow;
        // Inside the loop where you want to call draw(int)
        //mainwindow.draw(proc[shortest].pid);
        globaldraw=proc[shortest].pid;
        inProgress.push_back(proc[shortest].pid);
        cout<<endl;
        // Update minimum
        min_remaining_time = proc[shortest].Remaning_Time;
        if (min_remaining_time == 0)
            min_remaining_time = INT_MAX;

        // If a process gets completely executed
        if (proc[shortest].Remaning_Time == 0) {
            // Increment complete
            complete++;
            check = false;

            // Find finish time of the current process
            finish_time = currentTime + 1;

            // Calculate waiting time
            proc[shortest].waitingTime = finish_time - proc[shortest].bt - proc[shortest].art;

            if (proc[shortest].waitingTime < 0)
                proc[shortest].waitingTime = 0;
        }
        // Increment time
        currentTime++;
        cout << endl;
        if (!GanttChart.empty() && GanttChart.back().process == proc[shortest].pid) {
            GanttChart.back().end = currentTime;
        } else {
            GanntChartSection section;
            section.process = proc[shortest].pid;
            section.start = currentTime - 1;
            section.end = currentTime;
            GanttChart.push_back(section);
        }

        cout << endl;
        // Introduce a one-second delay
        //  this_thread::sleep_for(seconds(1));
    }
    cout << endl;

}
// Function to find the waiting time for all processes


// Function to calculate turn around time
void findTurnAroundTime()
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < proc.size(); i++)
        proc[i].turn_around_time = proc[i].bt + proc[i].waitingTime;
}

// Function to calculate average time
QVector<Process> findavgTime(QVector<Process>v, float& avg_waiting)
{
    Pro in_p;
    proc.clear();
    GanttChart.clear();
    for(int i =0 ;i<v.size();i++){
        in_p.pid=v.at(i).get_process_Id();
        in_p.bt=v.at(i).get_process_burst_time();
        in_p.art=v.at(i).get_process_arrival_time();
        proc.push_back(in_p);
    }
    QVector<Process> Draw;
    //vector<int> wt(n);
    //vector<int> tat(n);
    int total_wt = 0,total_tat = 0;

    // Function to find waiting time of all
    // processes

    findWaitingTime();

    // Function to find turn around time for
    // all processes
    findTurnAroundTime();

    // Display processes along with all
    // details
    cout << " P\t\t"
         << "BT\t\t"
         << "WT\t\t"
         << "TAT\t\t\n";

    // Calculate total waiting time and
    // total turnaround time
    for (int i = 0; i < proc.size(); i++) {
        total_wt = total_wt + proc[i].waitingTime;
        total_tat = total_tat + proc[i].turn_around_time;
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t\t " << proc[i].waitingTime
             << "\t\t " << proc[i].turn_around_time << endl;
    }
    avg_waiting = (float)total_wt / (float)(proc.size());
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)(proc.size());
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)(proc.size());
    for (const GanntChartSection& section : GanttChart) {
        unsigned int burst_time = section.end - section.start;
        int arrival_time = section.start;
        Process p(section.process, burst_time, arrival_time, 0,section.start,section.end); // Setting priority to 0, you can change as needed
        Draw.push_back(p);
    }


    return Draw;
}
