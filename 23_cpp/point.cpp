#include "point.h"
#include <cmath>
#include <iostream>

Point::Point()
{
    x=0;
    y=0;
}
Point::Point(double x_, double y_)
{
    x=x_;
    y=y_;
}

double Point::Distance(const Point &p)
{

    double a = (p.x-x) * (p.x-x);
    double b = (p.y-y) * (p.y-y);

    double c = sqrt(a+b);

    return c;
}

void Point::Shift(double x_, double y_)
{
    x+=x_;
    y+=y_;
}

void Point::Show()
{
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
}

