#pragma once
#include <iostream>
#include "Class.h"
#include <vector>
using namespace std;
class RLS
{
private:
	double x_;
	double y_;
	double time_max_;
	double delta_;
	double rad_;
	const char* name_;
	vector<TAircraft*> list_;
public:
	~RLS() = default;
	void peleng();
	RLS() = default;
	void SetFileName(const char* name);
	void SetX(double x);
	void SetY(double y);
	double GetX();
	double GetY();
	void SetRad(double rad);
	void SetTimeMax(double time_max);
	void SetDelta(double delta);
	void SetList(vector<TAircraft*> list) { list_ = list; }
};

