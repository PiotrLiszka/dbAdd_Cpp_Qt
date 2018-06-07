#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
protected:
    QString engine;
    int capacity;
public:
    Truck(QString brnd, QString mdl, QString clr,QDate yr, QString eng, int cap);
    QString createDetailsQuery(int id);
};

#endif // TRUCK_H
