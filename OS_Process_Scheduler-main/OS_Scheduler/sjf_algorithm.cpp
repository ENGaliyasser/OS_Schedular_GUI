#include "sjf_algorithm.h"

#include <algorithm> // for std::sort
#include <climits>   // for INT_MAX

extern QVector<int> inProgress;

// Function to calculate average waiting time
float calculate_avg_waiting(const QVector<Process>& execution_order) {
    int total_waiting_time = 0;
    for (const Process& process : execution_order) {
        total_waiting_time += process.get_start_time() - process.get_process_arrival_time();
    }
    return static_cast<float>(total_waiting_time) / execution_order.size();
}


// SJF non-preemptive scheduling algorithm
QVector<Process> sjf_algorithm::sjf_non_preemptive(QVector<Process> processes, float& avg_waiting) {
    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.get_process_arrival_time() < b.get_process_arrival_time();
    });

    QVector<Process> execution_order; // Store the order of execution
    int curr_time = 0; // Current time

    // Push "idle" into inProgress until the first process starts
    if (!processes.isEmpty() && processes[0].get_process_arrival_time() > 0) {
        for (int i = 0; i < processes[0].get_process_arrival_time(); ++i) {
            inProgress.push_back(0); // Assuming 0 represents "idle"
        }
        curr_time = processes[0].get_process_arrival_time();
    }

    while (!processes.isEmpty()) {
        int shortest_index = -1;
        int shortest_burst = INT_MAX;

        // Find the process with the shortest burst time among arrived processes
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].get_process_arrival_time() <= curr_time) {
                if (processes[i].get_process_burst_time() < shortest_burst) {
                    shortest_burst = processes[i].get_process_burst_time();
                    shortest_index = i;
                }
            } else {
                break; // No need to continue, as processes are sorted by arrival time
            }
        }

        if (shortest_index != -1) { // If a process is found
            Process shortest_process = processes.takeAt(shortest_index); // Remove process from queue
            shortest_process.set_start_time(curr_time);
            shortest_process.set_end_time(curr_time + shortest_process.get_process_burst_time());
            execution_order.push_back(shortest_process);

            // Update inProgress with the ID of the process being executed
            for (int i = 0; i < shortest_process.get_process_burst_time(); i++) {
                inProgress.push_back(shortest_process.get_process_Id());
            }

            curr_time += shortest_process.get_process_burst_time();
        } else {
            // If no process is found at current time, move to the next arrival time
            curr_time = processes[0].get_process_arrival_time();
        }
    }

    // Calculate average waiting time
    avg_waiting = calculate_avg_waiting(execution_order);

    // Return the execution order
    return execution_order;
}
