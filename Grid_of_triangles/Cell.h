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
	void set_boarder(double, double, double, double, double, double);

	void add_extend_point(ExtendPoint*);

	size_t get_i() const;
	std::tuple<size_t, size_t, size_t> get_xyz() const; // CHECK можно убрать один из методов
	XYZ_number& get_xyz(); // CHECK можно убрать один из методов
	
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
	// this method helps "distance_to_point" method to calculate the distance
	double distance_to_point_one_dimensions(double p, double min, double max) const;
private:
	// This in number of cell. It is better to use "size_t", 
	// but in this case don't show -1, this fact says that this cell is connected to grid
	int i_;

	//int i_x_;
	//int i_y_;
	//int i_z_;
	size_t number_of_points;

	XYZ_number xyz_;

	Rectangular_Prallelepiped boarder_;

	std::vector<ExtendPoint*> data_;
};
