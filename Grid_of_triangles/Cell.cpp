#include "Cell.h"

std::vector<ExtendPoint*>* Cell::get_points()
{
	return &ExtendPoint_;
}

size_t Cell::get_id()
{
	return id_;
}
