//
// Created by mrozolga on 21.03.17.
//


#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


namespace geometry {
    using namespace ::std;

    Point::Point() : x_(0), y_(0) {

    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
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

    double Square::Area() const {
        if (p1.Distance(p3) == p2.Distance(p4))
            return pow(p1.Distance(p2), 2);
        else return 0;
    }

    double Square::Circumference() const {
        if (p1.Distance(p3) == p2.Distance(p4))

            return p1.Distance(p2) * 4;
        else return 0;
    }

    Square::Square() {

    }

    Square::Square(const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
    }

    Square::~Square() {

    }
}