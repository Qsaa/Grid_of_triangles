#pragma once

#include "ExtendPoint.h"
#include "Cell.h"
#include "Rectangular_Prallelepiped.h"
#include "X_Y_Z.h"

#include <vector>
#include <set>
#include <iostream>


struct Grid
{
public:
	Grid(const Rectangular_Prallelepiped& boarder, size_t size, double density);

	// up - i_up_by_x 
	int i_up(int);
	// down - i_down_by_x
	int i_down(int);
	// left - i_up_by_y
	int i_left(int);
	// right - i_down_by_y
	int i_right(int);
	// ahead - i_up_by_z
	int i_ahead(int);
	// back - i_down_by_z
	int i_back(int);

	// up - i_up_by_x 
	Cell* up(Cell*);
	// down - i_down_by_x
	Cell* down(Cell*);
	// left - i_up_by_y
	Cell* left(Cell*);
	// right - i_down_by_y
	Cell* right(Cell*);
	// ahead - i_up_by_z
	Cell* ahead(Cell*);
	// back - i_down_by_z
	Cell* back(Cell*);

	Cell* get_neighbouring_cell(Cell* cell, int(Grid::*)(int));

	size_t size() const;

	void insert_point(ExtendPoint& point);
	void fill(std::vector<ExtendPoint>& points);
	Cell& get_cell(size_t i);


	// Returns to std::set<Cell*>& cells 
	// that have a distance between them and a point less than the "distance"
	void nearest_cells(std::set<Cell*>& result, ExtendPoint*, double);
	void nearest_cells(std::set<Cell*>& result, Cell* cell, ExtendPoint* p, double dist);

	void is_cell_near(std::set<Cell*>& cells,  double, ExtendPoint*);

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

	Rectangular_Prallelepiped boarder_;

	size_t n_cell_x_;
	size_t n_cell_y_;
	size_t n_cell_z_;

	double len_section_x_;
	double len_section_y_;
	double len_section_z_;

	std::vector<Cell> cells_;

};

