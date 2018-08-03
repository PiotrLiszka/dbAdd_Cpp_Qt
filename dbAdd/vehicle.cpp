#include "vehicle.h"

QString brand;
QString model;
QString color;
QDate year;



Vehicle::Vehicle(QString brnd, QString mdl, QString clr, QDate yr) : brand(brnd), model(mdl), color(clr), year(yr)
{

}

QString Vehicle::createBaseQuery()
{
    return "INSERT INTO vehicle (brand, model, prodYear, color) VALUES ('"+brand+"','"+model+"','" + year.toString("yyyy") +  "','" + color +"')";
}
Vehicle::~Vehicle(){ }
