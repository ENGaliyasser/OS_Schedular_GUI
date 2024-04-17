#ifndef PRIORITY_ALGORITHM_H
#define PRIORITY_ALGORITHM_H
#include "process.h"
#include <QVector>

class priority_algorithm
{
public:
    priority_algorithm();
    static QVector<Process> Priority_nonPreemptive(QVector<Process> processes, float &avg_waiting);
    static QVector<Process> Priority_preemitive(QVector<Process> processes, float &avg_waiting);
};

#endif // PRIORITY_ALGORITHM_H
