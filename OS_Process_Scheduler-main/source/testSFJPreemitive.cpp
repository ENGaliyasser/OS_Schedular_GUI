#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process
{
private:
    int process_ID;
    int process_burst_time;
    int process_arrival_time;
    int process_priority;
    int start_time;
    int end_time;

public:
    Process(int id, int burst_time, int arrival_time, int priority);
    int get_process_Id() const;
    int get_process_burst_time() const;
    int get_process_arrival_time() const;
    int get_process_priority() const;
    int get_start_time() const;
    int get_end_time() const;

    void set_process_Id(int);
    void set_process_burst_time(int);
    void set_process_arrival_time(int);
    void set_process_priority(int);
    void set_start_time(int);
    void set_end_time(int);
};

Process::Process(int id, int burst_time, int arrival_time, int priority) : process_ID(id), process_burst_time(burst_time), process_arrival_time(arrival_time), process_priority(priority)
{
}
int Process::get_process_burst_time() const
{
    return process_burst_time;
}
int Process::get_process_arrival_time() const
{
    return process_arrival_time;
}
int Process::get_process_priority() const
{
    return process_priority;
}
int Process::get_process_Id() const
{
    return process_ID;
}
int Process::get_start_time() const
{
    return start_time;
}
int Process::get_end_time() const
{
    return end_time;
}

void Process::set_process_burst_time(int b)
{
    this->process_burst_time = b;
}
void Process::set_process_arrival_time(int a)
{
    this->process_arrival_time = a;
}
void Process::set_process_priority(int p)
{
    this->process_priority = p;
}

void Process::set_process_Id(int i)
{
    this->process_ID = i;
}
void Process::set_start_time(int s)
{
    this->start_time = s;
}
void Process::set_end_time(int e)
{
    this->end_time = e;
}

ostream &operator<<(ostream &os, const Process &p)
{
    os <<" "<<p.get_process_Id() << ": " << p.get_start_time() << "  -  " << p.get_end_time();
    // os << p.get_process_arrival_time() << " - " << p.get_process_burst_time();
    return os;
}


vector<Process> SJF(vector<Process> processes, float &avr_wait)
{

    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    int total_waiting_time = 0;
    vector<Process> ordered_processes; // ordered of processes in Gantt chart

    vector<int> remaining_time(n);
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

    // outputs
    avr_wait = (float)total_waiting_time / n;
    return ordered_processes;
}
int main()
{

    vector<Process> v;
    Process temp0(1, 8, 0, 0);
    Process temp1(2, 4, 1, 0);
    Process temp2(3, 9, 2, 0);
    Process temp3(4, 5, 3, 0);
    v.push_back(temp0);
    v.push_back(temp1);
    v.push_back(temp2);
    v.push_back(temp3);
    // sort(v.begin(), v.end(), compare);
    float avr_waiting = 0;
    vector<Process> ans = SJF(v, avr_waiting);
    cout<<"id: "<<"st - "<<"end"<<endl;
    for (auto &&i : ans)
    {
        cout << i << endl;
    }
    cout << "avr_wait: " << avr_waiting << endl;

    return 0;
}
