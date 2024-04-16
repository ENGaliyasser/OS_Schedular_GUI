#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H
#include "process.h"
#include <QVector>

class round_robin
{
public:
    round_robin();
    static QVector<Process> RR(QVector<Process> p, int tq,float &w_time) ;
};



#endif // ROUND_ROBIN_H
