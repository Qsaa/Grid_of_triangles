#pragma once

#include "ExtendPoint.h"
#include "Cell.h"
#include "Rectangular_Prallelepiped.h"

#include <vector>
#include <iostream>


struct Grid
{
	friend std::ostream& operator<<(std::ostream&, const Grid&);

	Grid(const Rectangular_Prallelepiped& boarder, size_t size, double density);

	void insert_point(ExtendPoint& point);
	std::vector<ExtendPoint*>& get_points_cell(size_t n_cell);
	
	//переделай потом с move семантикой
	//std::vector<ExtendPoint*>* foo();
	//ExtendPoint* get_closest_point(const ExtendPoint& point);

private:
	std::tuple<size_t, size_t, size_t> get_cell_coordinates(const ExtendPoint&) const;
	std::tuple<size_t, size_t, size_t> get_cell_coordinates(size_t i) const;
	size_t get_cell_number(size_t, size_t, size_t) const;

private:
	double x_max_;
	double x_min_;

	double y_max_;
	double y_min_;
	
	double z_max_;
	double z_min_; 

	Rectangular_Prallelepiped boarder_;

	size_t n_x_;
	size_t n_y_;
	size_t n_z_;

	double section_x_;
	double section_y_;
	double section_z_;

	std::vector<double> boarder_x_;
	std::vector<double> boarder_y_;
	std::vector<double> boarder_z_;

	std::vector<Cell> data_;

};

