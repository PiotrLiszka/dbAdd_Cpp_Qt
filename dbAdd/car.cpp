#include "car.h"

Car::Car(QString brnd, QString mdl, QString clr, QDate yr, QString eng, int nr) : Vehicle(brnd,mdl,clr,yr)
{
    engine = eng;
    noOfDoors = nr;
}

QString Car::createDetailsQuery(int id)
{
    return "INSERT INTO car (engine,doors,vid) VALUES ('" + engine + "','" +QString::number(noOfDoors)+ "','"  +QString::number(id)+  "')";
}
