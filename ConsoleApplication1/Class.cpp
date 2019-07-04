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
void Plane::Move(double time)
{
	x_ += velocity_ * cos(course_) * time;
	y_ += velocity_ * sin(course_) * time;
}
void Plane::Print(const char* name,double time, double D, double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %lf %lf %lf %lf %lf\n", "Plane ", x_, y_, velocity_, course_, time);
	fclose(fp);
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
void Missle::Move(double time)
{
	x_ += (velocity_ + acceleration_ * time / 2) * cos(course_) * time;
	y_ += (velocity_ + acceleration_ * time / 2) * sin(course_) * time;
	velocity_ += acceleration_ * time;
}
void Missle::Print(const char* name, double time,double D,double az)
{
	FILE* fp;
	fp = fopen(name, "a");
	fprintf(fp, "%s %lf %lf %lf %lf %lf %lf\n", "Missle ", x_, y_, velocity_, course_, acceleration_, time);
	fclose(fp);
}