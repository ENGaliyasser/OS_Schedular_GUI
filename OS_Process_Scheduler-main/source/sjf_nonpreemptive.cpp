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

ostream& operator<<(ostream& os, const Process& p)
{
    os << " " << p.get_process_Id() << ": " << p.get_start_time() << "  -  " << p.get_end_time();
    // os << p.get_process_arrival_time() << " - " << p.get_process_burst_time();
    return os;
}


vector<Process> sjf_non(vector<Process>v, float& avg_waiting) {
    int n = v.size();
    vector<bool>taken;
    for (int i = 0; i < n; i++) {
        taken.push_back(false);
    }
    vector<Process>v2;
    vector<Process>v3;
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

            v2.erase(v2.begin() + min_burst_index);

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
    vector<Process> ans = sjf_non(v, avr_waiting);
    cout << "id: " << "st - " << "end" << endl;
    for (auto&& i : ans)
    {
        cout << i << endl;
    }
    cout << "avr_wait: " << avr_waiting << endl;

    return 0;
}