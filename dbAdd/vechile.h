#ifndef VECHILE_H
#define VECHILE_H
#include <QString>

class Vechile
{
protected:
    QString brand;
    QString model;
    QString color;
    int year;
public:
    virtual QString dbAdd1() = 0;
    virtual QString dbAdd2(int id) = 0;
    Vechile(QString b, QString m, QString c, int y);
    virtual ~Vechile() = 0;
};

#endif // VECHILE_H
