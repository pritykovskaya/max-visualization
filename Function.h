#ifndef _FUNCTION_
#define _FUNCTION_

#include <string>
#include <vector>
using namespace std;

class Function {
protected:
	static const double h;

public:
    virtual double calc_value(const vector <double> points) = 0;
	
	virtual vector<double> calc_grad(vector<double> point);
	virtual double operator ()(const vector <double> point);

    virtual int get_dimension () const = 0;
    virtual string get_formula() const = 0;

};

class TwoArgumentFunction: public Function {
public:
	virtual double calc_value (const double x, const double y) = 0; 
	virtual double operator ()(const double x, const double y);

	virtual int get_dimension () const;
	virtual double calc_value(const vector <double> points);
};

class Function_1: public TwoArgumentFunction
{
public:
	Function_1();
	virtual double calc_value (const double x, const double y);
	virtual string get_formula() const;
	~Function_1();
};

class Function_2: public TwoArgumentFunction
{
public:
	Function_2();
	virtual double calc_value (const double x, const double y);
	virtual string get_formula() const;
	~Function_2();
};


class Function_3:public TwoArgumentFunction
{
public:
	Function_3();
	virtual double calc_value (const double x, const double y);
	virtual string get_formula() const;
	~Function_3();
};


class Function_4:public TwoArgumentFunction
{
public:
	Function_4();
	virtual double calc_value (const double x, const double y);
	virtual string get_formula() const;
	~Function_4();
};
#endif