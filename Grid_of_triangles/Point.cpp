#include "Point.h"

#include <algorithm>

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

double Point::distance(const Point& p) const
{
	return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
}

