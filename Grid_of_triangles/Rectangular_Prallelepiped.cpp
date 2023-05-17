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

Rectangular_Prallelepiped::Rectangular_Prallelepiped(
	double x_min, double x_max, double y_min, double y_max, double z_min, double z_max)
{
	x_min_ = x_min;
	x_max_ = x_max;

	y_min_ = y_min;
	y_max_ = y_max;

	z_min_ = z_min;
	z_max_ = z_max;
}

XYZ_number::XYZ_number() :i_x_(-1), i_y_(-1), i_z_(-1) {}

XYZ_number::XYZ_number(int x, int y, int z) : i_x_(x), i_y_(y), i_z_(z) {}
