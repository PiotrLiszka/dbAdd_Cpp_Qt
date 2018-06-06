#include "scooter.h"
#include <QDebug>

Scooter::Scooter(QString b, QString m, QString c, int y,int r) : Vechile(b,m,c,y)
{
    range = r;
}

QString Scooter::dbAdd1()
{

  //  std::cout << "GAY"<<endl;
    return "Yeah";

}
QString Scooter::dbAdd2(int id)
{
    return "x";
}

