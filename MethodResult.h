#ifndef _RESULT_
#define _RESULT_

#include <vector>
#include <list>
#include <string>
using namespace std;

class MethodResult{
public:
	MethodResult();
	MethodResult(vector < vector<double> > trajectory, string s);
	vector < vector<double> > my_trajectory;
	string reason_of_stop;
	vector<double> get_last_point();
	~MethodResult();

};
#endif