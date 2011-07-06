#include "stdafx.h"
#include "MethodResult.h"

MethodResult::MethodResult(std::vector<vector<double> > trajectory, std::string s):
my_trajectory(trajectory),
reason_of_stop(s) 
{}

MethodResult::MethodResult(){}
MethodResult::~MethodResult(){}
vector<double> MethodResult::get_last_point() {
	return my_trajectory[my_trajectory.size() - 1];
}

