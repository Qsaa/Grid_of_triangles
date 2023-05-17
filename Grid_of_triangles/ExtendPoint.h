#pragma once

#include "Point.h"
#include "Cell.h"

#include <string>





struct ExtendPoint : Point
{
	friend std::ostream& operator<< (std::ostream& out, const ExtendPoint& p);
	friend std::istream& operator>> (std::istream& in, ExtendPoint& p);

	ExtendPoint();
	ExtendPoint(double, double, double);

	size_t get_id() const;
	size_t get_n_cell() const;

	void set_cell(size_t);
	std::istream& set(std::istream&);
	
	ExtendPoint* get_closest_point_in_cell_nn(const Cell&) const;
	
	//double distance_to_wall(const Grid& grid) const; //??
	
	virtual void print() const;
private:
	size_t id_;
	size_t n_cell_;
};

