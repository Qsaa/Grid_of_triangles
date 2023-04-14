#pragma once
struct Point
{
    //friend ostream& operator<< (ostream& out, const Point0& p);
    //friend istream& operator>> (istream& in, Point0& p);

    Point();
    double get_x() const;
    double get_y() const;
    double get_z() const;

    double distance(const Point& p) const;
private:
    double x_;
    double y_;
    double z_;
};

