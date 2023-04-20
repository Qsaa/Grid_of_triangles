#include "Algorithm_Point.h"

ExtendPoint* get_closest_point_nn(const ExtendPoint& p, std::vector<ExtendPoint>::iterator it, std::vector<ExtendPoint>::iterator end)
{
	if (it == end)
	{
		return nullptr;
	}
	double distance = p.distance(*it);
	ExtendPoint* closest_point = &(*it);
	while ((++it) != end)
	{
		double new_distance = p.distance(*it);
		if (distance > new_distance)
		{
			distance = new_distance;
			closest_point = &(*it);
		}
	}
	return closest_point;
}

std::vector<ExtendPoint*>::iterator get_closest_point_planeX(double border_of_square, auto begin, auto end)
{
	if (begin == end)
	{
		std::cout << "Error!" << std::endl;
		// не пор€док
	}

	std::vector<ExtendPoint*>::iterator closest_pos;
	while ()
	{
		auto it = begin + (end - begin) / 2;
		if ((*it)->get_x() <= border_of_square)
		{
			begin = it;
		}
		else
		{
			end = it;
		}
	}
	return closest_pos;
}

ExtendPoint* get_closest_point(const ExtendPoint& p, std::vector<ExtendPoint*>::iterator begin, std::vector<ExtendPoint*>::iterator end)
{

	sort(begin, end, ExtendPoint::compare_by_x);

	double border_of_square = get_max((*begin)->get_x(), (*begin)->get_y(), (*begin)->get_z());
	// раздел€й и властвуй
	get_closest_point_planeX(border_of_square, begin, end);

	// отсортированный ветор по x. O - log(n);



	//отдел€ем лишние точки
	std::vector<ExtendPoint*> close_points;

	double x = it->get_x();
	double x = it->get_x();

	return nullptr;
}

double get_max(double num1, double num2, double num3)
{
	if (num1 >= num2 && num1 >= num3)
	{
		return num1;
	}
	else if (num2 >= num3 && num2 >= num1)
	{
		return num2;
	}
	else if (num3 >= num1 && num3 >= num2)
	{
		return num3;
	}
}

//size_t get_max_of3_id(const ExtendPoint* const ep1, const ExtendPoint* const ep2, const ExtendPoint* const ep3)
//{
//	if (num1 >= num2 && num1 >= num3)
//	{
//		return num1;
//	}
//	else if (num2 >= num3 && num2 >= num1)
//	{
//		return num2;
//	}
//	else if (num3 >= num1 && num3 >= num2)
//	{
//		return num3;
//	}
//}