#include "bullet.h"
#include <cmath>

int bullet::getX()
{
	return x;
}
int bullet::getY()
{
	return y;
}
double bullet::getRotation()
{
	return 0.0;
}
void bullet::service()
{
	if (isDisplayed)
	{
		double radians = (angle * 2 * 3.142) / 360;
		x = x + sin(radians) * speed;
		y = y - cos(radians) * speed;

		if (balloon != nullptr && balloon->hasBeenHit(getX(), getY()))
		{
			isDisplayed = false;
		}
		
	}
}

bool bullet::getDisplayed()
{
	return isDisplayed;
}

void bullet::fire(int x, int y, double angle)
{
	this->x = x;
	this->y = y;
	this->angle = angle;

	isDisplayed = true;
}

void bullet::setTarget(target* balloon)
{
	this->balloon = balloon;
}

