#ifndef IVEHICLE_H
#define IVEHICLE_H

#include <QString>

class IVehicle
{
public:
    virtual QString createBaseQuery() = 0;
    virtual QString createDetailsQuery(int id) = 0;
};



#endif // IVEHCILE_H
