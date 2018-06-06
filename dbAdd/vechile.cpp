#include "vechile.h"
QString brand;
QString model;
QString color;
int year;

Vechile::Vechile(QString b, QString m, QString c, int y)
{
    brand = b;
    model = m;
    color = c;
    year = y;
}

Vechile::~Vechile(){}
