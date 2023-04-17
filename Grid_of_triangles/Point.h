#pragma once

#include <iostream>
#include <algorithm>

struct Point
{
    friend std::ostream& operator<< (std::ostream&, const Point&);
    friend std::istream& operator>> (std::istream& in, Point& p);

    Point();

    double get_x() const;
    double get_y() const;
    double get_z() const;

    double& set_x();
    double& set_y();
    double& set_z();

    void set_x(double);
    void set_y(double);
    void set_z(double);

    virtual void print() const;

    double distance(const Point& p) const;

private:
    double x_;
    double y_;
    double z_;
};

