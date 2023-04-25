#include "ExtendPoint.h"
#include "Algorithm_Point.h"
#include "Grid.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>

#include <exception>

//#define Matrix std::vector<std::vector<std::vector<std::vector<ExtendPoint*>>>>
//using Matrix = std::vector<std::vector<std::vector<std::vector<ExtendPoint*>>>>;

// Амортизацинная плотность точек в подэлементе 
constexpr auto DENSITY = 10;
// а было деашту
//using DENSITY2 = 2;

using namespace std;

int main()
{
	//ifstream input_file("test_data.txt");
	ifstream input_file("barrel-nodes.xyz");
	if (!input_file.is_open())
	{
		cout << "Error! File wasn't found" << endl;
		return 0;
	}

	double x_max;
	double x_min;
	double y_max;
	double y_min;
	double z_max;
	double z_min;

	vector<ExtendPoint> points;
	ExtendPoint point;

	input_file >> point;
	points.push_back(point);

	x_max = x_min = point.get_x();
	y_max = y_min = point.get_y();
	z_max = z_min = point.get_z();

	while(input_file >> point)
	{
		if (x_max < point.get_x())
		{
			x_max = point.get_x();
		}
		if (x_min > point.get_x())
		{
			x_min = point.get_x();
		}

		if (y_max < point.get_y())
		{
			y_max = point.get_y();
		}
		if (y_min > point.get_y())
		{
			y_min = point.get_y();
		}

		if (z_max < point.get_z())
		{
			z_max = point.get_z();
		}
		if (z_min > point.get_z())
		{
			z_min = point.get_z();
		}

		points.push_back(point);
	}
	cout << "x_max: " << x_max << "   x_min: " << x_min << " __ " << x_max - x_min << endl;
	cout << "y_max: " << y_max << "   y_min: " << y_min << " __ " << y_max - y_min << endl;
	cout << "z_max: " << z_max << "   z_min: " << z_min << " __ " << z_max - z_min << endl;

	
	Grid grid(x_max, x_min, y_max, y_min, z_max, z_min, points.size(), DENSITY);

	for (auto& pointH : points)
	{
		grid.insert_point(pointH);
	}

	auto va = grid.get_points_cell(0);

	cout << grid << endl;

	for (auto& a : *va)
	{
		cout << *a << endl;
	}

	//points[0].get_closest_point_nn();

	
	cout << "The end" << endl;
	return 0;
}