#include "stdafx.h"
#include "Method.h"
#include "R32M.H"



vector< vector<double> > Method::single_element_vector(vector<double> v) {
	vector< vector<double> > vv;
	vv.push_back(v);
	return vv;
}
RandomMethod::RandomMethod (int _steps, double _eps, double _p, int bsteps): 
numb_of_steps(_steps), 
my_eps(_eps), 
p_fall_inside_bound(_p),
my_fail_steps(bsteps) 
{}


string RandomMethod::get_method_name() {
	return "Random method";
}

int RandomMethod::numb_of_start_points() {
	return 1;
}

void RandomMethod::set_steps(int steps) {numb_of_steps = steps;}
void RandomMethod::set_epsilon(double eps) {my_eps = eps;}
void RandomMethod::set_p(double p) {p_fall_inside_bound = p;}
void RandomMethod::set_fail_steps(int fail_steps) {my_fail_steps = fail_steps;}

int RandomMethod::get_steps() const {return numb_of_steps;}
double RandomMethod::get_epsilon() const {return my_eps;}
double RandomMethod::get_p() const {return p_fall_inside_bound;}
int RandomMethod::get_fail_steps() const {return my_fail_steps;}

RandomMethod::~RandomMethod() {}

vector<double> RandomMethod::next_step(Area* area, vector<double> point)
{
	double x, rand_numb;
	int dim = area -> get_dim();
	vector <double> res;
	res.reserve(dim);

	rand_numb = rnunif();
	if (rand_numb < p_fall_inside_bound)
	{
		for (int i = 0; i < dim; ++i)
		{
			x = rnunif() * 2 * my_eps + point[i] - my_eps;
			if (x >= area -> my_area[2*i]  &&  x <= area -> my_area[2*i+1]) res.push_back(x);
			else 
			{
				if (x < area -> my_area[2*i])
					res.push_back(area -> my_area[2*i]);
				if (x > area -> my_area[2*i+1])
					res.push_back(area -> my_area[2*i+1]);
			}
		}
	}
	else
	{
		for (int i = 0; i < dim; ++i)
		{
			x = rnunif() * (area -> my_area[2*i+1] - area -> my_area[2*i]) + area -> my_area[2*i];
			res.push_back(x);
		}
	}
	return res;
}


MethodResult RandomMethod::search_process(Function* f, Area* area, vector< vector<double> > start_points){

	string s;
	vector<double> start_point = start_points[0];
	vector <double> cur_point(start_point);
	vector <double> next_point;
	next_point.reserve(start_point.size());

	vector< vector<double> > cur_traj;
	cur_traj.push_back(start_point);

	int step_count = 0;
	int fail_step_count = 0;

	while (1)
	{
		next_point = next_step(area, cur_point);
		if ((*f)(next_point) > (*f)(cur_point))
		{
			cur_traj.push_back(next_point);
			cur_point = next_point;
			fail_step_count = 0;
		}
		else
		{
			++fail_step_count;
			if (fail_step_count >= my_fail_steps)
			{
				s = "fail steps limit achived";
				break;
			}
		}
		++step_count;
		if (step_count > numb_of_steps) 
		{
			s = "steps limit achived";
			break;
		}
	}


	return MethodResult(cur_traj, s);
}
