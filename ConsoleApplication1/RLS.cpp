#include "RLS.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#define eps 1e-6
#define eps_c 1e-2
void RLS::SetFileName(const char* name) { name_ = name; }
void RLS::peleng()
{
	double D,az;
	bool buf=0;
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
				else if (i->GetX() > x_) {az = atan((i->GetY() - y_) / (i->GetX() - x_));}
				else {az = atan((i->GetY() - y_) / (i->GetX() - x_)) + M_PI;}
				for (auto j : attack_list_)
				{
					if (j->GetNum() == i->GetNum())
						buf = 1;
				}
				if (buf == 0)
				{
					AD_Missle* missle = new AD_Missle();
					missle->SetX(x_);
					missle->SetY(y_);
					missle->SetNum(i->GetNum());
					attack_list_.push_back(missle);
				}
				for (auto j : attack_list_)
				{
					if (j->GetNum() == i->GetNum())
					{
						if ((fabs(i->GetX() - j->GetX()) < eps_c * rad_) && (fabs(i->GetY() - j->GetY()) < eps_c * rad_) &&(i->GetVelocity()!=0))
						{
							PrintRes(i->GetNum());
							i->SetVelocity(0);
							j->SetVelocity(0);
						}
						if (i->GetVelocity() == 0) {j->SetVelocity(0);}
						j->DefineCourse(i);
						if(j->GetVelocity()>eps) {j->Print(name_, time_, 0, 0);}
						j->Move(delta_,time_);
					}
				}
				if (i->GetVelocity() > eps) {i->Print(name_,time_,D,az );}
			}
			if (i->GetVelocity() > eps) {i->Move(delta_,time_);}
			buf = 0;
		}
	time_ += delta_;
}
void RLS::SetX(double x) { x_ = x; }
double RLS::GetX() { return x_; }
void RLS::SetY(double y) { y_ = y; }
double RLS::GetY() { return y_; }
void RLS::SetDelta(double delta) { delta_ = delta; }
void RLS::SetRad(double rad) { rad_ = rad; }
void RLS::PrintRes(int i)
{
	FILE* fp;
	fp = fopen(name_, "a");
	fprintf(fp, "Target num %d is destroyed\n", i);
	fclose(fp);
}
//void RLS::SetTimeMax(double time_max) { time_max_ = time_max; }
