#include "truck.h"

Truck::Truck(QString brnd, QString mdl, QString clr, QDate yr, QString eng, int cap) : Vehicle(brnd,mdl,clr,yr)
{
    engine = eng;
    capacity = cap;
}

QString Truck::createDetailsQuery(int id)
{
    return "INSERT INTO truck (engine,capacity,vid) VALUES ('" + engine + "','" +QString::number(capacity)+ "','"  +QString::number(id)+  "')";
}
