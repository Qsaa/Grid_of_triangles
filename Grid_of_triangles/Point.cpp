#include "Point.h"

Point::Point() : x_(0), y_(0), z_(0) {}

double Point::get_x() const
{
	return x_;
}

double Point::get_y() const
{
	return y_;
}

double Point::get_z() const
{
	return z_;
}

double& Point::set_x()
{
	return x_;
}

double& Point::set_y()
{
	return y_;
}

double& Point::set_z()
{
	return z_;
}

void Point::set_x(double x)
{
	x_ = x;
}

void Point::set_y(double y)
{
	y_ = y;
}

void Point::set_z(double z)
{
	z_ = z;
}

void Point::print() const
{
	std::cout << (*this);
}

double Point::distance(const Point& p) const
{
	return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
}

std::ostream& operator<< (std::ostream& out, const Point& p)
{
	return out << p.x_ << ' ' << p.y_ << ' ' << p.z_;
}

std::istream& operator>> (std::istream& in, Point& p)
{
	in >> p.x_ >> p.y_ >> p.z_;
	return in;
}
