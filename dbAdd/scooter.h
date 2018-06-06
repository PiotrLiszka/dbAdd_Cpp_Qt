#ifndef SCOOTER_H
#define SCOOTER_H
#include "vechile.h"

class Scooter : public Vechile
{
protected:
    int range;
public:
    Scooter(QString b, QString m, QString c, int y,int r);
    QString dbAdd1();
    QString dbAdd2(int id);
};

#endif // SCOOTER_H
