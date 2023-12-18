#include "rgb.h"
#include <cmath>
#include<QDebug>

double RGB::F(double x) const
{
    if(x>=0.04045){
        return std::pow(((x+0.055)/1.055),2.4);
    }
    return x/12.92;
}

RGB::RGB(double r, double g, double b):r(r),g(g),b(b)
{}

void RGB::setR(double r)
{
    this->r = r;
}

void RGB::setG(double g)
{
    this->g = g;
}

void RGB::setB(double b)
{
    this->b = b;
}

double RGB::getR() const
{
    return r;
}

double RGB::getG() const
{
    return g;
}

double RGB::getB() const
{
    return b;
}

XYZ RGB::RGB_TO_XYZ() const
{
    double x,y,z;
    qDebug()<<r;
    qDebug()<<g;
    qDebug()<<b;

    double Rn = F(r/255)*100;
    double Gn = F(g/255)*100;
    double Bn = F(b/255)*100;

    x =0.412453*Rn + 0.357580*Gn + 0.180423*Bn;
    y =0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
    z =0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

    return XYZ(x,y,z);
}
