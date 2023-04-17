#include "ExtendPoint.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool my_fx(ExtendPoint* p1, ExtendPoint* p2)
{
	return p1->get_x() < p2->get_x();

}
bool my_fy(ExtendPoint* p1, ExtendPoint* p2)
{
	return p1->get_y() < p2->get_y();
}

bool my_fz(ExtendPoint* p1, ExtendPoint* p2)
{
	return p1->get_z() < p2->get_z();
}

int main()
{
	ifstream input_file("test_data.txt");
	if (!input_file.is_open())
	{
		cout << "Error! File wasn't found" << endl;
		return 0;
	}
	////Point* points = new ExtendPoint[5];
	//ExtendPoint* points = new ExtendPoint[5];
	//for (size_t i = 0; input_file >> points[i]; ++i);
	//for (size_t i = 0; i < 5; ++i)
	//{
	//	cout << points[i] << endl;
	//}



	vector<ExtendPoint> points;
	ExtendPoint point;
	while(input_file>> point)
	{
		points.push_back(point);
	}
	
	for (auto& el : points)
	{
		cout << el << endl;
	}
	cout << endl;

	vector<ExtendPoint*> px;
	ExtendPoint* p;
	for (auto& el : points)
	{
		p = &el;
		px.push_back(p);
	}
	sort(begin(px), end(px), my_fx);
	cout << "______________________X_______________" << endl;
	for (auto p : px)
	{
		cout << *p << endl;
	}

	vector<ExtendPoint*> py;
	for (auto& el : points)
	{
		p = &el;
		py.push_back(p);
	}
	cout << "______________________Y_______________" << endl;
	sort(begin(py), end(py), my_fy);
	for (auto p : py)
	{
		cout << *p << endl;
	}
	cout << endl;


	vector<ExtendPoint*> pz;
	for (auto& el : points)
	{
		p = &el;
		pz.push_back(p);
	}
	cout << "______________________Y_______________" << endl;
	sort(begin(pz), end(pz), [](ExtendPoint* p1, ExtendPoint* p2) { return p1->get_z() < p2->get_z(); });
	for (auto p : pz)
	{
		cout << *p << endl;
	}
	cout << endl;

	return 0;
}