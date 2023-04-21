#pragma once

#include "Point.h"

#include <string>


struct ExtendPoint : Point
{
	friend std::ostream& operator<< (std::ostream& out, const ExtendPoint& p);
	friend std::istream& operator>> (std::istream& in, ExtendPoint& p);

	ExtendPoint();
	ExtendPoint(double, double, double);

	size_t get_id() const;

	void set_pos(size_t);
	std::istream& set(std::istream&);
	
	virtual void print() const;
private:
	size_t id_;
	size_t pos_;

	//?????
	bool accetable_;
};

