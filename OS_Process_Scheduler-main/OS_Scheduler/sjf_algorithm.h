#ifndef SJF_ALGORITHM_H
#define SJF_ALGORITHM_H

#include "process.h"
#include <QVector>
class sjf_algorithm
{
public:
    sjf_algorithm();
    static QVector<Process> sjf_non_preemptive(QVector<Process>v,float &avg_waiting);
};

#endif // SJF_ALGORITHM_H
