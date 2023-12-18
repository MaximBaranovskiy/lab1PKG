#include "lab.h"



LAB::LAB(double l, double a, double b):l(l),a(a),b(b)
{}

double LAB::getL() const
{
    return l;
}

double LAB::getA() const
{
    return a;
}

double LAB::getB() const
{
    return b;
}

void LAB::setL(double l)
{
    this->l = l;
}

void LAB::setA(double a)
{
    this->a = a;
}

void LAB::setB(double b)
{
    this->b = b ;
}
