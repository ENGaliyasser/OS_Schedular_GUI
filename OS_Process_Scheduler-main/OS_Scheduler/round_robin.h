#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H
#include "process.h"
#include <QVector>
#include <vector>

/* This is used with the interface with gui  */
class round_robin
{
public:
    static QVector<Process> RR(QVector<Process> p, int tq,float &w_time) ;
};

class Processes {
public:
    static int noOfProcess;
    int arrivalTime = 0;
    int burstTime = 0;
    int nextBurstTime = 0;
    int waiting = 0;
    int turnaround = 0;

    Processes(int arrivalTime, int burstTime);
    void executeProcess();
    static int getNoOfProcess();
};

class GanttChart{
public:
    static int n;
    int id;
    int start;
    int end;

    GanttChart(int id,int start);
    void setEnd(int end);
};

class RoundRobin {
public:
    static int quantum;
    static int timer;
    static int lastArrivedProcessIndex;
    static int avgWait;
    static int avgTurn;
    static int RunningProcess;
    static std::vector<GanttChart> runningProcesses;
    static std::vector<Processes> queueOfAllProcesses;
    static std::vector<bool> firstExecution;
    static std::vector<int> readyQueue;
    static std::vector<bool> complete;

    static void addProcess(int arrivalTime, int burstTime);
    static void updateData();
    static void enqueueProcess();
    static void updateQueue();
    static void checkNewArrival();
    static bool isEndOfSched();
    static void startScheduling();
    static void findAvgAndWait();
};



#endif // ROUND_ROBIN_H
