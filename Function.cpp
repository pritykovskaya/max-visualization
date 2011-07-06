#include "stdafx.h"
#include "Function.h"
#include <vector>
#include <math.h>


const double Function::h = 0.0001;

vector<double> Function::calc_grad(vector<double> point) {
	vector<double> res;
	for (int i = 0; i < get_dimension(); ++i) {
		point[i] += h;
		double plus_h = calc_value(point);

		point[i] -= 2*h;
		double minus_h = calc_value(point);
		
		res.push_back( (plus_h - minus_h) / (2*h));
		point[i] += h;
	}
	return res;
}

double Function::operator ()(const vector <double> point) {
	return calc_value(point);	
}

double TwoArgumentFunction::operator ()(const double x, const double y) {
	return calc_value(x, y);	
}

double TwoArgumentFunction::calc_value(const vector <double> points) {
	return calc_value(points[0], points[1]);
}

int TwoArgumentFunction::get_dimension() const {
	return 2;
}

Function_1::Function_1() {}
Function_1::~Function_1() {}

Function_2::Function_2() {}
Function_2::~Function_2() {}

Function_3::Function_3() {}
Function_3::~Function_3() {}

Function_4::Function_4() {}
Function_4::~Function_4() {}

string Function_1::get_formula() const {
	return "x*y";
};


double Function_1::calc_value(const double x, const double y) { 
	return (x*y);
};


string Function_2::get_formula () const {
	return "x*x + y*y";
};


double Function_2::calc_value(const double x, const double y) {
	return (x*x + y*y);
};

string Function_3::get_formula () const{
	return "sin(x)*cos(x) + sin(y)*cos(y)";
};


double Function_3::calc_value(const double x, const double y)
{
	return sin(x)*cos(x) + sin(y)*cos(y);
};


string Function_4::get_formula () const {
	return "-(sqrt(300*(y^2+(x+1)^2))-20)^2+250*y-5*x)";
};

double Function_4::calc_value(const double x, const double y)
{
	return -((sqrt(300*(y*y+(x+1)*(x+1)))-20)*(sqrt(300*(y*y+(x+1)*(x+1)))-100)+250*y-5*x);
};