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

// јмортизацинна€ плотность точек в подэлементе 
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

	//auto va = grid.get_points_cell(0);

	//cout << grid << endl;

	//for (auto& a : *va)
	//{
	//	cout << *a << endl;
	//}


	size_t n_cell = points[0].get_n_cell(); // получаем номер €чейки
	Cell&  pointer_on_cell = grid.get_points_cell(n_cell); // получаем указатель на вектор точек в данной €чейки
	std::vector<Point*>* ppp = static_cast< std::vector<Point*>* > (pointer_on_cell);
	ExtendPoint* p1 =  points[0].get_closest_point_nn(pointer_on_cell); //
	cout << points[0] << endl;
	cout << *p1 << endl;
	
	cout << "The end" << endl;
	return 0;
}


Point make_middle_point(const Point& p1, const Point& p2)
{
	return Point((p1.get_x() + p2.get_x()) / 2.0, (p1.get_y() + p2.get_y()) / 2.0, (p1.get_z() + p2.get_z()) / 2.0);
}