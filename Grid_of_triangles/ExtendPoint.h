#pragma once

#include "Point.h"

#include <vector>





struct ExtendPoint : Point
{
	friend std::ostream& operator<< (std::ostream& out, const ExtendPoint& p);
	friend std::istream& operator>> (std::istream& in, ExtendPoint& p);

	ExtendPoint();
	ExtendPoint(double, double, double);

	size_t get_id() const;
	int get_n_cell() const;

	void set_cell(size_t);
	std::istream& set(std::istream&);
	
	ExtendPoint* get_closest_point_nn(std::vector<ExtendPoint*>&);
	
	virtual void print() const;

private:
	size_t id_;
	int n_cell_;
};

