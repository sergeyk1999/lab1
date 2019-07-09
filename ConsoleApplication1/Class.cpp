#include <iostream>
#include "Class.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#define step M_PI/180
#define eps 1e-6
void Plane::SetVelocity(double velocity) { velocity_ = velocity; }
double Plane::GetVelocity() { return velocity_; }
void Plane::SetCourse(double course) { course_ = course; }
double Plane::GetCourse() { return course_; }
void Plane::SetX(double x) { x_ = x; }
double Plane::GetX() { return x_; }
void Plane::SetY(double y) { y_ = y; }
double Plane::GetY() { return y_; }
void Plane::Move(double delta,double time)
{
	x_ += f1(delta);//f1
	y_ += f2(delta);//f2
	velocity_ += f3(delta, time);
	if (velocity_ <= 0) velocity_ = 0;
}
void Plane::Print(const char* name,double time, double D, double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %i %lf %lf %lf %lf %lf\n", "Plane ",num_, x_, y_, velocity_, course_, time);
	fclose(fp);
}
double Plane::f1(double delta)
{
	return velocity_ * cos(course_) * delta;
}
double Plane::f2(double delta)
{
	return velocity_ * sin(course_) * delta;
}
double Plane::f3(double delta,double time)
{
	double c = 1;
	double p = 1;
	double pl = 1;
	double s = 1;
	double dm = 0.001;
	double m = 5;
	double critm = 1;
	double mcurr = m - time * dm;
	if (mcurr >= critm) return -((p - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
	else return -((p * mcurr / critm - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
}
int Plane::GetNum() { return num_; }
void Plane::SetNum(int num) { num_ = num; }
void Missle::SetVelocity(double velocity) { velocity_ = velocity; }
double Missle::GetVelocity() { return velocity_; }
void Missle::SetCourse(double course) { course_ = course; }
double Missle::GetCourse() { return course_; }
void Missle::SetX(double x) { x_ = x; }
double Missle::GetX() { return x_; }
void Missle::SetY(double y) { y_ = y; }
double Missle::GetY() { return y_; }
void Missle::SetAcceleration(double acceleration) { acceleration_ = acceleration; }
double Missle::GetAcceleration() { return acceleration_; }
void Missle::Move(double delta,double time)
{
	x_ += f1(delta);//f1
	y_ += f2(delta);//f2
	velocity_ += f3(delta,time);
	if (velocity_ <= 0) velocity_ = 0;
}
void Missle::Print(const char* name, double time,double D,double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %i %lf %lf %lf %lf %lf %lf\n", "Missle ",num_, x_, y_, velocity_, course_, acceleration_, time);
	fclose(fp);
}
double Missle::f1(double delta)
{
	return (velocity_ + acceleration_ * delta / 2) * cos(course_) * delta;
}
double Missle::f2(double delta)
{
	return (velocity_ + acceleration_ * delta / 2) * sin(course_) * delta;
}
double Missle::f3(double delta, double time)
{
	double c = 1;
	double p = 1;
	double pl = 1;
	double s = 1;
	double dm = 0.001;
	double m = 5;
	double critm = 1;
	double mcurr = m - time * dm;
	if (mcurr >= critm) return (acceleration_-(p - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
	else return (acceleration_-(p * mcurr / critm - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
}
int Missle::GetNum() { return num_; }
void Missle::SetNum(int num) { num_ = num; }
void AD_Missle::SetX(double x) { x_ = x; }
double AD_Missle::GetX() { return x_; }
void AD_Missle::SetY(double y) { y_ = y; }
double AD_Missle::GetY() { return y_; }
void AD_Missle::Move(double delta, double time)
{
	x_ += f1(delta);//f1
	y_ += f2(delta);//f2
	velocity_ += f3(delta, time);
	if (velocity_ <= 0) velocity_ = 0;
}
void AD_Missle::DefineCourse(TAircraft* target)
{
	double new_course;
	if ((fabs(x_ - target->GetX()) < eps))
	{
		if (target->GetY() > y_) new_course = M_PI / 2;
		else new_course = -M_PI / 2;
	}
	else if (fabs(y_ - target->GetY()) < eps)
	{
		if (target->GetX() >= x_) new_course = 0;
		else new_course = M_PI;
	}
	else if (target->GetX() > x_) new_course = atan((target->GetY() - y_) / (target->GetX() - x_));
	else new_course = atan((target->GetY() - y_) / (target->GetX() - x_)) + M_PI;
	course_ = new_course;
}
void AD_Missle::Print(const char* name, double time, double D, double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %i %lf %lf %lf %lf %lf %lf\n", "AD_Missle ",num_, x_, y_, velocity_, course_, acceleration_, time);
	fclose(fp);
}
double AD_Missle::f1(double delta)
{
	return (velocity_ + acceleration_ * delta / 2) * cos(course_) * delta;
}
double AD_Missle::f2(double delta)
{
	return (velocity_ + acceleration_ * delta / 2) * sin(course_) * delta;
}
double AD_Missle::f3(double delta,double time)
{
	double c = 1;
	double p = 1;
	double pl = 1;
	double s = 1;
	double dm = 0.001;
	double m = 5;
	double critm = 1;
	double mcurr = m - time * dm;
	if (mcurr >= critm) return (acceleration_-(p - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
	else return (acceleration_-(p * mcurr / critm - c * velocity_ * velocity_ * pl * s / 2) / mcurr)*delta;
}
void AD_Missle::SetVelocity(double velocity) { velocity_ = velocity; }
double AD_Missle::GetVelocity() { return velocity_; }
void AD_Missle::SetCourse(double course) { course_ = course; }
double AD_Missle::GetCourse() { return course_; }
int AD_Missle::GetNum() { return num_; }
void AD_Missle::SetNum(int num) { num_ = num; }