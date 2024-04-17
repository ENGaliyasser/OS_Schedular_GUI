#include "fcfs_algorithm.h"

FCFS_Algorithm::FCFS_Algorithm()
{

}

struct compare_process
{
    inline bool operator() (const Process& lhs,const  Process& rhs)
    {
        return (lhs.get_process_arrival_time() < rhs.get_process_arrival_time());
    }
};

QVector<Process>  FCFS_Algorithm::fcfs(QVector<Process>v,float &avg_waiting){
    std::stable_sort(v.begin(),v.end(),compare_process());
    int n=v.size();
    v[0].set_start_time(v[0].get_process_arrival_time());
    v[0].set_end_time(v[0].get_process_arrival_time()+v[0].get_process_burst_time());

    int waiting_time=0;
    for(int i=1;i<n;i++){
        v[i].set_start_time(v[i-1].get_end_time());
        v[i].set_end_time(v[i].get_start_time()+v[i].get_process_burst_time());
        waiting_time+=v[i].get_start_time()-v[i].get_process_arrival_time();
    }

    avg_waiting=(waiting_time*1.0)/n;
    return v;
}
