//#include "ExtendPoint.h"
//#include "Algorithm_Point.h"
#include "Grid.h"
#include "Cell.h"
#include "ExtendPoint.h"
#include "Point.h"
#include "Rectangular_Prallelepiped.h"

#include <iostream>
#include <fstream>
//#include <algorithm>
//#include <vector>
//#include <math.h>


// јмортизацинна€ плотность точек в подэлементе 
constexpr auto DENSITY = 10;

using namespace std;

int main()
{
	//TODO
	//¬ыполнить проверку если количество точек больше, чем max_int бросить исключение
	
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
	
	Rectangular_Prallelepiped boarder;
	boarder.x_max_ = boarder.x_min_ = point.get_x();
	boarder.y_max_ = boarder.y_min_ = point.get_y();
	boarder.z_max_ = boarder.z_min_ = point.get_z();
	

	while(input_file >> point)
	{
		if (boarder.x_max_ < point.get_x())
		{
			boarder.x_max_ = point.get_x();
		}
		if (boarder.x_min_ > point.get_x())
		{
			boarder.x_min_ = point.get_x();
		}

		if (boarder.y_max_ < point.get_y())
		{
			boarder.y_max_ = point.get_y();
		}
		if (boarder.y_min_ > point.get_y())
		{
			boarder.y_min_ = point.get_y();
		}

		if (boarder.z_max_ < point.get_z())
		{
			boarder.z_max_ = point.get_z();
		}
		if (boarder.z_min_ > point.get_z())
		{
			boarder.z_min_ = point.get_z();
		}

		points.push_back(point);
	}

	cout << "x_max: " << boarder.x_max_ << "   x_min: " << boarder.x_min_ << " __ " << boarder.x_max_ - boarder.x_min_ << endl;
	cout << "y_max: " << boarder.y_max_ << "   y_min: " << boarder.y_min_ << " __ " << boarder.y_max_ - boarder.y_min_ << endl;
	cout << "z_max: " << boarder.z_max_ << "   z_min: " << boarder.z_min_ << " __ " << boarder.z_max_ - boarder.z_min_ << endl;


	Grid grid(boarder, points.size(), DENSITY);

	for (auto& pointH : points)
	{
		grid.insert_point(pointH);
	}

	//auto va = grid.get_points_cell(0);

	cout << grid << endl;

	//for (auto& a : *va)
	//{
	//	cout << *a << endl;
	//}


	//size_t n_cell = points[0].get_n_cell(); // получаем номер €чейки
	//Cell&  pointer_on_cell = grid.get_points_cell(n_cell); // получаем указатель на вектор точек в данной €чейки
	//std::vector<Point*>* ppp = static_cast< std::vector<Point*>* > (pointer_on_cell);
	//ExtendPoint* p1 =  points[0].get_closest_point_nn(pointer_on_cell); //
	//cout << points[0] << endl;
	//cout << *p1 << endl;
	
	cout << "The end" << endl;
	return 0;
}


//Point make_middle_point(const Point& p1, const Point& p2)
//{
//	return Point((p1.get_x() + p2.get_x()) / 2.0, (p1.get_y() + p2.get_y()) / 2.0, (p1.get_z() + p2.get_z()) / 2.0);
//}