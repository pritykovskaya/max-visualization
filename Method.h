#ifndef _METHOD_
#define _METHOD_

#include <string>
#include <vector>
#include <list>
#include "Function.h"
#include "Area.h"
#include "MethodResult.h"
using namespace std;

class Method {
public:
	virtual string get_method_name() = 0;
	virtual	MethodResult search_process(Function* f, Area* area, vector < vector<double> > start_points) = 0;
	virtual int numb_of_start_points() = 0;
	vector< vector<double> > single_element_vector (vector<double> v);
	
};

class RandomMethod: public Method {
protected:

	int numb_of_steps; 
	double my_eps; 
	double p_fall_inside_bound; 
	int my_fail_steps; 
	
	vector<double> next_step(Area* area, vector <double> point);
public:
	RandomMethod (int _steps, double _eps, double _p, int bsteps);
	
	virtual MethodResult search_process(Function* f, Area* area, vector < vector<double> > start_points); 
	virtual string get_method_name();
	virtual int numb_of_start_points();

	void set_steps(int steps);
	void set_epsilon(double eps);
	void set_p(double p);
	void set_fail_steps(int fail_steps);

	int get_steps() const;
	double get_epsilon() const;
	double get_p() const;
	int get_fail_steps() const;

	~RandomMethod();
};

class GradMethod: public Method {
protected:

	int numb_of_steps; 
	double eps_grad_abs; 
	double eps_point_change;
	double start_change_coef;
	bool is_for_gorge;

public:
	GradMethod (int _steps, double _eps_grad_abs, double _eps_point_change, double _start_change_coef, bool _is_for_gorge);
	
	virtual MethodResult search_process(Function* f, Area* area, vector < vector<double> > start_points); 
	virtual string get_method_name();
	virtual int numb_of_start_points();

	void set_numb_of_steps(int _numb_of_steps);
	void set_eps_grad_abs(double _eps_grad_abs);
	void set_eps_point_change(double _eps_point_change);
	void set_start_change_coef(double _start_change_coef);

	int get_numb_of_steps() const;
	double get_eps_grad_abs() const;
	double get_eps_point_change() const;
	double get_start_change_coef() const;

	~GradMethod();
};

class GorgeMethod: public Method {
protected:

	GradMethod grad_method;
	int numb_of_steps; 
	double eps_point_change;
	double gorge_coef;
	double get_difference_length(vector<double> v1, vector<double> v2);
public:
	GorgeMethod (GradMethod _grad, int _numb_of_steps, double _eps_point_change, double _gorge_coef);
	
	void set_numb_of_steps(int _numb_of_steps);
	void set_eps_point_change(double _eps_point_change);
	void set_gorge_coef(double _gorge_coef);

	int get_numb_of_steps() const;
	double get_eps_point_change () const;
	double get_gorge_coef() const;

	virtual MethodResult search_process(Function* f, Area* area, vector < vector<double> > start_points); 
	virtual string get_method_name();
	virtual int numb_of_start_points();

	~GorgeMethod();
};


#endif