#ifndef _AREA_
#define _AREA_
#include <vector>
using namespace std;

class Area{
private:
	int my_dim;
public:
	int get_dim();
	vector<double> my_area;
	Area();
	~Area();
	bool contain_point(vector<double> point);
};
#endif