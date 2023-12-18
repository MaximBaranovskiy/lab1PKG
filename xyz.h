#ifndef XYZ_H
#define XYZ_H

#include "lab.h"


class XYZ
{
private:
    double x;
    double y;
    double z;

    double F(double x) const;
public:
    XYZ(double x = 0,double y = 0,double z = 0);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    LAB XYZ_TO_LAB() const;

};

#endif // XYZ_H
