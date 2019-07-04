#pragma once
#include <iostream>
//enum typeoftarget { a, b };
using namespace std;
class TAircraft
{
public:
	TAircraft() = default;
	~TAircraft() = default;
	virtual void SetVelocity(double velocity) = 0;
	virtual double GetVelocity() = 0;
	virtual void SetCourse(double course) = 0;
	virtual double GetCourse() = 0;
	virtual void SetX(double x) = 0;
	virtual double GetX() = 0;
	virtual void SetY(double y) = 0;
	virtual double GetY() = 0;
	virtual void Move(double time) = 0;
	virtual void Print(const char *name,double time,double D,double az) = 0;
};

class Plane :public TAircraft
{
public:
	virtual void SetVelocity(double velocity) override;
	virtual double GetVelocity() override;
	virtual void SetCourse(double course) override;
	virtual double GetCourse() override;
	virtual void SetX(double x) override;
	virtual double GetX() override;
	virtual void SetY(double y) override;
	virtual double GetY() override;
	virtual void Move(double time) override;
	virtual void Print(const char *name,double time,double D,double az) override;
	Plane() = default;
	~Plane() = default;
	//typeoftarget type = a;
private:
	double velocity_;
	double course_;
	double x_;
	double y_;
};

class Missle : public TAircraft
{
public:
	virtual void SetVelocity(double velocity) override;
	virtual double GetVelocity() override;
	virtual void SetCourse(double course) override;
	virtual double GetCourse() override;
	virtual void SetX(double x) override;
	virtual double GetX() override;
	virtual void SetY(double y) override;
	virtual double GetY() override;
	virtual void SetAcceleration(double acceleration);
	virtual double GetAcceleration();
	virtual void Move(double time) override;
	virtual void Print(const char* name,double time,double D,double az) override;
	Missle() = default;
	~Missle() = default;
	//typeoftarget type = b;
private:
	double velocity_;
	double course_;
	double x_;
	double y_;
	double acceleration_;
};



