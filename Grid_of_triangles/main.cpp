#include "ExtendPoint.h"
#include "Algorithm_Point.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>

//#define Matrix std::vector<std::vector<std::vector<std::vector<ExtendPoint*>>>>
//using Matrix = std::vector<std::vector<std::vector<std::vector<ExtendPoint*>>>>;

// Амортизацинная плотность точек в подэлементе 
constexpr auto DENSITY = 1;
// а было деашту
//using DENSITY2 = 2;

using namespace std;

int main()
{
	ifstream input_file("test_data.txt");
	//ifstream input_file("barrel-nodes.xyz");
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
	
	//for (auto& el : points)
	//{
	//	cout << el << endl;
	//}
	//cout << endl;
	//double len_x = x_max - x_min;
	//double len_y = y_max - y_min;
	//double len_z = z_max - z_min;

	//cout << "x_max: " << x_max << "   x_min: " << x_min << " __ " << x_max - x_min << endl;
	//cout << "y_max: " << y_max << "   y_min: " << y_min << " __ " << y_max - y_min << endl;
	//cout << "z_max: " << z_max << "   z_min: " << z_min << " __ " << z_max - z_min << endl;

	//double k_x = (len_x * len_x) / (len_y * len_z);
	//double k_y = (len_y * len_y) / (len_x * len_z);
	//double k_z = (len_z * len_z) / (len_x * len_y);

	//size_t n_x = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_x));
	//size_t n_y = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_y));
	//size_t n_z = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_z));

	Matrix matrix(x_max, x_min, y_max, y_min, z_max, z_min, points.size(), DENSITY);

	vector<int> v(5);
	cout << v.size() << endl;
	////cout << n_x * n_y * n_z << endl;
	////cout << "number_of_point: " << points.size() << endl;

	//vector<ExtendPoint*> p_sort_by_x;
	//ExtendPoint* p;
	//for (auto& el : points)
	//{
	//	p = &el;
	//	p_sort_by_x.push_back(p);
	//}
	//sort(begin(p_sort_by_x), end(p_sort_by_x), ExtendPoint::compare_by_x);
	//cout << "______________________X_______________" << endl;
	//for (auto p : p_sort_by_x)
	//{
	//	cout << *p << endl;
	//}

	//vector<ExtendPoint*> p_sort_by_y;
	//for (auto& el : points)
	//{
	//	p = &el;
	//	p_sort_by_y.push_back(p);
	//}
	//cout << "______________________Y_______________" << endl;
	//sort(begin(p_sort_by_y), end(p_sort_by_y), ExtendPoint::compare_by_y);
	//for (auto p : p_sort_by_y)
	//{
	//	cout << *p << endl;
	//}
	//cout << endl;


	//vector<ExtendPoint*> p_sort_by_z;
	//for (auto& el : points)
	//{
	//	p = &el;
	//	p_sort_by_z.push_back(p);
	//}

	//cout << "______________________Z_______________" << endl;
	//
	//sort(begin(p_sort_by_z), end(p_sort_by_z), ExtendPoint::compare_by_z);
	//for (auto p : p_sort_by_z)
	//{
	//	cout << *p << endl;
	//}
	//cout << endl;

	//ExtendPoint* closest_p = get_closest_point_nn(points[0], points.begin() + 1, points.end());
	//cout << "Point_ "<<points[0]<< " _the closest: "<< *closest_p << endl;
	return 0;
}