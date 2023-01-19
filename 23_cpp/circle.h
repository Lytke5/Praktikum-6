#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"


class Circle : public Point
{
public:
    Circle();
    Circle(double x_, double y_, double r);
    double Distance(const Point &p);
    double Distance(const Circle &c);
    void Shift(double x_, double y_);
    void Show();
    void scale(double r);
    bool contains(const Point &p);
    bool intersect(const Circle &c);

private:
    double radius;
};

#endif // CIRCLE_H
