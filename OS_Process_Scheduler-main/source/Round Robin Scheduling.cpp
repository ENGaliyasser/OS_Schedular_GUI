#include<stdio.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

class Process
{
public:
    int process_ID;
    int process_burst_time;
    int process_arrival_time;
    int process_priority;
    int start_time;
    int end_time;
    int wt, tt, rt;
    int completed;

public:
    Process(int id, int burst_time, int arrival_time, int priority, int s=0, int e=0) :process_ID(id), process_burst_time(burst_time), process_arrival_time(arrival_time), process_priority(priority)
    {
        start_time = s;
        end_time = e;
        rt = 0;
        wt = 0;
        tt = 0;
        completed = 0;
    }
    int get_process_burst_time()const {
        return process_burst_time;
    }
    int get_process_arrival_time()const {
        return process_arrival_time;
    }
    int get_process_priority()const {
        return process_priority;
    }
    int get_process_Id()const {
        return process_ID;
    }
    int get_start_time() {
        return start_time;
    }
    int get_end_time() {
        return end_time;
    }
    int get_rt() {
        return rt;
    }
    int get_tt() {
        return tt;
    }
    int get_wt() {
        return wt;
    }
    int get_completed() {
        return completed;
    }

    void set_process_burst_time(int b) {
        this->process_burst_time = b;
    }
    void set_process_arrival_time(int a) {
        this->process_arrival_time = a;
    }
    void set_process_priority(int p) {
        this->process_priority = p;
    }

    void set_process_Id(int i) {
        this->process_ID = i;
    }
    void set_end_time(int s) {
        this->end_time = s;
    }
    void set_start_time(int s) {
        this->start_time = s;
    }
    void set_rt(int e) {
        this->rt = e;
    }
    void set_wt(int e) {
        this->wt = e;
    }
    void set_tt(int e) {
        this->tt = e;
    }
    void set_completed(int e) {
        this->completed = e;
    }
};

int n;
vector<int> q(100); //queue
int front = -1, rear = -1;

void enqueue(int i)
{
    if (rear == 100)
        printf("overflow");
    rear++;
    q[rear] = i;
    if (front == -1)
        front = 0;
}

int dequeue()
{
    if (front == -1)
        printf("underflow");
    int temp = q[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}

int isInQueue(int i)
{
    int k;
    for (k = 0; k <= rear; k++)
    {
        if (q[k] == i)
            return 1;
    }
    return 0;
}

void sortByArrival(vector<Process> p)
{
    Process temp(0, 0, 0, 0, 0, 0);

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].process_arrival_time > p[j].process_arrival_time)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

vector<Process> RR(vector<Process> p, int tq, float& w_time) {
    int count = 0;
    vector< Process > re;

    int n = p.size();

    int i, j, time = 0, sum_bt = 0;
    float avgwt = 0;
    float avgtt = 0;

    vector<int> rt(n);
    vector<int> completed(n);
    vector<int> tt(n);
    vector<int> wt(n);

    int r = 0;
    int st = 0;



    for (i = 0; i < n; i++)
    {

        rt[i] = p[i].get_process_burst_time();
        completed[i] = 0;

        sum_bt += p[i].get_process_burst_time();
    }

    sortByArrival(p);
    enqueue(0);

    for (time = p[0].get_process_arrival_time(); time < sum_bt;)
    {
        i = dequeue();
        if (rt[i] <= tq)
        {
            time += rt[i];
            r = rt[i];
            rt[i] = 0;
            completed[i] = 1;

            re.push_back(Process(p[i].get_process_Id(), r, 0, 0, st, st + r));
            st = st + r;

            count++;
            wt[i] = time - p[i].get_process_arrival_time() - p[i].get_process_burst_time();
            tt[i] = time - p[i].get_process_arrival_time();
            for (j = 0; j < n; j++)
            {
                if (p[j].get_process_arrival_time() <= time && completed[j] != 1 && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
        }
        else
        {

            time += tq;
            rt[i] -= tq;

            re.push_back(Process(p[i].get_process_Id(), tq, 0, 0, st, st + tq));
            st = st + tq;



            for (j = 0; j < n; j++)
            {
                if (p[j].get_process_arrival_time() <= time && completed[j] != 1 && i != j && isInQueue(j) != 1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);
        }
    }

    for (i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtt += tt[i];

    }
    //printf("\n\nTurnAround Time:%f \n", avgtt / n);

    w_time = avgwt / n;

    return re;

}

int main()
{
    vector<Process> A;
    vector<Process> B;
    Process x(44, 4, 0, 0);
    Process y(11, 5, 0, 0);
    Process z(99, 3, 2, 0);
    Process m(4, 8, 2, 0);
    Process n(1, 6, 8, 0);

    A.push_back(x);
    A.push_back(y);
    A.push_back(z);
    A.push_back(m);
    A.push_back(n);

    float cc;
    B = RR(A, 2, cc);

    for (int i = 0; i < B.size(); i++) {
        cout << B[i].get_process_Id() << " " << B[i].get_start_time() << " " << B[i].get_end_time() << endl;
    }
    cout << "avg waiting time " << cc << endl;
}