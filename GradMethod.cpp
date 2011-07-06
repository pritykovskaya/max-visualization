#include "stdafx.h"
#include "Method.h"
#include <string>
#include <math.h>

GradMethod::GradMethod (int _steps, double _eps_grad_abs, double _eps_point_change, double _start_change_coef, bool _is_for_gorge): 
numb_of_steps(_steps), 
eps_grad_abs(_eps_grad_abs), 
eps_point_change(_eps_point_change),
start_change_coef(_start_change_coef),
is_for_gorge(_is_for_gorge)
{}

GradMethod::~GradMethod(){}

int GradMethod::numb_of_start_points(){
	return 1;
}

string GradMethod::get_method_name(){
	return "Gradient method";
}

MethodResult GradMethod::search_process(Function* f, Area* area, vector < vector<double> > start_points) {
	int count_of_steps = 0;

	vector<double> cur_point;
	cur_point = start_points[0];
	
	vector < vector<double>> traj;
	traj.push_back(cur_point);

	double cur_coeff = start_change_coef;

	while(1) {
		if (count_of_steps > numb_of_steps) {
			return MethodResult(traj, "steps limit achived ");
		}
		if (cur_coeff <  eps_point_change) {
			return MethodResult(traj, "epsilon point change ");
		}

		vector<double> cur_grad = f -> calc_grad(cur_point);

		double grad_abs = 0;

		for (int i = 0; i < cur_grad.size(); ++i) {
			grad_abs += cur_grad[i] * cur_grad[i];
		}
		if (sqrt(grad_abs) < eps_grad_abs) {
			return MethodResult(traj, "epsilon grad abs ");
		}

		vector<double> next_point;
		for (int i = 0; i < cur_point.size(); ++i ) {
			next_point.push_back(cur_point[i] + cur_grad[i] * cur_coeff); 
		}

		for (int i = 0; i < next_point.size(); ++i) {
			if (next_point[i] < area->my_area[2*i]) {
				next_point[i] = area->my_area[2*i];
			}
			if (next_point[i] > area->my_area[2*i+1]) {
				next_point[i] = area->my_area[2*i+1];
			}
		}

		//bool flag;
		//if (area -> contain_point(next_point)) {
		//	flag = true;
		//}

		if ( (*f)(next_point) > (*f)(cur_point)) {
			traj.push_back(next_point);
			cur_point = next_point;
			
			if (is_for_gorge) {
				return MethodResult(traj, "");
			}
		} else {
			cur_coeff /= 2;
		}

		++count_of_steps;
	}
}

double GradMethod::get_eps_grad_abs() const {return eps_grad_abs;}
int GradMethod::get_numb_of_steps() const {return numb_of_steps;}
double GradMethod::get_eps_point_change() const {return eps_point_change;}
double GradMethod::get_start_change_coef() const {return start_change_coef;}


void GradMethod::set_eps_grad_abs(double _eps_grad_abs) {eps_grad_abs = _eps_grad_abs;}
void GradMethod::set_eps_point_change(double _eps_point_change) {eps_point_change = _eps_point_change;}
void GradMethod::set_numb_of_steps(int _numb_of_steps) {numb_of_steps = _numb_of_steps;}
void GradMethod::set_start_change_coef(double _start_change_coef) {start_change_coef = _start_change_coef;}