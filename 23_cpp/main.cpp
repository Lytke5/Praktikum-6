#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

int main()
{
    Point* Punkt1 = new Point();
    Punkt1->Shift(2.5,-1);
    Point* Punkt2 = new Point(5, 2);
    Punkt1->Distance(*Punkt2);

    Circle* Kreis1 = new Circle();
    Kreis1->Shift(3, -1);
    Kreis1->scale(2.3);

    cout << Kreis1->contains(*Punkt1) << endl;

    Circle* Kreis2 = new Circle(3, 4.5, 5);

    cout << Kreis2->contains(*Punkt1) << endl;

    cout << Kreis1->intersect(*Kreis2) << endl;


    return 0;
}
