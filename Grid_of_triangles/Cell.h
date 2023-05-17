#pragma once

#include "ExtendPoint.h"
#include "Rectangular_Prallelepiped.h"

#include<vector>
#include<cmath>

struct Cell
{
	// Написать конструкторы!!!! TODO
	Cell();

	void set_i(size_t);
	void set_i_xyz(const XYZ_number&);
	void set_i_xyz(size_t, size_t, size_t);
	void set_boarder(const Rectangular_Prallelepiped&);

	size_t get_i() const;
	std::tuple<size_t, size_t, size_t> get_xyz() const; // TODO можно переделать в структуру
	XYZ_number& get_xyz(); // можно переделать в структуру
	
	double get_x_min() const;
	double get_x_max() const;
	double get_y_min() const;
	double get_y_max() const;
	double get_z_min() const;
	double get_z_max() const;

	const std::vector<ExtendPoint*>& get_points() const;
	std::vector<ExtendPoint*>& get_points();

	double distance_to_point(const Point& point) const;

private:
	double distance_to_point_one_dimensions(double p, double min, double max) const;
private:
	int i_;

	//int i_x_;
	//int i_y_;
	//int i_z_;

	XYZ_number xyz_;

	Rectangular_Prallelepiped boarder_;

	std::vector<ExtendPoint*> data_;
};
