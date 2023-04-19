#pragma once

#include "ExtendPoint.h"

#include <vector>

//std::vector<ExtendPoint>::iterator begin, end
ExtendPoint* get_closest_point_nn(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end);

ExtendPoint* get_closest_point(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end);

