#include "ExtendPoint.h"
#include "Algorithm_Point.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ifstream input_file("test_data.txt");
	if (!input_file.is_open())
	{
		cout << "Error! File wasn't found" << endl;
		return 0;
	}

	vector<ExtendPoint> points;
	ExtendPoint point;
	while(input_file >> point)
	{
		points.push_back(point);
	}
	
	for (auto& el : points)
	{
		cout << el << endl;
	}
	cout << endl;


	vector<ExtendPoint*> p_sort_by_x;
	ExtendPoint* p;
	for (auto& el : points)
	{
		p = &el;
		p_sort_by_x.push_back(p);
	}
	sort(begin(p_sort_by_x), end(p_sort_by_x), ExtendPoint::compare_by_x);
	cout << "______________________X_______________" << endl;
	for (auto p : p_sort_by_x)
	{
		cout << *p << endl;
	}

	vector<ExtendPoint*> p_sort_by_y;
	for (auto& el : points)
	{
		p = &el;
		p_sort_by_y.push_back(p);
	}
	cout << "______________________Y_______________" << endl;
	sort(begin(p_sort_by_y), end(p_sort_by_y), ExtendPoint::compare_by_y);
	for (auto p : p_sort_by_y)
	{
		cout << *p << endl;
	}
	cout << endl;


	vector<ExtendPoint*> p_sort_by_z;
	for (auto& el : points)
	{
		p = &el;
		p_sort_by_z.push_back(p);
	}

	cout << "______________________Z_______________" << endl;
	
	sort(begin(p_sort_by_z), end(p_sort_by_z), ExtendPoint::compare_by_z);
	for (auto p : p_sort_by_z)
	{
		cout << *p << endl;
	}
	cout << endl;

	ExtendPoint* closest_p = get_closest_point_nn(points[0], points.begin() + 1, points.end());
	

	cout << "Point_ "<<points[0]<< " _the closest: "<< *closest_p << endl;
	return 0;
}