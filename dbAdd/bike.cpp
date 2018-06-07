#include "bike.h"

Bike::Bike(QString brnd, QString mdl, QString clr, QDate yr, QString tp)  : Vehicle(brnd,mdl,clr,yr)
{
    type = tp;
}



QString Bike::createDetailsQuery(int id)
{
    return "INSERT INTO bike (type,vid) VALUES ('" + type + "','"+QString::number(id)+"')";
}
