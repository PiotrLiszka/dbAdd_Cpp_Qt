#include "bike.h"
#include <QDebug>

Bike::Bike(QString b, QString m, QString c, int y, QString t)  : Vechile(b,m,c,y)
{
    type = t;
}

QString Bike::dbAdd1()
{
    qDebug() << brand << model<<color<< year << type;
    return "INSERT INTO vechile (brand, model, prodYear, color) VALUES ('"+brand+"','"+model+"','" +QString::number(year)+  "','" + color +"')";

}

QString Bike::dbAdd2(int id)
{
    qDebug() << id;
    return "INSERT INTO bike (type,vid) VALUES ('" + type + "','"+QString::number(id)+"')";
}
