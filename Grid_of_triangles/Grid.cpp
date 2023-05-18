#include "Grid.h"

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
	len_section_x_ = len_x / n_cell_x_;
	len_section_y_ = len_y / n_cell_y_;
	len_section_z_ = len_z / n_cell_z_;

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
					(boarder_.x_min_ + (i_x	   ) * len_section_x_),		// x_min
					(boarder_.x_min_ + (i_x + 1) * len_section_x_),		// x_max
					(boarder_.y_min_ + (i_y	   ) * len_section_y_),		// y_max
					(boarder_.y_min_ + (i_y + 1) * len_section_y_),		// y_min
					(boarder_.z_min_ + (i_z    ) * len_section_z_),		// z_max
					(boarder_.z_min_ + (i_z + 1) * len_section_z_)		// z_min
					);
				++n;
			}
		}
	}
}


void Grid::insert_point(ExtendPoint& point)
{
	size_t i = get_the_cell_number(point);
	data_[i].add_extend_point(&point);
}

size_t Grid::get_the_cell_number(const ExtendPoint& point) const
{
	return convert_from_xyz_to_i(
		floor(((point.get_x() - boarder_.x_min_) / len_section_x_)), // position by x
		floor(((point.get_y() - boarder_.y_min_) / len_section_y_)), // position by y
		floor(((point.get_z() - boarder_.z_min_) / len_section_z_))  // position by z
	);
}

size_t Grid::convert_from_xyz_to_i(size_t x, size_t y, size_t z) const
{
	return n_cell_z_ * n_cell_y_ * x + n_cell_z_ * y + z;
}

std::tuple<size_t, size_t, size_t> Grid::convert_from_i_to_xyz(size_t i) const
{
	size_t x = i / (n_cell_z_ * n_cell_y_);
	size_t y = (i % (n_cell_z_ * n_cell_y_) / n_cell_z_);
	size_t z = i % n_cell_z_;
	return {x, y, z};
}

void Grid::print_short()
{
	std::cout << "Boarder of this Grid\n";
	std::cout << "x_max: " << boarder_.x_max_ << "\n";
	std::cout << "x_min: " << boarder_.x_min_ << "\n";
	std::cout << "y_max: " << boarder_.y_max_ << "\n";
	std::cout << "y_min: " << boarder_.y_min_ << "\n";
	std::cout << "z_max: " << boarder_.z_max_ << "\n";
	std::cout << "z_min: " << boarder_.z_min_ << "\n";

	std::cout << "Number of cells:\n";
	std::cout << "X: " << n_cell_x_ << "\n";
	std::cout << "Y: " << n_cell_y_ << "\n";
	std::cout << "Z: " << n_cell_z_ << "\n";
	std::cout << "All: " << data_.size() << "\n";

	std::cout << "Lenght of each section:\n";
	std::cout << "X: " << len_section_x_ << "\n";
	std::cout << "Y: " << len_section_y_ << "\n";
	std::cout << "Z: " << len_section_z_ << "\n";
}

void Grid::print()
{
	print_short();

	if (!data_.empty())
	{
		size_t max = data_[0].get_points().size();
		size_t min = max;

		for (auto& cell : data_)
		{
			if (max < cell.get_points().size())
			{
				max = cell.get_points().size();
			}
			if (min > cell.get_points().size())
			{
				min = cell.get_points().size();
			}
		}
		std::cout << "Maximum number of points in one cell: " << max << "\n";
		std::cout << "Minimun number of points in one cell: " << min << "\n";
	}
	else
	{
		std::cout << "There isn't any cell in grid" << "\n";
	}
}

void Grid::print_full()
{
	print_short();

	if (!data_.empty())
	{
		size_t max = data_[0].get_points().size();
		size_t min = max;

		//cell.print();
		//std::cout << cell << "\n";

		for (auto& cell : data_)
		{
			if (max < cell.get_points().size())
			{
				max = cell.get_points().size();
			}
			if (min > cell.get_points().size())
			{
				min = cell.get_points().size();
			}
		}
		std::cout << "Maximum number of points in one cell: " << max << "\n";
		std::cout << "Minimun number of points in one cell: " << min << "\n";
	}
	else
	{
		std::cout << "There isn't any cell in grid" << "\n";
	}
}

std::ostream& operator<<(std::ostream& out, const Grid& grid)
{
	out << "Boarder of this Grid\n";
	out << "x_max: " << grid.boarder_.x_max_ << "\n";
	out << "x_min: " << grid.boarder_.x_min_ << "\n";
	out << "y_max: " << grid.boarder_.y_max_ << "\n";
	out << "y_min: " << grid.boarder_.y_min_ << "\n";
	out << "z_max: " << grid.boarder_.z_max_ << "\n";
	out << "z_min: " << grid.boarder_.z_min_ << "\n";

	out << "Number of cells:\n";
	out << "X: " << grid.n_cell_x_ << "\n";
	out << "Y: " << grid.n_cell_y_ << "\n";
	out << "Z: " << grid.n_cell_z_ << "\n";
	out << "All: " << grid.data_.size() << "\n";

	out << "Lenght of each section:\n";
	out << "X: " << grid.len_section_x_ << "\n";
	out << "Y: " << grid.len_section_y_ << "\n";
	out << "Z: " << grid.len_section_z_ << "\n";

	if (!grid.data_.empty())
	{
		size_t max = grid.data_[0].get_points().size();
		size_t min = max;

		for (auto& cell : grid.data_)
		{
			if (max < cell.get_points().size())
			{
				max = cell.get_points().size();
			}
			if (min > cell.get_points().size())
			{
				min = cell.get_points().size();
			}
		}
		out << "Maximum number of points in one cell: " << max << "\n";
		out << "Minimun number of points in one cell: " << min << "\n";
	}
	else
	{
		out << "There isn't any cell in grid" << "\n";
	}
	out << "---The end----" << "\n";
	return out;
}


