#pragma once

struct Rectangular_Prallelepiped
{
	Rectangular_Prallelepiped();
	Rectangular_Prallelepiped(double, double, double, double, double, double);
	
	double x_min_;
	double x_max_;
	
	double y_min_;
	double y_max_;

	double z_min_;
	double z_max_;
};

struct XYZ_number
{
	XYZ_number();
	XYZ_number(int, int, int);
	int i_x_;
	int i_y_;
	int i_z_;
};