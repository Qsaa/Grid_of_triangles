#pragma once

#include "ExtendPoint.h"
#include "Cell.h"
#include "Rectangular_Prallelepiped.h"

#include <vector>
#include <iostream>


struct Grid
{
public:
	Grid(const Rectangular_Prallelepiped& boarder, size_t size, double density);

	void insert_point(ExtendPoint& point);
	//std::vector<ExtendPoint*>& get_points_cell(size_t n_cell);
	
	//переделай потом с move семантикой
	//std::vector<ExtendPoint*>* foo();
	//ExtendPoint* get_closest_point(const ExtendPoint& point);

private:
	size_t get_the_cell_number(const ExtendPoint&) const;
	size_t convert_from_xyz_to_i(size_t x, size_t y, size_t z) const;
	std::tuple<size_t, size_t, size_t> convert_from_i_to_xyz(size_t) const;

public:
	void print_short();
	void print();
	void print_full();
	friend std::ostream& operator<<(std::ostream&, const Grid&);

private:
	/*double x_max_;
	double x_min_;

	double y_max_;
	double y_min_;
	
	double z_max_;
	double z_min_;*/

	Rectangular_Prallelepiped boarder_;

	size_t n_cell_x_;
	size_t n_cell_y_;
	size_t n_cell_z_;

	double len_section_x_;
	double len_section_y_;
	double len_section_z_;

	std::vector<Cell> сells_;

};

