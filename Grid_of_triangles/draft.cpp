//for (auto& el : points)
//{
//	cout << el << endl;
//}
//cout << endl;
//double len_x = x_max - x_min;
//double len_y = y_max - y_min;
//double len_z = z_max - z_min;

//cout << "x_max: " << x_max << "   x_min: " << x_min << " __ " << x_max - x_min << endl;
//cout << "y_max: " << y_max << "   y_min: " << y_min << " __ " << y_max - y_min << endl;
//cout << "z_max: " << z_max << "   z_min: " << z_min << " __ " << z_max - z_min << endl;

//double k_x = (len_x * len_x) / (len_y * len_z);
//double k_y = (len_y * len_y) / (len_x * len_z);
//double k_z = (len_z * len_z) / (len_x * len_y);

//size_t n_x = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_x));
//size_t n_y = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_y));
//size_t n_z = round(cbrt((static_cast<double>(points.size()) / DENSITY) * k_z));


//vector<ExtendPoint*> p_sort_by_x;
//ExtendPoint* p;
//for (auto& el : points)
//{
//	p = &el;
//	p_sort_by_x.push_back(p);
//}
//sort(begin(p_sort_by_x), end(p_sort_by_x), ExtendPoint::compare_by_x);
//cout << "______________________X_______________" << endl;
//for (auto p : p_sort_by_x)
//{
//	cout << *p << endl;
//}

//vector<ExtendPoint*> p_sort_by_y;
//for (auto& el : points)
//{
//	p = &el;
//	p_sort_by_y.push_back(p);
//}
//cout << "______________________Y_______________" << endl;
//sort(begin(p_sort_by_y), end(p_sort_by_y), ExtendPoint::compare_by_y);
//for (auto p : p_sort_by_y)
//{
//	cout << *p << endl;
//}
//cout << endl;


//vector<ExtendPoint*> p_sort_by_z;
//for (auto& el : points)
//{
//	p = &el;
//	p_sort_by_z.push_back(p);
//}

//cout << "______________________Z_______________" << endl;
//
//sort(begin(p_sort_by_z), end(p_sort_by_z), ExtendPoint::compare_by_z);
//for (auto p : p_sort_by_z)
//{
//	cout << *p << endl;
//}
//cout << endl;

//ExtendPoint* closest_p = get_closest_point_nn(points[0], points.begin() + 1, points.end());
//cout << "Point_ "<<points[0]<< " _the closest: "<< *closest_p << endl;