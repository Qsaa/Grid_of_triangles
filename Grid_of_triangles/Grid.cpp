#include "Grid.h"

Grid::Grid(double x_max, double x_min, double y_max, double y_min, double z_max, double z_min, size_t size, double density = 10.0)
{
	double delta;
		
	delta = (x_max - x_min) * 0.01;
	x_max_ = x_max + delta;
	x_min_ = x_min - delta;

	delta = (y_max - y_min) * 0.01;
	y_max_ = y_max + delta;
	y_min_ = y_min - delta;
	
	delta = (z_max - z_min) * 0.01;
	z_max_ = z_max + delta;
	z_min_ = z_min - delta;

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

	for (size_t i = 0; i <= n_x_; ++i)
	{
		boarder_x_.push_back(x_min_ + section_x_ * i);
	}

	for (size_t i = 0; i <= n_y_; ++i)
	{
		boarder_y_.push_back(x_min_ + section_x_ * i);
	}

	for (size_t i = 0; i <= n_z_; ++i)
	{
		boarder_z_.push_back(x_min_ + section_x_ * i);
	}

	data_.resize(n_x_ * n_y_ * n_z_);
}

void Grid::insert_point(ExtendPoint& point)
{
	auto [x, y, z] = get_cell_coordinates(point);
	size_t i = get_cell_number(x, y, z);

	point.set_cell(i);
	data_[i].push_back(&point);
}

std::vector<ExtendPoint*>& Grid::get_points_cell(size_t n_cell)
{
	return data_[n_cell];
}

std::tuple<size_t, size_t, size_t> Grid::get_cell_coordinates(const ExtendPoint& point) const
{
	size_t x = floor(((point.get_x() - x_min_) / section_x_));
	size_t y = floor(((point.get_y() - y_min_) / section_y_));
	size_t z = floor(((point.get_z() - z_min_) / section_z_));

	return {x, y, z};
}

std::tuple<size_t, size_t, size_t> Grid::get_cell_coordinates(size_t i) const
{
	size_t x = i / (n_z_ * n_y_);
	size_t y = (i % (n_z_ * n_y_) / n_z_);
	size_t z = i % n_z_;
	return {x, y, z};
}

size_t Grid::get_cell_number(size_t x, size_t y, size_t z) const
{
	// x y z
	return n_z_ * n_y_ * x + n_z_ * y + z;
}

std::ostream& operator<<(std::ostream& out, const Grid& grid)
{
	out << "Boarder of this Grid\n";
	out << "x_max: " << grid.x_max_<<"\n";
	out << "x_min: " << grid.x_max_<<"\n";
	out << "y_max: " << grid.y_max_<<"\n";
	out << "y_min: " << grid.y_min_<<"\n";
	out << "z_max: " << grid.z_max_<<"\n";
	out << "z_min: " << grid.z_min_<<"\n";

	out << "Number of cells:\n";
	out << "X: " << grid.n_x_ << "\n";
	out << "Y: " << grid.n_y_ << "\n";
	out << "Z: " << grid.n_z_ << "\n";

	out << "Lenght of each section:\n";
	out << "X: " << grid.section_x_ << "\n";
	out << "Y: " << grid.section_y_ << "\n";
	out << "Z: " << grid.section_z_ << "\n";

	size_t i = 0;
	size_t max = grid.data_[0].size();
	for (auto& vector_point : grid.data_)
	{
		out << "Cell number " << i << "\n";	
		for (auto pointer : vector_point)
		{
			out << *pointer << "\n";
		}
		out << "number of points: ";
		out << vector_point.size() << "\n";

		if (max < vector_point.size())
		{
			max = vector_point.size();
		}
		++i;
		break;
	}
	out << "Statictic:\n";
	out << "Maximum number of points per cell: " << max << "\n";
	out << "Number of cells: " << i << "\n";
	out << "---The end----" << "\n";
	return out;
}

