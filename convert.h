#ifndef CONVERT_H
#define CONVERT_H

#include "rgb.h"
#include "xyz.h"
#include "lab.h"

class Convert
{
public:
    static XYZ convertRGB_TO_XYZ(RGB rgb);
    static LAB convertRGB_TO_LAB(RGB rgb);
    static RGB convertXYZ_TO_RGB(XYZ xyz);
    static LAB convertXYZ_TO_LAB(XYZ xyz);
    static RGB convertLAB_TO_RGB(LAB lab);
    static XYZ convertLAB_TO_XYZ(LAB lab);

private:
    Convert();

    static double F_RGB_TO_XYZ(double x);
    static double F_XYZ_TO_RGB(double x);
    static double F_XYZ_TO_LAB(double x);
    static double F_LAB_TO_XYZ(double x);

};

#endif // CONVERT_H
