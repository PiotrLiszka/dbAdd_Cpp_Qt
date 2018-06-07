#include "scooter.h"

Scooter::Scooter(QString brnd, QString mdl, QString clr, QDate yr, int rng) : Vehicle(brnd,mdl,clr,yr)
{
    range = rng;
}

QString Scooter::createDetailsQuery(int id)
{
    return "INSERT INTO scooter (range,vid) VALUES ('" + QString::number(range) + "','"+QString::number(id)+"')";
}

