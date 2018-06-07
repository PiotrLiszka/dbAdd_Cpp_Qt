#ifndef SCOOTER_H
#define SCOOTER_H

#include "vehicle.h"

class Scooter : public Vehicle
{
protected:
    int range;
public:
    Scooter(QString brnd, QString mdl, QString clr,QDate yr,int rng);
//    QString dbAdd1();
    QString createDetailsQuery(int id);
};

#endif // SCOOTER_H
