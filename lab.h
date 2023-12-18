#ifndef LAB_H
#define LAB_H


class LAB
{
private:
    double l;
    double a;
    double b;
public:
    LAB(double l = 0,double a = 0,double b = 0);

    double getL() const;
    double getA() const;
    double getB() const;

    void setL(double l);
    void setA(double a);
    void setB(double b);

};

#endif // LAB_H
