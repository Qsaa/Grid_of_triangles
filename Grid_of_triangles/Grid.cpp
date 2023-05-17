#include "Grid.h"

std::ostream& operator<<(std::ostream& out, const Grid& grid)
{
	out << "Boarder of this Grid\n";
	out << "x_max: " << grid.boarder_.x_max_<<"\n";
	out << "x_min: " << grid.boarder_.x_max_<<"\n";
	out << "y_max: " << grid.boarder_.y_max_<<"\n";
	out << "y_min: " << grid.boarder_.y_min_<<"\n";
	out << "z_max: " << grid.boarder_.z_max_<<"\n";
	out << "z_min: " << grid.boarder_.z_min_<<"\n";

	out << "Number of cells:\n";
	out << "X: " << grid.n_cell_x_ << "\n";
	out << "Y: " << grid.n_cell_y_ << "\n";
	out << "Z: " << grid.n_cell_z_ << "\n";

	out << "Lenght of each section:\n";
	out << "X: " << grid.section_x_ << "\n";
	out << "Y: " << grid.section_y_ << "\n";
	out << "Z: " << grid.section_z_ << "\n";

	//size_t i = 0;
	//size_t max = grid.data_[0].size();
	//for (auto& vector_point : grid.data_.get_points())
	//{
	//	out << "Cell number " << i << "\n";	
	//	for (auto pointer : vector_point)
	//	{
	//		out << *pointer << "\n";
	//	}
	//	out << "number of points: ";
	//	out << vector_point.size() << "\n";

	//	if (max < vector_point.size())
	//	{
	//		max = vector_point.size();
	//	}
	//	++i;
	//	break;
	//}
	out << "Statictic:\n";
	//out << "Maximum number of points per cell: " << max << "\n";
	//out << "Number of cells: " << i << "\n";
	out << "---The end----" << "\n";
	return out;
}


Grid::Grid(const Rectangular_Prallelepiped& boarder, size_t number_of_points, double density = 10.0)
{
	// increasing on margin error the boarder of this grid
	double delta;
	delta = (boarder.x_max_ - boarder.x_min_) * 0.01;
	boarder_.x_max_ = boarder.x_max_ + delta;
	boarder_.x_min_ = boarder.x_min_ - delta;

	delta = (boarder.y_max_ - boarder.y_min_) * 0.01;
	boarder_.y_max_ = boarder.y_max_ + delta;
	boarder_.y_min_ = boarder.y_min_ - delta;
	
	delta = (boarder.z_max_ - boarder.z_min_) * 0.01;
	boarder_.z_max_ = boarder.z_max_ + delta;
	boarder_.z_min_ = boarder.z_min_ - delta;

	// lenght of this grid, can be only positive
	double len_x = boarder_.x_max_ - boarder_.x_min_;
	double len_y = boarder_.y_max_ - boarder_.y_min_;
	double len_z = boarder_.z_max_ - boarder_.z_min_;

	//getting a coefficient to make each cell a cube
	double k_x = (len_x * len_x) / (len_y * len_z);
	double k_y = (len_y * len_y) / (len_x * len_z);
	double k_z = (len_z * len_z) / (len_x * len_y);

	//number of section by x, y, z
	n_cell_x_ = static_cast<size_t>(round(cbrt((static_cast<double>(number_of_points) / density) * k_x)));
	n_cell_y_ = static_cast<size_t>(round(cbrt((static_cast<double>(number_of_points) / density) * k_y)));
	n_cell_z_ = static_cast<size_t>(round(cbrt((static_cast<double>(number_of_points) / density) * k_z)));

	// lenght of section by x, y, z
	section_x_ = len_x / n_cell_x_;
	section_y_ = len_y / n_cell_y_;
	section_z_ = len_z / n_cell_z_;

	// define number of cells
	//data_.reserve(n_x_ * n_y_ * n_z_); ???
	data_.resize(n_cell_x_ * n_cell_y_ * n_cell_z_);

	int n = 0;
	for (size_t i_x = 0; i_x < n_cell_x_; ++i_x)
	{
		for (size_t i_y = 0; i_y < n_cell_y_; ++i_y)
		{
			for (size_t i_z = 0; i_z < n_cell_z_; ++i_z)
			{
				data_[n].set_i(n);
				//data_[n].set_i_xyz(x, y, z);
				data_[n].set_i_xyz(XYZ_number(i_x, i_y, i_z));
				data_[n].set_boarder(
					(boarder_.x_min_ + i_x * section_x_),		// x_min
					(boarder_.x_min_ + (i_x + 1) * section_x_), // x_max
					(boarder_.y_min_ + i_y * section_y_),		// y_max
					(boarder_.y_min_ + (i_y + 1) * section_y_), // y_min
					(boarder_.z_min_ + i_z * section_z_),		// z_max
					(boarder_.z_min_ + (i_z + 1) * section_z_)  // z_min
					);
				++n;
			}
		}
	}
}


void Grid::insert_point(ExtendPoint& point)
{
	//auto [x, y, z] = get_cell_coordinates(point);
	//size_t i = get_cell_number(x, y, z);

	//point.set_cell(i);
	////data_[i].push_back(&point);
	//data_[i].add_extend_point(&point);
}

//std::vector<ExtendPoint*>& Grid::get_points_cell(size_t n_cell)
//{
//	return data_[n_cell];
//}
//
//std::tuple<size_t, size_t, size_t> Grid::get_cell_coordinates(const ExtendPoint& point) const
//{
//	size_t x = floor(((point.get_x() - x_min_) / section_x_));
//	size_t y = floor(((point.get_y() - y_min_) / section_y_));
//	size_t z = floor(((point.get_z() - z_min_) / section_z_));
//
//	return {x, y, z};
//}
//
//std::tuple<size_t, size_t, size_t> Grid::get_cell_coordinates(size_t i) const
//{
//	size_t x = i / (n_z_ * n_y_);
//	size_t y = (i % (n_z_ * n_y_) / n_z_);
//	size_t z = i % n_z_;
//	return {x, y, z};
//}
//
//size_t Grid::get_cell_number(size_t x, size_t y, size_t z) const
//{
//	// x y z
//	return n_z_ * n_y_ * x + n_z_ * y + z;
//}
