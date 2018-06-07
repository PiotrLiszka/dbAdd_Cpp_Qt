#ifndef CAR_H
#define CAR_H

#include "vehicle.h"



class Car : public Vehicle
{
private:
    QString engine;
    int noOfDoors;
public:
    Car(QString brnd, QString mdl, QString clr,QDate yr, QString eng, int nr);
    QString createDetailsQuery(int id);
};

#endif // CAR_H
