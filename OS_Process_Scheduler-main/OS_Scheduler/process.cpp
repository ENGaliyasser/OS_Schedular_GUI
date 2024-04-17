#include "process.h"

Process::Process(int id, int burst_time, int arrival_time, int priority , int s ,int e) :process_ID(id),
    process_burst_time(burst_time),
    process_arrival_time(arrival_time),
    process_priority(priority)
  {
      start_time = s;
      end_time = e;
      rt = 0;
      wt = 0;
      tt = 0;
      completed = 0;
  }
int Process::get_process_burst_time()const{
    return process_burst_time;
}
int Process::get_process_arrival_time()const{
    return process_arrival_time;
}
int Process::get_process_priority()const{
    return process_priority;
}
int Process::get_process_Id()const{
    return process_ID;
}
int Process::get_start_time(){
    return start_time;
}
int Process::get_end_time(){
    return end_time;
}

void Process::set_process_burst_time(int b){
    this->process_burst_time=b;
}
void Process::set_process_arrival_time(int a){
    this->process_arrival_time=a;
}
void Process::set_process_priority(int p){
    this->process_priority=p;
}

void Process::set_process_Id(int i){
    this->process_ID=i;
}
void Process::set_start_time(int s){
    this->start_time=s;
}
void Process::set_end_time(int e){
    this->end_time=e;
}

