#include "stdafx.h"
#include "Method.h"
#include <string>
#include <math.h>



GorgeMethod::GorgeMethod(GradMethod _grad, int _numb_of_steps, double _eps_point_change, double _gorge_coef):
grad_method(_grad),
numb_of_steps(_numb_of_steps),
eps_point_change(_eps_point_change),
gorge_coef(_gorge_coef)
{}


GorgeMethod::~GorgeMethod(){}

int GorgeMethod::numb_of_start_points(){
	return 2;
}

string GorgeMethod::get_method_name(){
	return "Gorge method";
}



double GorgeMethod::get_difference_length(vector<double> v1, vector<double> v2){
	double vector_length = 0;
		
	for (int i = 0; i < v1.size(); ++i) {
		vector_length += (v1[i] - v2[i]) * (v1[i] - v2[i]);
	}
	return sqrt(vector_length);
}

MethodResult GorgeMethod::search_process(Function* f, Area* area, vector < vector<double> > start_points) {
	vector< vector<double>> traj;
	traj.push_back(start_points[0]);
	vector<double> prev = grad_method.search_process(f, area, single_element_vector(start_points[0])).get_last_point();
	//traj.push_back(prev);

	traj.push_back(start_points[1]);
	vector<double> cur = grad_method.search_process(f, area, single_element_vector(start_points[1])).get_last_point();
	//traj.push_back(cur);

	int count_steps = 0;
	double cur_gorge_coef = gorge_coef;

	while(1) {
		if (count_steps > numb_of_steps ) {
			return MethodResult(traj, "step limit is achived");
		}
		if ( get_difference_length(traj[traj.size() - 1], traj[traj.size() - 2]) < eps_point_change) {
			return MethodResult(traj, "coordinate shift less than epsilon");
		}
		vector<double> next;
		
		if (get_difference_length(prev, cur) < eps_point_change) {
			if ((*f)(prev) > (*f)(cur)) {
				traj.push_back(prev);
			} else {
				traj.push_back(cur);
			}

			return MethodResult(traj, "coordinate shift less than epsilon");
		}

		double coef = 1 / get_difference_length(prev, cur);
		coef = coef * cur_gorge_coef;
		if ((*f)(cur) -(*f)(prev) < 0) {
			coef *= -1;
		}	
		
		for (int i = 0; i < cur.size(); ++i) {
			next.push_back(cur[i] + coef * (cur[i] - prev[i]));
		}

		if (!area -> contain_point(next)) {
			if ((*f)(prev) > (*f)(cur)) {
				traj.push_back(prev);
			} else {
				traj.push_back(cur);
			}

			return MethodResult(traj, "Out of area");
		}
		traj.push_back(next);
		prev = cur;
		cur = grad_method.search_process(f, area, single_element_vector(next)).get_last_point();
		//traj.push_back(cur);
		++count_steps;
	}

}

double GorgeMethod::get_eps_point_change() const {return eps_point_change;}
double GorgeMethod::get_gorge_coef() const {return gorge_coef;}
int GorgeMethod::get_numb_of_steps() const {return numb_of_steps;}

void GorgeMethod::set_numb_of_steps(int _numb_of_steps) { numb_of_steps = _numb_of_steps;}
void GorgeMethod::set_eps_point_change(double _eps_point_change) { eps_point_change = _eps_point_change;}
void GorgeMethod::set_gorge_coef(double _gorge_coef) { gorge_coef = _gorge_coef;}

