#include "ExtendPoint.h"

ExtendPoint::ExtendPoint(): Point(), id_(0), n_cell_(0){}

ExtendPoint::ExtendPoint(double x, double y, double z) : Point(x, y, z), id_(0), n_cell_(-1) {}

size_t ExtendPoint::get_id() const
{
	return id_;
}

int ExtendPoint::get_n_cell() const
{
	return n_cell_;
}

void ExtendPoint::set_cell(size_t pos)
{
	n_cell_ = pos;
}


std::istream& ExtendPoint::set(std::istream& in)
{
	char common;
	in >> id_ >> common >> set_x()>> common >> set_y()>> common >> set_z();
	return in;
}

ExtendPoint* ExtendPoint::get_closest_point_nn(std::vector<ExtendPoint*>& points) //const
{
	ExtendPoint* closest_Point = nullptr;
	double min_distance = -1;
	for (ExtendPoint* point : points)
	{
		double new_distance = distance(*point);
		if (id_ != point->get_id())
		{
			if (new_distance < min_distance || min_distance < 0)
			{
				min_distance = new_distance;
				closest_Point = point;
			}
		}
	}
    return closest_Point;
}


void ExtendPoint::print() const
{
	std::cout << (*this);
}

std::ostream& operator<<(std::ostream& out, const ExtendPoint& p)
{
	return out << "Number: " << p.id_ << " Cell: " << p.n_cell_ << " Point: " <<
		p.get_x() << " " << p.get_y() << ' ' << p.get_z();
}

std::istream& operator>>(std::istream& in, ExtendPoint& p)
{
	char note = '*';
	char common;
	in >> p.id_ >> common >> p.set_x() >> common >> p.set_y() >> common >> p.set_z();
	/*if (in >> p.id_ >> common >> p.set_x() >> common >> p.set_y() >> common >> p.set_z())
	{
		p.accetable_ = true;
	}
	else
	{
		p.accetable_ = false;
	}*/
	return in;
}
