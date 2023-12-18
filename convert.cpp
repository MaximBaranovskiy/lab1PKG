#include "convert.h"
#include <cmath>

XYZ Convert::convertRGB_TO_XYZ(RGB rgb)
{
    double x,y,z;

    double Rn = F_RGB_TO_XYZ(rgb.getR()/255)*100;
    double Gn = F_RGB_TO_XYZ(rgb.getG()/255)*100;
    double Bn = F_RGB_TO_XYZ(rgb.getB()/255)*100;

    x =0.412453*Rn + 0.357580*Gn + 0.180423*Bn;
    y =0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
    z =0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

    return XYZ(x,y,z);
}

LAB Convert::convertRGB_TO_LAB(RGB rgb)
{
    XYZ xyz = convertRGB_TO_XYZ(rgb);
    return convertXYZ_TO_LAB(xyz);
}

RGB Convert::convertXYZ_TO_RGB(XYZ xyz)
{
    double Rn,Gn,Bn;

    Rn = (3.2406*xyz.getX() +(-1.5372)*xyz.getY() +(-0.4986)*xyz.getZ()) /100.0;
    Gn = ((-0.9689)*xyz.getX() + 1.8758*xyz.getY() + 0.0415*xyz.getZ()) /100.0;
    Bn = (0.0557*xyz.getX() +(-0.2040)*xyz.getY() + 1.0570*xyz.getZ()) /100.0;


    return RGB(F_XYZ_TO_RGB(Rn)*255.0,F_XYZ_TO_RGB(Gn)*255.0,F_XYZ_TO_RGB(Bn)*255.0);
}

LAB Convert::convertXYZ_TO_LAB(XYZ xyz)
{
    double l,a,b;

    l = 116*F_XYZ_TO_LAB(xyz.getY()/100) - 16;
    a = 500*(F_XYZ_TO_LAB(xyz.getX()/95.047) - F_XYZ_TO_LAB(xyz.getY()/100));
    b = 200*(F_XYZ_TO_LAB(xyz.getY()/100) - F_XYZ_TO_LAB(xyz.getZ()/108.883));

    return LAB(l,a,b);
}

RGB Convert::convertLAB_TO_RGB(LAB lab)
{
    XYZ xyz = convertLAB_TO_XYZ(lab);
    return convertXYZ_TO_RGB(xyz);
}

XYZ Convert::convertLAB_TO_XYZ(LAB lab)
{
    double x,y,z;
    y = F_LAB_TO_XYZ((lab.getL() + 16.0)/116.0)*95.047;
    x = F_LAB_TO_XYZ(lab.getA()/500.0 + (lab.getL() + 16.0)/116.0)*100.0;
    z = F_LAB_TO_XYZ((lab.getL() + 16.0)/116.0 +((-lab.getB())/200.0))*108.883;

    return XYZ(x,y,z);
}

Convert::Convert()
{}

double Convert::F_RGB_TO_XYZ(double x)
{
    if(x>=0.04045){
        return std::pow(((x+0.055)/1.055),2.4);
    }
    return x/12.92;
}

double Convert::F_XYZ_TO_RGB(double x)
{
    if(x>=0.0031308){
        return 1.055*std::pow(x,1.0/2.4) - 0.055;
    }
    return 12.92*x;
}

double Convert::F_XYZ_TO_LAB(double x)
{
    if(x>=0.008856){
        return pow(x,1.0/3.0);
    }
    return 7.787*x+16.0/116.0;
}

double Convert::F_LAB_TO_XYZ(double x)
{
    if(std::pow(x,3)>=0.008856){
        return std::pow(x,3);
    }
    else return (x - 16.0/116.0)/7.787;
}
