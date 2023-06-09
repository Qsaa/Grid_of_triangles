#include "Cell.h"
#include "Point.h"


Cell::Cell() : i_(-1), number_of_points(0), xyz_(), boarder_() {}

void Cell::set_i(int i)
{
	// you can add a check to see if this cell is ok
	// TODO
	i_ = i;
}

void Cell::set_i_xyz(const X_Y_Z& xyz)
{
	xyz_.i_x_ = xyz.i_x_;
	xyz_.i_y_ = xyz.i_y_;
	xyz_.i_z_ = xyz.i_z_;
}

void Cell::set_i_xyz(int i_x, int i_y, int i_z)
{
	xyz_.i_x_ = i_x;
	xyz_.i_y_ = i_y;
	xyz_.i_z_ = i_z;
}

void Cell::set_boarder(const Rectangular_Prallelepiped& boarder)
{
	boarder_.x_max_ = boarder.x_max_;
	boarder_.x_min_ = boarder.x_min_;

	boarder_.y_max_ = boarder.y_max_;
	boarder_.y_min_ = boarder.y_min_;
	
	boarder_.z_max_ = boarder.z_max_;
	boarder_.z_min_ = boarder.z_min_;
}

void Cell::set_boarder(double x_min, double x_max, double y_min, double y_max, double z_min, double z_max)
{
	boarder_.x_min_ = x_min;
	boarder_.x_max_ = x_max;

	boarder_.y_min_ = y_min;
	boarder_.y_max_ = y_max;

	boarder_.z_min_ = z_min;
	boarder_.z_max_ = z_max;
}

void Cell::add_extend_point(ExtendPoint* point)
{
	point->set_cell(i_);
	extend_points_.push_back(point);
	++number_of_points;
}

size_t Cell::get_i() const
{
	return i_;
}

X_Y_Z& Cell::get_xyz()
{
	return xyz_;
}

std::tuple<size_t, size_t, size_t> Cell::get_xyz() const
{
	return {xyz_.i_x_, xyz_.i_y_, xyz_.i_z_ };
}

double Cell::get_x_min() const
{
	return boarder_.x_min_;
}

double Cell::get_x_max() const
{
	return boarder_.x_max_;
}

double Cell::get_y_min() const
{
	return boarder_.y_min_;
}

double Cell::get_y_max() const
{
	return boarder_.y_max_;
}

double Cell::get_z_min() const
{
	return boarder_.z_min_;
}

double Cell::get_z_max() const
{
	return boarder_.z_max_;
}

const std::vector<ExtendPoint*>& Cell::get_points() const
{
	return extend_points_;
	//return Cell::get_points();
}

std::vector<ExtendPoint*>& Cell::get_points()
{
	return extend_points_;
}


double Cell::distance_to_point(const Point* point) const
{
	double distance_by_x = distance_to_point_one_dimensions(point->get_x(), boarder_.x_min_, boarder_.x_max_);
	double distance_by_y = distance_to_point_one_dimensions(point->get_y(), boarder_.y_min_, boarder_.y_max_);
	double distance_by_z = distance_to_point_one_dimensions(point->get_z(), boarder_.z_min_, boarder_.z_max_);
	return sqrt(distance_by_x * distance_by_x + distance_by_y * distance_by_y + distance_by_z * distance_by_z);
}

ExtendPoint& Cell::closest_point_in_cell_nn(ExtendPoint& point_0)
{
	ExtendPoint& p = *(point_0.get_closest_point_nn(this->get_points()));
	return p;
}

/*ExtendPoint& Cell::closest_point_in_cell_nn(Point&)
{
	// TODO: �������� ����� �������� return
	ExtendPoint p;//!!!!!!!!!!!
	return p;//!!!!!!!
}*/

double Cell::distance_to_point_one_dimensions(double p, double min, double max) const
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

