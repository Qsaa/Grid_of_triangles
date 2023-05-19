#include "Point.h"

std::ostream& operator<< (std::ostream& out, const Point& p)
{
	return out << p.x_ << ' ' << p.y_ << ' ' << p.z_;
}

std::istream& operator>> (std::istream& in, Point& p)
{
	in >> p.x_ >> p.y_ >> p.z_;
	return in;
}

bool Point::compare_by_x(const Point* const p1, const Point* const p2)
{
	return p1->get_x() < p2->get_x();
}

bool Point::compare_by_y(const Point* const p1, const Point* const p2)
{
	return p1->get_y() < p2->get_y();
}

bool Point::compare_by_z(const Point* const p1, const Point* const p2)
{
	return p1->get_z() < p2->get_z();
}


Point::Point() : x_(0), y_(0), z_(0) {}

Point::Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}

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

//double Point::distance(const Point& p) const
//{
//	return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
//}

double Point::distance(Point& p)
{
	return sqrt(pow((x_ - p.x_), 2) + pow((y_ - p.y_), 2) + pow((z_ - p.z_), 2));
}


//Point* Point::get_closest_point_nn(const std::vector<Point*>& vector_points) const
//{
//	if (vector_points.empty())
//	{
//		return nullptr;
//	}
//
//	Point* closest_Point = vector_points[0];
//	double min_distance = distance(*(vector_points[0]));
//	for (size_t i = 1; i < vector_points.size(); ++i)
//	{
//		double new_distance = distance(*(vector_points[0]));
//		if (min_distance > new_distance)
//		{
//			min_distance = new_distance;
//		}
//	}
//	return closest_Point;
//}

//Point* get_closest_point_nn(std::vector< std::vector<Point*> >& vector_points) //const
//{
//	if (vector_points.empty())
//	{
//		return nullptr;
//	}
//	get_closest_point_nn(vector_points[0]);
//	return nullptr;
//}
