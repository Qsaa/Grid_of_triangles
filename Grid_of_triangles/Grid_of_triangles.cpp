#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    Point() :x_(0), y_(0), z_(0) {}
    Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}

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

    double dist(const Point& p)
    {
        return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
    }
    bool x_bigger (const Point& p)
    {
        return x_ > p.x_;
    }
    bool y_bigger(const Point& p)
    {
        return y_ > p.y_;
    }
    bool z_bigger(const Point& p)
    {
        return z_ > p.z_;
    }

    friend ostream& operator<< (ostream& out, const Point& p)
    {
        return out << p.x_ << ' ' << p.y_ << ' ' << p.z_;
    }

    friend istream& operator>> (istream& in, Point& p)
    {
        in >> p.x_ >> p.y_ >> p.z_;
        return in;
    }

private:
    //unsigned n_;
    double x_;
    double y_;
    double z_;
};

struct ExtendPoint
{

    Point get_p() const
    {
        return p_;
    }
    friend ostream& operator<<(ostream& out, const ExtendPoint& extend_p)
    {
        return out << extend_p.number_ << ' ' << extend_p.p_;
    }

    friend istream& operator>>(istream& in, ExtendPoint& extend_p)
    {
        in >> extend_p.number_ >> extend_p.p_;
        return in;
    }
private:
    unsigned number_;
    Point p_;
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


bool my_function(ExtendPoint a, ExtendPoint b)
{
    return a.get_p().get_x() < b.get_p().get_x();
}


void print_vector(auto& vec)
{
    int number = 100;
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
    ifstream input_file("barrel-nodes.xyz");
    if (!input_file.is_open())
    {
        cout << "Error! File wasn't found" << endl;
        return 0;
    }


    vector<ExtendPoint> points;
    for (string str; getline(input_file, str); /*nothing*/)
    {
        if (str[0] != '*')
        {
            comma_to_space(str);
            stringstream strs(str);
            ExtendPoint p;
            strs >> p;
            points.push_back(p);
        }
    }

    //vector<int> v = { 1, 2, 3, 4 };
    print_vector(points);
    sort(begin(points), end(points), my_function);
    print_vector(points);
    vector<ExtendPoint> points_x(points);
    vector<ExtendPoint> points_y(points);
    vector<ExtendPoint> points_z(points);



    return 0;
}
