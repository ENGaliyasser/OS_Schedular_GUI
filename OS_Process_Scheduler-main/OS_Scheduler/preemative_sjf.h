#ifndef PREEMATIVE_SJF_H
#define PREEMATIVE_SJF_H

#include <bits/stdc++.h>
#include "vector"
#include <chrono>
#include <thread>
#include <mutex>
#include <list>
#include "process.h"
#include <QVector>

using namespace std;
using namespace chrono;
extern int globaldraw;
extern QVector<int> CurrentProcess;
struct Pro {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
    int Remaning_Time;
    int waitingTime;
    int turn_around_time;
};
extern vector<Pro> proc; // Declare proc as extern
extern int totalTime; // Declare totalTime as extern



typedef struct {
    unsigned int process; //Process IDs start from 1 (Process ID 0 indicated idle section)
    unsigned int start;
    unsigned int end;
} GanntChartSection;

typedef list<GanntChartSection> GanntChart; //GanntChart is a vector of GanntChartSections

extern GanntChart GanttChart;


void findWaitingTime( );
void findTurnAroundTime();
QVector<Process> findavgTime(QVector<Process>v, float& avg_waiting);

#endif // PREEMATIVE_SJF_H
