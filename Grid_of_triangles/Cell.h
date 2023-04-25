#pragma once

#include"ExtendPoint.h"

#include<vector>

struct Cell
{
	std::vector<ExtendPoint*>* get_points();
	size_t get_id();

private:
	size_t id_;
	std::vector<ExtendPoint*> ExtendPoint_;
};

