#pragma once

#include<vector>
#include<cmath>

struct Point;
struct ExtendPoint;

struct Cell
{
	size_t get_i() const;
	std::tuple<size_t, size_t, size_t> get_xyz() const;
	
	double get_x_min() const;
	double get_x_max() const;
	double get_y_min() const;
	double get_y_max() const;
	double get_z_min() const;
	double get_z_max() const;

	std::vector<ExtendPoint>& get_points();

	double distance_to_point(Point* point) const;

private:
	double distance_to_point_one_dimensions(double p, double min, double max);
private:
	size_t i_;
	size_t i_x_;
	size_t i_y_;
	size_t i_z_;

	double x_min_;
	double x_max_;
	double y_min_;
	double y_max_;
	double z_min_;
	double z_max_;
	std::vector<ExtendPoint> data_;
};
