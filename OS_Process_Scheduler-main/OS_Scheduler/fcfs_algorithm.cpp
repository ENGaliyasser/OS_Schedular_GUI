#include "fcfs_algorithm.h"


/*************************************************************
*
* fcfs - implementation of fcfs algorithm for processes
*
* @Processes:   vector of processes passes to function
* @avg_waiting: to calculate avg waiting time for processes
*
* Return:       vector of processes after fcfs implementation
*
****************************************************************/


QVector<Process>  FCFS_Algorithm::fcfs(QVector<Process>processes,float &avg_waiting){
    avg_waiting = 0;
    unsigned int n = processes.size(); // Number of processes
    unsigned int min_arriv; // Minimum arrival time
    unsigned int current_time = 0; // Time on the Gantt chart
    QVector<Process> scheduledProcesses; // Vector to store scheduled processes
    vector<int> waitingTime(n, 0); // Array to store waiting time for each process
    vector<int> turnaroundTime(n, 0); // Array to store turnaround time for each process

    // Sort processes according to arrival times
    QVector<Process> p = processes; // Copy of processes vector to operate on
    for (unsigned int i = 0; i < n - 1; i++) {
        min_arriv = i;
        for (unsigned int j = i + 1; j < n; j++) {
            if (p[j].get_process_arrival_time() < p[min_arriv].get_process_arrival_time()) {
                min_arriv = j;
            }
        }
        swap(p[i], p[min_arriv]); // Use std::swap to swap Process objects
    }

    // Schedule processes
    for (unsigned int i = 0; i < n; i++) {
        // Handle idle time between processes
        if (current_time < p[i].get_process_arrival_time()) {
            // Idle section
            //Process(int id,int burst_time,int arrival_time,int priority,int s=0 ,int e=0);
            Process idle(0, p[i].get_process_arrival_time() - current_time, current_time,0,0,0 );
            idle.set_start_time(current_time);
            idle.set_end_time(idle.get_process_arrival_time()+idle.get_process_burst_time());

            for(int i=0;i<idle.get_process_burst_time();i++){
                inProgress.push_back(idle.get_process_Id());
            }
            //inProgress.push_back(idle.get_process_Id());
            scheduledProcesses.push_back(idle);

            current_time = p[i].get_process_arrival_time();
        }

        // Calculate waiting time
        waitingTime[i] = current_time - p[i].get_process_arrival_time();
        if (waitingTime[i] < 0)
            waitingTime[i] = 0;


        // Add the process to the scheduled list
        Process scheduledProcess = p[i];
        scheduledProcess.set_start_time(current_time);
        scheduledProcess.set_process_arrival_time(current_time);
        scheduledProcess.set_end_time(scheduledProcess.get_process_arrival_time()+scheduledProcess.get_process_burst_time());

        for(int i=0;i<scheduledProcess.get_process_burst_time();i++){
            inProgress.push_back(scheduledProcess.get_process_Id());
        }
        //inProgress.push_back(scheduledProcess.get_process_Id());
        scheduledProcesses.push_back(scheduledProcess);

        // Update current time
        current_time += p[i].get_process_burst_time();

        // Calculate turnaround time
        turnaroundTime[i] = current_time - p[i].get_process_arrival_time();

    }


    // Calculate total waiting time
    int total_waiting_time = 0;
    for (unsigned int i = 0; i < n; ++i) {
        total_waiting_time += waitingTime[i];
    }

    // Calculate average waiting time
    avg_waiting = static_cast<float>(total_waiting_time) / n;

    // Display waiting time and turnaround time

    cout << "Waiting Time:\n";
    for (unsigned int i = 0; i < n; ++i) {
        cout << "Process " << p[i].get_process_Id() << ": " << waitingTime[i] << " seconds" << endl;
        //avg_waiting =  (avg_waiting + static_cast<float>(waitingTime[i]) ) / n ;

    }

    cout << "\nTurnaround Time:\n";
    for (unsigned int i = 0; i < n; ++i) {
        cout << "Process " << p[i].get_process_Id() << ": " << turnaroundTime[i] << " seconds" << endl;
    }

    return scheduledProcesses;
}
