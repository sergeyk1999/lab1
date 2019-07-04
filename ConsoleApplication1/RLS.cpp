#include "RLS.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#define eps 1e-16
void RLS::SetFileName(const char* name) { name_ = name; }
void RLS::peleng()
{
	double time,D,az;
	for (time = 0; time < time_max_; time += delta_)
	{
		for (auto i : list_)
		{
			D = sqrt((x_ - i->GetX()) * (x_ - i->GetX()) + (y_ - i->GetY()) * (y_ - i->GetY()));
			if (D<=rad_)
			{
				if ((fabs(x_ - i->GetX()) < eps))
				{
					if (i->GetY ()> y_) az = M_PI / 2;
					else az = -M_PI / 2;
				}
				else if (fabs(y_ - i->GetY()) < eps)
				{
					if (i->GetX() >= x_) az = 0;
					else az = M_PI;
				}
				else if (i->GetX() > x_) az = atan((i->GetY() - y_) / (i->GetX() - x_));
				else az = atan((i->GetY() - y_) / (i->GetX() - x_)) + M_PI;
				i->Print(name_,time,D,az );
			}
			i->Move(delta_);
		}
	}
}
void RLS::SetX(double x) { x_ = x; }
double RLS::GetX() { return x_; }
void RLS::SetY(double y) { y_ = y; }
double RLS::GetY() { return y_; }
void RLS::SetDelta(double delta) { delta_ = delta; }
void RLS::SetRad(double rad) { rad_ = rad; }
void RLS::SetTimeMax(double time_max) { time_max_ = time_max; }
