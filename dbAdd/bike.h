#ifndef BIKE_H
#define BIKE_H
#include <QDebug>
#include "vechile.h"

class Bike : public Vechile
{
protected:
    QString type;
public:
    Bike(QString b, QString m, QString c, int y,QString t);
    QString dbAdd1();
    QString dbAdd2(int id);

};

#endif // BIKE_H
