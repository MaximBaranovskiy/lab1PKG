#include "xyz.h"
#include <cmath>

double XYZ::F(double x) const
{
    if(x>=0.008856){
        return pow(x,1.0/3.0);
    }
    return 7.787*x+16.0/116.0;
}

XYZ::XYZ(double x, double y, double z):x(x),y(y),z(z)
{}

double XYZ::getX() const
{
    return x;
}

double XYZ::getY() const
{
    return y;
}

double XYZ::getZ() const
{
    return z;
}

void XYZ::setX(double x)
{
    this->x = x;
}

void XYZ::setY(double y)
{
    this->y = y;
}

void XYZ::setZ(double z)
{
    this->z = z;
}

LAB XYZ::XYZ_TO_LAB() const
{
    double l,a,b;

    l = 116*F(y/100) - 16;
    a = 500*(F(x/95.047) - F(y/100));
    b = 200*(F(y/100) - F(z/108.883));

    return LAB(l,a,b);
}
