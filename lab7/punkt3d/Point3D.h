//
// Created by maria on 21.04.17.
//

#ifndef JIMP_EXERCISES_PUNKT3D_H
#define JIMP_EXERCISES_PUNKT3D_H


#include <iostream>
#include <string>
#include <cmath>
#include <ostream>

using namespace std;

class Point {
public:
    Point();
    Point(double x, double y);
    ~Point();

    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;

    double GetX() const;

    friend ostream &operator<<(ostream &os, const Point &point);

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

#endif //JIMP_EXERCISES_PUNKT3D_H
