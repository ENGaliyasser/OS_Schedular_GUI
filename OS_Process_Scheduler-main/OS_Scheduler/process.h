#ifndef PROCESS_H
#define PROCESS_H

//#include <QVector>
class Process
{
private:
    int process_ID;
    int process_burst_time;
    int process_arrival_time;
    int process_priority;
    int start_time;
    int end_time;
    int wt, tt, rt;//used in RR(mohamed gad)
    int completed;//used in RR(mohamed gad)
public:
    Process(int id,int burst_time,int arrival_time,int priority,int s=0 ,int e=0);
    int get_process_Id()const;
    int get_process_burst_time()const;
    int get_process_arrival_time()const;
    int get_process_priority()const;
    int get_start_time()const;
    int get_end_time();

    void set_process_Id(int);
    void set_process_burst_time(int );
    void set_process_arrival_time(int );
    void set_process_priority(int);
    void set_start_time(int);
    void set_end_time(int);
};


#endif // PROCESS_H
