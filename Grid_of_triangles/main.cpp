//#include "ExtendPoint.h"
//#include "Algorithm_Point.h"
#include "Grid.h"
#include "Cell.h"
#include "ExtendPoint.h"
#include "Point.h"
#include "Rectangular_Prallelepiped.h"
//#include "Function.h"

#include <iostream>
#include <fstream>


// јмортизацинна€ плотность точек в подэлементе 
constexpr auto DENSITY = 1;

using namespace std;

int read_data(vector<ExtendPoint>& points, Rectangular_Prallelepiped& boarder)
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

	ExtendPoint point;
	input_file >> point;
	points.push_back(point);

	boarder.x_max_ = boarder.x_min_ = point.get_x();
	boarder.y_max_ = boarder.y_min_ = point.get_y();
	boarder.z_max_ = boarder.z_min_ = point.get_z();


	while (input_file >> point)
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

	/*
	cout << "x_max: " << boarder.x_max_ << "   x_min: " << boarder.x_min_ << " __ " << boarder.x_max_ - boarder.x_min_ << endl;
	cout << "y_max: " << boarder.y_max_ << "   y_min: " << boarder.y_min_ << " __ " << boarder.y_max_ - boarder.y_min_ << endl;
	cout << "z_max: " << boarder.z_max_ << "   z_min: " << boarder.z_min_ << " __ " << boarder.z_max_ - boarder.z_min_ << endl;
	//*/
	return 0;
}


int main()
{
	vector<ExtendPoint> points;
	Rectangular_Prallelepiped boarder;

	read_data(points, boarder);

	//--
	double d1 = sqrt(
		(boarder.x_max_ - boarder.x_min_) * (boarder.x_max_ - boarder.x_min_) +
		(boarder.y_max_ - boarder.y_min_) * (boarder.y_max_ - boarder.y_min_) +
		(boarder.z_max_ - boarder.z_min_) * (boarder.z_max_ - boarder.z_min_));
	//--


	Grid grid(boarder, points.size(), DENSITY);
	grid.fill(points);

	for(size_t i = 0; i < 8; ++i)
	{
		std::cout << grid.get_cell(i).distance_to_point(&points[0]) << '\n';
	}


	size_t i_cell = points[0].get_the_cell_number(); // получим номер €чейки, в которой точка
	ExtendPoint *p = &(grid.get_cell(i_cell).closest_point_in_cell_nn(points[0])); // получим близжайшую точку к нашей точке в этой €чейки

	double distance = points[0].distance(p);

	std::set<Cell*> cells;
	//grid.nearest_cells(cells, p, d1);
	grid.nearest_cells(cells, &points[0], distance);



	/*cout << points[0] << endl;
	cout << points[1] << endl << endl;
	
	cout << static_cast<Point>(points[0]) << endl;
	cout << *p << endl << endl;

	Point middle_p = points[0].get_point_in_the_middle(p);
	
	cout << middle_p << endl;*/

	//grid.get_cell(i_cell).closest_point_in_cell_nn(middle_p);
	//cout << i_cell << " " << i_point << " " << grid.get_number_cell() << endl;
	
	cout << "The end" << endl;
	return 0;
}

