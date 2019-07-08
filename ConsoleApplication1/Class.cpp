#include <iostream>
#include "Class.h"
#include <math.h>
#include <stdio.h>
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
	x_ += velocity_ * cos(course_) * delta;
	y_ += velocity_ * sin(course_) * delta;
	velocity_ -= f3(velocity_, time);
}
void Plane::Print(const char* name,double time, double D, double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %lf %lf %lf %lf %lf\n", "Plane ", x_, y_, velocity_, course_, time);
	fclose(fp);
}
double Plane::f3(double v,double time)
{
	double c = 1;
	double p = 1;
	double pl = 1;
	double s = 1;
	double dm = 0.001;
	double m = 5;
	double critm = 1;
	double mcurr = m - time * dm;
	if (mcurr >= critm) return (p - c * v * v * pl * s / 2) / mcurr;
	else return (p * mcurr / critm - c * v * v * pl * s / 2) / mcurr;
}
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
	x_ += (velocity_ + acceleration_ * delta / 2) * cos(course_) * delta;
	y_ += (velocity_ + acceleration_ * delta / 2) * sin(course_) * delta;
	velocity_ += acceleration_ * delta-f3(velocity_,time);
}
void Missle::Print(const char* name, double time,double D,double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %lf %lf %lf %lf %lf %lf\n", "Missle ", x_, y_, velocity_, course_, acceleration_, time);
	fclose(fp);
}
double Missle::f3(double v, double time)
{
	double c = 1;
	double p = 1;
	double pl = 1;
	double s = 1;
	double dm = 0.001;
	double m = 5;
	double critm = 1;
	double mcurr = m - time * dm;
	if (mcurr >= critm) return (p - c * v * v * pl * s / 2) / mcurr;
	else return (p * mcurr / critm - c * v * v * pl * s / 2) / mcurr;
}