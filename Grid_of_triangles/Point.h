#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

struct Point
{
    friend std::ostream& operator<< (std::ostream&, const Point&);
    friend std::istream& operator>> (std::istream& in, Point& p);

    static bool compare_by_x(const Point* const p1, const Point* const p2);
    static bool compare_by_y(const Point* const p1, const Point* const p2);
    static bool compare_by_z(const Point* const p1, const Point* const p2);

    Point(); 
    Point(double, double, double);

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
    //Point* get_closest_point_nn(std::vector<Point*>& vector_points);// const;
    //Point* get_closest_point_nn(std::vector<std::vector<Point*>>& vector_points);// const;

private:
    double x_;
    double y_;
    double z_;
};

