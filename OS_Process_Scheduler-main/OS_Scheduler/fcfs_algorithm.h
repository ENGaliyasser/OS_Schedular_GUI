#ifndef FCFS_ALGORITHM_H
#define FCFS_ALGORITHM_H
#include "process.h"
#include <QVector>
class FCFS_Algorithm
{
public:
    FCFS_Algorithm();
    static QVector<Process>  fcfs(QVector<Process>v,float &avg_waiting);
};

#endif // FCFS_ALGORITHM_H
