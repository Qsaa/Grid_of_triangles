#include "Matrix.h"

Matrix::Matrix(double x_max, double x_min, double y_max, double y_min, double z_max, double z_min, size_t size, double density = 10.0)
{
	double len_x = x_max - x_min;
	double len_y = y_max - y_min;
	double len_z = z_max - z_min;

	double k_x = (len_x * len_x) / (len_y * len_z);
	double k_y = (len_y * len_y) / (len_x * len_z);
	double k_z = (len_z * len_z) / (len_x * len_y);

	size_t n_x = round(cbrt((static_cast<double>(size) / density) * k_x));
	size_t n_y = round(cbrt((static_cast<double>(size) / density) * k_y));
	size_t n_z = round(cbrt((static_cast<double>(size) / density) * k_z));

	data_.resize(n_x * n_y * n_z);
}

void Matrix::insert_point(ExtendPoint* point)
{
	int x;
	int y;
	int z;
	data_[1].push_back(point);
}
