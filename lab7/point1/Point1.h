//
// Created by olga on 14.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H


#include "Point1.h"
#include <iostream>
#include <cmath>
#include <string>

#include <iostream>
#include <string>
#include <cmath>
#include <ostream>


class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);
protected:
    double x_, y_;
};

class Point3D : public Point
{
private:
    double z_;
public:
    Point3D(double a, double b, double z);
    double DoubleDistance(const Point3D &other) const;
    double GetZ() const;
    ~Point3D();
};


#endif //JIMP_EXERCISES_POINT_H
