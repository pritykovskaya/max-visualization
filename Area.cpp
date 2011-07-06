#include "stdafx.h"
#include "Area.h"
#include <vector>

Area:: Area(){
	
	my_dim = 2;
	my_area.reserve(2*my_dim);
	for (int i = 0; i < my_dim; ++i)
	{
		my_area.push_back(-10);
		my_area.push_back(10);
	}
};

int Area::get_dim() {return my_dim;}

Area::~Area() {};

bool Area::contain_point(vector<double> point){
	for (int i = 0; i < my_dim ; ++i) {
		if (point[i] < my_area[2 * i] || point[i] > my_area[2 * i + 1]) {
			return false;
		}
	}
	return true;
};