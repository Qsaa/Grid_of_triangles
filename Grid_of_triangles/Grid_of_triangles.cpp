#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Point
{
    Point() :x_(0), y_(0), z_(0) {}
    Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}

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

int main()
{
    ifstream input_file("barrel-nodes.xyz");
    if (!input_file.is_open())
    {
        cout << "Error! File wasn't found" << endl;
        return 0;
    }


    vector<ExtendPoint> points_x;
    for (string str; getline(input_file, str); /*nothing*/)
    {
        if (str[0] != '*')
        {
            comma_to_space(str);
            stringstream strs(str);
            ExtendPoint p;
            strs >> p;
            points_x.push_back(p);
        }
    }

    vector<ExtendPoint> points_y(points_x);
    //for(auto p: points_y)
    //{
    //    cout << p << endl;
    //}




    //ifstream in("barrel-nodes.xyz");
    //if (!in.is_open())
    //{
    //    cout << "File is not opened" << endl;
    //    return 0;
    //}
    ////for (string str; getline(in, str); cout << str << endl);
    //
    //string str;
    //getline(in, str);

    //getline(in, str);
    //for (auto& c : str)
    //{
    //    if (c == ',')
    //    {
    //        c = ' ';
    //    }
    //}
    //cout << str << endl;

    //stringstream sstr(str);
    //
    //int n;
    //sstr >> n;
    //cout << n << endl;

    //double x, y, z;
    //Point p2;
    //sstr >> p2;
    //cout << p2;
    //Point p(x, y, z);
    //cin >> p;
    //cout << p << endl;
    //cout << x << " " << y << " " << z << endl;
    //cout << x + y + z << endl;



    return 0;
}
