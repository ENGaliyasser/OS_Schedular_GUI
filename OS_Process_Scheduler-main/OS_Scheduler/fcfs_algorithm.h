#ifndef FCFS_ALGORITHM_H
#define FCFS_ALGORITHM_H
#include "process.h"
#include <QVector>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*************************************
 *
 * Auther:      Ahmed Gamal Helmy
 *
 * file name:   fcfs_algorithm.h
 *
 * **********************************/

extern QVector<int> inProgress;
class FCFS_Algorithm
{
public:
    FCFS_Algorithm();
    static QVector<Process>  fcfs(QVector<Process>processes,float &avg_waiting);
};

#endif // FCFS_ALGORITHM_H

