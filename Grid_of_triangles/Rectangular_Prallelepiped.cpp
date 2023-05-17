#include "Rectangular_Prallelepiped.h"

Rectangular_Prallelepiped::Rectangular_Prallelepiped()
{
	x_max_ = 0;
	x_min_ = 0;

	y_max_ = 0;
	y_min_ = 0;

	z_max_ = 0;
	z_min_ = 0;
}

XYZ_number::XYZ_number() :i_x_(-1), i_y_(-1), i_z_(-1) {}

XYZ_number::XYZ_number(int x, int y, int z) : i_x_(x), i_y_(y), i_z_(z) {}
