#include "ExtendPoint.h"

ExtendPoint::ExtendPoint(): Point(), number_(0), accetable_(false) {}

std::istream& ExtendPoint::set(std::istream& in)
{
	char common;
	in >> number_ >> common >> set_x()>> common >> set_y()>> common >> set_z();
	accetable_ = true;
	return in;
}

void ExtendPoint::print() const
{
	std::cout << (*this);
}

std::ostream& operator<<(std::ostream& out, const ExtendPoint& p)
{
	return out << "Number: " << p.number_ << " Accateble: " << p.accetable_ << " Point: " << 
		p.get_x() << " " << p.get_y() << ' ' << p.get_z();
}

std::istream& operator>>(std::istream& in, ExtendPoint& p)
{
	//!!!!  а что если данные не корректные
	char common;
	if (in >> p.number_ >> common >> p.set_x() >> common >> p.set_y() >> common >> p.set_z())
	{
		p.accetable_ = true;
	}
	else
	{
		p.accetable_ = false;
	}
	return in;
}
