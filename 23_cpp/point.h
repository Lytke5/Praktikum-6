#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double x_, double y_);
    double Distance(const Point &p);
    void Shift(double x_, double y_);
    void Show();

    double x;
    double y;
};

#endif // POINT_H
