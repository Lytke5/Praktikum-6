#include "circle.h"
#include <iostream>
#include <cmath>

Circle::Circle()
{
    x = 0;
    y = 0;
    radius = 0;
}

Circle::Circle(double x_, double y_, double r)
{
    x = x_;
    y = y_;
    radius = r;
}

double Circle::Distance(const Point &p)
{
    double x_ = (p.x-x) * (p.x-x);
    double y_ = (p.y-y) * (p.y-y);

    double solution = sqrt(x_+y_);

    return solution;
}

double Circle::Distance(const Circle &c)
{
    double x_ = (c.x-x) * (c.x-x);
    double y_ = (c.y-y) * (c.y-y);

    double solution = sqrt(x_+y_);

    return solution;
}

void Circle::Shift(double x_, double y_)
{
    x+=x_;
    y+=y_;
}

void Circle::Show()
{
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
}

void Circle::scale(double r)
{
    radius = r;
}

bool Circle::contains(const Point &p)
{
    int dist = (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    if ( dist <= radius * radius)
       return true;
    else
       return false;
}

bool Circle::intersect(const Circle &c)
{
    double d = sqrt((x - c.x) * (x - c.x)
                             + (y - c.y) * (y - c.y));

        if (d <= radius + c.radius) {
            return true;
        }
    return false;
}
