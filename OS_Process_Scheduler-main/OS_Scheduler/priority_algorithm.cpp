#include "priority_algorithm.h"
extern QVector<int> inProgress;
priority_algorithm::priority_algorithm()
{

}


QVector<Process> priority_algorithm::Priority_nonPreemptive(QVector<Process> processes, float &avg_waiting)
{
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    int total_waiting_time = 0;
    int ali=0;
    int alii=INT_MAX;
    //int arrival =0;
    QVector<bool> is_completed(n, false);
    QVector<Process> ordered_processes; // ordered of processes in Gantt chart

    while (completed != n)
    {
        int idx = -1;
        int mn = 1e9;
        bool no_tasks_arrived = true; // Flag to check if any task has arrived

        for (int i = 0; i < n; i++)
        {
            if ((processes[i].get_process_arrival_time() <= current_time) && !is_completed[i])
            {
                no_tasks_arrived = false; // At least one task has arrived
                if(processes[i].get_process_priority() < mn){
                    mn = processes[i].get_process_priority();
                    idx = i;
                }
            }
            if(processes[i].get_process_priority() == mn) {
                if(processes[i].get_process_arrival_time() < processes[idx].get_process_arrival_time()) {
                    mn = processes[i].get_process_priority();
                    idx = i;
                }
            }
        }

        if (no_tasks_arrived) {
            // Push an idle task and increment time to the next arrival time
            Process idle_task(0, 1, current_time, INT_MAX); // Assuming idle task has priority INT_MAX and burst time 1
            //ordered_processes.push_back(idle_task);
            if(current_time<alii) alii=current_time;
            inProgress.push_back(idle_task.get_process_Id());
            ali++;
            //current_time++;
        }
        else if (idx != -1)
        {
            is_completed[idx] = true;
            completed++;
            if(ali){
            Process idle_task(0, ali, alii, INT_MAX); // Assuming idle task has priority INT_MAX and burst time 1
            ordered_processes.push_back(idle_task);
            ali =0;
            alii=INT_MAX;}
            Process curr_proc = processes[idx];
            for(int i=0;i<curr_proc.get_process_burst_time();i++){
                inProgress.push_back(curr_proc.get_process_Id());
            }
            curr_proc.set_start_time(current_time);
            curr_proc.set_end_time(curr_proc.get_process_burst_time() + current_time);
            ordered_processes.push_back(curr_proc);

            current_time += curr_proc.get_process_burst_time() - 1;
            int wait = curr_proc.get_start_time() - curr_proc.get_process_arrival_time();
            if(wait < 0) wait = 0;
            total_waiting_time += wait;
        }

        // Increment time
        current_time++;
    }

    // outputs
    avg_waiting = (float)total_waiting_time / n;
    return ordered_processes;
}
QVector<Process> priority_algorithm::Priority_preemitive(QVector<Process> processes, float &avg_waiting)
{

    int n = processes.size();

    int current_time = 0;
    int completed = 0;
    int total_waiting_time = 0;
    QVector<Process> ordered_processes; // ordered of processes in Gantt chart
    int ali=0;
    int alii=INT_MAX;
    QVector<int> burst_remaining(n,0);
    for (int i =0;i<n;i++) {
        int bt = processes[i].get_process_burst_time();
        burst_remaining[i] = bt;
        if(bt == 0) completed++;
    }
    while (completed != n)
    {
        int idx = -1;
        int mn = 1e9;
        bool no_tasks_arrived = true;
        for (int i = 0; i < n; i++)
        {
            if ((processes[i].get_process_arrival_time() <= current_time) && burst_remaining[i] > 0)
            {
                no_tasks_arrived = false;
                if(processes[i].get_process_priority() < mn){
                    mn = processes[i].get_process_priority();
                    idx = i;

                }
            }
            if(processes[i].get_process_priority() == mn && burst_remaining[i] > 0) {
                if(processes[i].get_process_arrival_time() < processes[idx].get_process_arrival_time()) {
                    mn = processes[i].get_process_priority();
                    idx = i;
                }
            }
        }

        if (no_tasks_arrived) {
            // Push an idle task and increment time to the next arrival time
            Process idle_task(0, 1, current_time, INT_MAX,current_time,current_time+1); // Assuming idle task has priority INT_MAX and burst time 1
            //ordered_processes.push_back(idle_task);
            if(current_time<alii) alii=current_time;
            inProgress.push_back(idle_task.get_process_Id());
            ali++;
            //current_time++;
        }
        else if (idx != -1)
        {
            Process curr_proc = processes[idx];
            if(ali){
            Process idle_task(0, ali, alii, INT_MAX,alii,alii+ali); // Assuming idle task has priority INT_MAX and burst time 1
            ordered_processes.push_back(idle_task);
            ali =0;
            alii=INT_MAX;
            }
            // decrementing the remaining time
            burst_remaining[idx]--;
            if (ordered_processes.empty() || curr_proc.get_process_Id() != ordered_processes.back().get_process_Id())
            {
                curr_proc.set_start_time(current_time);
                ordered_processes.push_back(curr_proc);
            }
            ordered_processes.back().set_end_time(current_time + 1);

            // If a process gets completely
            if (burst_remaining[idx] == 0){
                int finish_time = current_time + 1;

                int wait = finish_time - curr_proc.get_process_arrival_time() - curr_proc.get_process_burst_time();
                if (wait < 0)
                    wait = 0;

                total_waiting_time += wait;
                completed++;
            }

            inProgress.push_back(curr_proc.get_process_Id());

        }

        // Increment time
        current_time++;
    }
    for(int i=0;i<ordered_processes.size();i++){
        ordered_processes[i].set_process_burst_time(ordered_processes[i].get_end_time()-ordered_processes[i].get_start_time());
    }

    avg_waiting = (float)total_waiting_time / n;
    return ordered_processes;
}
