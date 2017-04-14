//
// Created by olga on 14.04.17.
//

#include "Point1.h"


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using namespace std;
Point::Point() : x_(0), y_(0) {

}

Point::Point(double x, double y) {
    x_ = x;
    y_ = y;
    cout<<"Konstruktor POINT"<<endl;
    cout<<x_<<" "<<y_<<endl;
}

Point::~Point() {

}


double Point::Distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x)
{
    x_=x;
}

void Point::SetY(double y)
{
    y_=y;
}

Point3D::Point3D(double a, double b, double z):Point(a, b)
{
    z_=z;
    cout<<"Konstruktor POINT3D"<<endl;
    cout<<x_<<" "<<y_<<" "<<z_<<endl;
}

double Point3D::DoubleDistance(const Point3D &other) const
{
    cout<<"x "<<Point::GetX()<<endl;
    return sqrt(pow(Point::GetX() - other.Point::GetX(), 2) + pow(Point::GetY() - other.Point::GetY(), 2) + pow(z_ - other.GetZ(), 2));
}

double Point3D::GetZ() const
{
    return z_;
}

Point3D::~Point3D()
{}
