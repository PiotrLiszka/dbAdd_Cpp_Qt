#ifndef VEHICLE_H
#define VEHICLE_H

#include "ivehicle.h"
#include <QDate>

class Vehicle : public IVehicle
{
protected:
    QString brand;
    QString model;
    QString color;
    QDate year;
public:
    QString createBaseQuery();
    virtual QString createDetailsQuery(int id) = 0;
    Vehicle(QString brnd, QString mdl, QString clr, QDate yr);
    virtual ~Vehicle();
};

#endif // VEHICLE_H
