#pragma once

#include <iostream>

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

    //ouble distance(const Point& p) const;
    double distance(Point& p);
    //Point* get_closest_point_nn(std::vector<Point*>::iterator vector_points);
    //template<typename T>
    //Point* get_closest_point_nn(const T& vector_points);

    //Point* get_closest_point_nn( Point* vector_points);// const;
    //Point* get_closest_point_nn(std::vector<std::vector<Point*>>& vector_points);// const;

private:
    double x_;
    double y_;
    double z_;
};

//template<typename T>
//inline Point* Point::get_closest_point_nn(const T& vector_points)
//{
//    if (vector_points.empty())
//    {
//        return nullptr;
//    }
//
//    Point* closest_Point = vector_points[0];
//    double min_distance = distance(*(vector_points[0]));
//    for (size_t i = 1; i < vector_points.size(); ++i)
//    {
//        double new_distance = distance(*(vector_points[0]));
//        if (min_distance > new_distance)
//        {
//            min_distance = new_distance;
//        }
//    }
//    return closest_Point;
//}
