#ifndef BULLET_H
#define BULLET_H
#include "target.h"
class bullet
{

private:
	double x{ 200 };
	double y{ 200 };
	double angle{ 25 };
	bool isDisplayed{ false };
	double speed{ 5 };
	target* balloon{ nullptr };



public:
	int getX();
	int getY();
	double getRotation();
	void service();
	bool getDisplayed();
	void fire(int x, int y, double angle);
	void setTarget(target* balloon);


};
#endif