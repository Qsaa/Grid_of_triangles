#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Point.h"

using namespace std;

struct Point0
{
    Point0() :x_(0), y_(0), z_(0) {}
    Point0(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    double get_x() const
    {
        return x_;
    }

    double get_y() const
    {
        return y_;
    }

    double get_z() const
    {
        return z_;
    }



    double dist(const Point0& p)
    {
        return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
    }
    bool x_bigger (const Point0& p)
    {
        return x_ > p.x_;
    }
    bool y_bigger(const Point0& p)
    {
        return y_ > p.y_;
    }
    bool z_bigger(const Point0& p)
    {
        return z_ > p.z_;
    }

    friend ostream& operator<< (ostream& out, const Point0& p)
    {
        return out << p.x_ << ' ' << p.y_ << ' ' << p.z_;
    }

    friend istream& operator>> (istream& in, Point0& p)
    {
        in >> p.x_ >> p.y_ >> p.z_;
        return in;
    }

//private:
    //unsigned n_;
    double x_;
    double y_;
    double z_;
};

struct ExtendPoint0
{
    ExtendPoint0() : number_(0), available_(true), p_() {}

    Point0 get_p() const
    {
        return p_;
    }
    friend ostream& operator<<(ostream& out, const ExtendPoint0& extend_p)
    {
        return out << extend_p.number_ << ' ' << extend_p.p_;
    }

    friend istream& operator>>(istream& in, ExtendPoint0& extend_p)
    {
        in >> extend_p.number_ >> extend_p.p_;
        return in;
    }
//private:
    unsigned number_;
    bool available_;
    Point0 p_;
};

void comma_to_space(string& str)
{
    for (auto& c : str)
    {
        if (c == ',')
        {
            c = ' ';
        }
    }
}


bool my_function(ExtendPoint0 a, ExtendPoint0 b)
{
    return a.get_p().get_x() < b.get_p().get_x();
}


void print_vector(auto& vec, int number = -1)
{
    for (auto& el : vec)
    {
        cout << el << endl;
        if (!--number)
        {
            break;
        }
    }
}

int main()
{
    Point p;
    //ifstream input_file("barrel-nodes.xyz");
    //if (!input_file.is_open())
    //{
    //    cout << "Error! File wasn't found" << endl;
    //    return 0;
    //}


    //vector<ExtendPoint0> points;
    //for (string str; getline(input_file, str); /*nothing*/)
    //{
    //    if (str[0] != '*')
    //    {
    //        comma_to_space(str);
    //        stringstream strs(str);
    //        ExtendPoint0 p;
    //        strs >> p;
    //        points.push_back(p);
    //    }
    //}



    //double dist = 9999;
    //size_t n_p = 0;
    //for (size_t i = 1; i < points.size(); ++i)
    //{
    //    if (points[0].p_.dist(points[i].p_) < dist)
    //    {
    //        dist = points[0].p_.dist(points[i].p_);
    //        n_p = i;
    //    }
    //}
    //cout << "- point:" << n_p + 1 << " dist:" << dist << endl;
    ////print_vector(points, 100);




    //vector<int> v = { 1, 2, 3, 4 };
    //print_vector(points);
    //sort(begin(points), end(points), my_function);
    //print_vector(points);
    //vector<ExtendPoint> points_x(points);
    //vector<ExtendPoint> points_y(points);
    //vector<ExtendPoint> points_z(points);



    return 0;
}
