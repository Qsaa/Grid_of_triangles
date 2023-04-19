#include "Algorithm_Point.h"

ExtendPoint* get_closest_point_nn(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end)
{
	if (it == end)
	{
		return nullptr;
	}
	double distance = p.distance(*it);
	ExtendPoint* closest_point = &(*it);
	while ((++it) != end)
	{
		double new_distance = p.distance(*it);
		if (distance > new_distance)
		{
			distance = new_distance;
			closest_point = &(*it);
		}
	}
	return closest_point;
}

ExtendPoint* get_closest_point(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end)
{

	return nullptr;
}
