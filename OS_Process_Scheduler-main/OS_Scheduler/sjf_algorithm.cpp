#include "sjf_algorithm.h"

sjf_algorithm::sjf_algorithm()
{

}


QVector<Process> sjf_algorithm::sjf_non_preemptive (QVector<Process>v, float& avg_waiting) {
    int n = v.size();
    QVector<bool>taken;
    for (int i = 0; i < n; i++) {
        taken.push_back(false);
    }
    QVector<Process>v2;
    QVector<Process>v3;
    int curr_time = 0;
    bool x = true;
    while (x) {
        for (int i = 0; i < n; i++) {
            if (v[i].get_process_arrival_time() <= curr_time && taken[i] == false) {
                v2.push_back(v[i]);
                taken[i] = true;
            }
        }
        int min_burst_index = 0;
        for (int i = 1; i < v2.size(); i++) {
            if (v2[i].get_process_burst_time() < v2[min_burst_index].get_process_burst_time()) {
                min_burst_index = i;
            }
        }
        if (v3.empty()) {
            v3.push_back(v2[min_burst_index]);
            v3[0].set_start_time(0);
            v3[0].set_end_time(v3[0].get_process_burst_time());
            curr_time = v3[0].get_process_burst_time();
            v2.erase(v2.begin() + min_burst_index);
        }
        else {
            int v3_size = v3.size();
            v3.push_back(v2[min_burst_index]);
            v3[v3_size].set_start_time(v3[v3_size - 1].get_end_time());
            v3[v3_size].set_end_time(v3[v3_size - 1].get_end_time() + v3[v3_size].get_process_burst_time());
            curr_time += v3[v3_size].get_process_burst_time();

            v2.erase(v2.begin()+ min_burst_index);

        }
        if (v3.size() == v.size()) {
            x = false;
        }

    }
    int waiting_time = 0;
    for (int i = 0; i < v3.size(); i++) {
        waiting_time += v3[i].get_start_time() - v3[i].get_process_arrival_time();
    }

    avg_waiting = (waiting_time * 1.0) / n;
    return v3;

}


QVector<Process> sjf_algorithm::sjf_preemptive(QVector<Process> processes, float &avr_wait)
{

    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    int total_waiting_time = 0;
    QVector<Process> ordered_processes; // ordered of processes in Gantt chart

    QVector<int> remaining_time(n);
    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = processes[i].get_process_burst_time();
        // if process has no burst time
        if (remaining_time[i] <= 0)
            completed++;
    }

    int shortest_process = 1e9; // track the process that has shortest burst time at that point
    while (completed != n)
    {
        int indx = -1; // save indx of shortest process

        // get indx of shortest process
        for (int i = 0; i < n; i++)
        {
            if ((processes[i].get_process_arrival_time() <= current_time) && (remaining_time[i] <= shortest_process) && (remaining_time[i] > 0))
            {
                shortest_process = remaining_time[i];
                indx = i;
            }
        }

        if (indx != -1)
        {
            Process curr_proc = processes[indx];

            // decrementing the remaining time
            remaining_time[indx]--;
            shortest_process = remaining_time[indx];

            if (ordered_processes.empty() || curr_proc.get_process_Id() != ordered_processes.back().get_process_Id())
            {
                curr_proc.set_start_time(current_time);
                ordered_processes.push_back(curr_proc);
            }
            ordered_processes.back().set_end_time(current_time + 1);

            // If a process gets completely
            if (remaining_time[indx] == 0)
            {
                int finish_time = current_time + 1;

                int wait = finish_time - curr_proc.get_process_arrival_time() - curr_proc.get_process_burst_time();
                if (wait < 0)
                    wait = 0;

                total_waiting_time += wait;
                completed++;
            }
            if (shortest_process == 0)
                shortest_process = 1e9;
        }

        // Increment time
        current_time++;
    }
    for(int i=0;i<ordered_processes.size();i++){
            ordered_processes[i].set_process_burst_time(ordered_processes[i].get_end_time()-ordered_processes[i].get_start_time());
    }

    // outputs
    avr_wait = (float)total_waiting_time / n;
    return ordered_processes;
}
