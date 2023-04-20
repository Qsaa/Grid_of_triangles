#pragma once

#include "ExtendPoint.h"

#include <vector>
struct Matrix
{
	Matrix(double x_max, double x_min, double y_max, double y_min, double z_max, double z_min, size_t size, double density);

	void insert_point(const ExtendPoint& point);
	void insert_point(ExtendPoint* point);
private:
	size_t n_x_;
	size_t n_y_;
	size_t n_z_;
	std::vector<std::vector<ExtendPoint*>> data_;
};

