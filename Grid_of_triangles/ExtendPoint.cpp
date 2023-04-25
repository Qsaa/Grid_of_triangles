#include "ExtendPoint.h"

ExtendPoint::ExtendPoint(): Point(), id_(0), n_cell_(0), accetable_(false) {}

ExtendPoint::ExtendPoint(double x, double y, double z) : Point(x, y, z), id_(0), n_cell_(0) {}

size_t ExtendPoint::get_id() const
{
	return id_;
}

void ExtendPoint::set_cell(size_t pos)
{
	n_cell_ = pos;
}


std::istream& ExtendPoint::set(std::istream& in)
{
	char common;
	in >> id_ >> common >> set_x()>> common >> set_y()>> common >> set_z();
	accetable_ = true;
	return in;
}

//ExtendPoint* ExtendPoint::get_closest_point()
//{
//	n_cell_;
//	return nullptr;
//}

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
	if (in >> p.id_ >> common >> p.set_x() >> common >> p.set_y() >> common >> p.set_z())
	{
		p.accetable_ = true;
	}
	else
	{
		p.accetable_ = false;
	}
	return in;
}
