#include "Matrix.h"

Matrix::Matrix(double x_max, double x_min, double y_max, double y_min, double z_max, double z_min, size_t size, double density = 10.0)
{
	x_max_ = x_max;
	x_min_ = x_min;

	y_max_ = x_max;
	y_min_ = y_min;
	
	z_max_ = x_max;
	z_min_ = z_min;

	// len is only positive
	double len_x = x_max_ - x_min_; 
	double len_y = y_max_ - y_min_;
	double len_z = z_max_ - z_min_;

	double k_x = (len_x * len_x) / (len_y * len_z);
	double k_y = (len_y * len_y) / (len_x * len_z);
	double k_z = (len_z * len_z) / (len_x * len_y);

	n_x_ = static_cast<size_t>(round(cbrt((static_cast<double>(size) / density) * k_x)));
	n_y_ = static_cast<size_t>(round(cbrt((static_cast<double>(size) / density) * k_y)));
	n_z_ = static_cast<size_t>(round(cbrt((static_cast<double>(size) / density) * k_z)));

	section_x_ = len_x / n_x_;
	section_y_ = len_y / n_y_;
	section_z_ = len_z / n_z_;

	data_.resize(n_x_ * n_y_ * n_z_);
}

std::tuple<size_t, size_t, size_t> Matrix::get_cell_coordinates(const ExtendPoint& point) const
{
	size_t x = floor(((x_min_ - point.get_x()) / section_x_));
	size_t y = floor(((y_min_ - point.get_y()) / section_y_));
	size_t z = floor(((z_min_ - point.get_z()) / section_z_));

	return {x, y, z};
}

std::tuple<size_t, size_t, size_t> Matrix::get_cell_coordinates(size_t i) const
{
	size_t x = i / (n_z_ * n_y_);
	size_t y = (i % (n_z_ * n_y_) / n_z_);
	size_t z = i % n_z_;
	return {x, y, z};
}


void Matrix::insert_point(ExtendPoint& point)
{
	auto [x, y, z] = get_cell_coordinates(point);
	size_t i = get_cell_number(x, y, z);

	point.set_pos(i);
	data_[i].push_back(&point);
}

size_t Matrix::get_cell_number(size_t x, size_t y, size_t z) const
{
	// x y z
	return n_z_ * n_y_ * x + n_z_ * y + n_z_;
}
