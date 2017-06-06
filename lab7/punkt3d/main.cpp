//
// Created by maria on 22.04.17.
//


#include "Point3D.h"

using namespace std;

int main()
{
    Point3D a(2, 3, 4);
    Point3D b(1, 2, 3);
    double c;
    c=a.DoubleDistance(b);
    std::cout<<c;

    //Zad6
    //Funkcja została wywołana, ale jedynie dla pierwszych dwóch współrzędnych, bo funkcja w klasie macierzystej jest utworzona, by liczyć  odległość dla 2 współrzędnych.//
    Point3D point3d(4,4,4);
    Point point2d(3,3);
    double d=point2d.Distance(point3d);
    std::cout<<d<<std::endl;

    //Zad7
    //Funkcja została wywołana i zwraca jedynie dwie pierwsze współrzędne.
    Point3D p3d(1,2,3);
    cout<< p3d<<endl;


    return 0;
}