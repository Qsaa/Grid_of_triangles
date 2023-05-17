#include "Point.h"
#include "Cell.h"


size_t Cell::get_i() const
{
	return i_;
}

std::tuple<size_t, size_t, size_t> Cell::get_xyz() const
{
	return {i_x_, i_y_, i_z_ };
}

double Cell::get_x_min() const
{
	return x_min_;
}

double Cell::get_x_max() const
{
	return x_max_;
}

double Cell::get_y_min() const
{
	return y_min_;
}

double Cell::get_y_max() const
{
	return y_max_;
}

double Cell::get_z_min() const
{
	return z_min_;
}

double Cell::get_z_max() const
{
	return z_max_;
}

std::vector<ExtendPoint>& Cell::get_points() const;
{
	return data_;
}

double Cell::distance_to_point(Point* point)
{
	double distance_by_x = distance_to_point_one_dimensions(point->get_x(), x_min_, x_max_);
	double distance_by_y = distance_to_point_one_dimensions(point->get_y(), y_min_, y_max_);
	double distance_by_z = distance_to_point_one_dimensions(point->get_z(), z_min_, z_max_);
	return sqrt(distance_by_x * distance_by_x + distance_by_y * distance_by_y + distance_by_z * distance_by_z);
}

double Cell::distance_to_point_one_dimensions(double p, double min, double max)
{
	if ((min <= p && p <= max) || (max <= p && p <= min))
	{
		return 0;
	}
	else
	{
		double d1 = abs(min - p);
		double d2 = abs(max - p);
		return ((d1 < d2) ? d1 : d2);
	}
}

