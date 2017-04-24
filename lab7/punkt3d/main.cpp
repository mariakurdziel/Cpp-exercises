//
// Created by maria on 22.04.17.
//


#include "Point3D.h"

int main()
{
    Point3D a(2, 3, 4);
    Point3D b(1, 2, 3);
    double c;
    c=a.DoubleDistance(b);
    std::cout<<c;

    Point3D point3d();
    Point point2d();
    //c=point2d.Distance(point3d); - nie działa, jeden ma 2 parametry, drugi 3

    Point3D p3d(1,2,3);
    //cout << p3d << endl; - nie można wypisać


    return 0;
}