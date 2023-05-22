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