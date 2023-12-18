#ifndef RGB_H
#define RGB_H

#include "xyz.h"

class RGB
{
private:
    double r;
    double g;
    double b;

    double F(double x) const;
public:
    RGB(double r = 0,double g = 0,double b = 0);

    void setR(double r);
    void setG(double g);
    void setB(double b);

    double getR() const;
    double getG() const;
    double getB() const;

    XYZ RGB_TO_XYZ() const;
};

#endif // RGB_H
