#pragma once

#include "ExtendPoint.h"

#include <vector>
#include <algorithm>

//std::vector<ExtendPoint>::iterator begin, end
ExtendPoint* get_closest_point_nn(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end);
ExtendPoint* get_closest_point(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end);

//double get_min(double num, ...);
double get_max(double num1, double num2, double num3);
size_t get_max_of3_id(const ExtendPoint* const, const ExtendPoint* const, const ExtendPoint* const);