#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

class Bike : public Vehicle
{
protected:
    QString type;
public:
    Bike(QString brnd, QString mdl, QString clr,QDate yr,QString tp);
    QString createDetailsQuery(int id);

};

#endif // BIKE_H
