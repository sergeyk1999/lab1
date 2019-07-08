#include <vector>
#include <iostream>
#include "Class.h"
#include "RLS.h"
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
double deg_rad(double deg);
int main(void)
{
	const char* name = "a.txt";
	int i, j, k;
	double x, y, acceleration, velocity, course,rad,time_max,delta;
	FILE* fp;
	fp = fopen(name, "w");
	//fprintf(fp, "type x_coord y_coord velocity course accel time\n");
	fclose(fp);
	vector <TAircraft*> list;
	printf("enter number of planes and missles\n");
	cin >> i >> j;
	for (k = 0; k < i; k++)
	{
		cout << "enter velocity, course, x and y for plane\n";
		cin >> velocity >> course >> x >> y;
		Plane* plane = new Plane();
		plane->SetVelocity(velocity);
		course = deg_rad(course);
		plane->SetCourse(course);
		plane->SetX(x);
		plane->SetY(y);
		list.push_back(plane);
	}
	for (k = 0; k < j; k++)
	{
		cout << "enter velocity, course, acceleration, x and y for plane\n";
		cin >> velocity >> course >> acceleration >> x >> y;
		Missle* missle = new Missle();
		course = deg_rad(course);
		missle->SetVelocity(velocity);
		missle->SetCourse(course);
		missle->SetX(x);
		missle->SetY(y);
		missle->SetAcceleration(acceleration);
		list.push_back(missle);
	}
	cout << "enter x, y, rad, time_max and delta for RLS\n";
	cin >> x >> y >> rad >> time_max >> delta;
	RLS* rls = new RLS();
	rls->SetFileName(name);
	rls->SetDelta(delta);
	rls->SetRad(rad);
	rls->SetX(x);
	rls->SetY(y);
	rls->SetTime(0);
	rls->SetList(list);
	while (rls->GetTime() <= time_max)
	{
		rls->peleng();
	}
	for (auto i : list)
	{
		delete i;
	}
	delete rls;
	return 0;
}
double deg_rad(double deg)
{
	return deg * M_PI / 180;
}
