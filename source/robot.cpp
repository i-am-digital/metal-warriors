#include "robot.h"
#include <cmath>

bool robot::moveForward()
{
	return false;
}

int robot::getX()
{
	return x;
}

int robot::getY()
{
	return y;
}

double robot::getRotation()
{
	return angle;
}

void robot::startMovingForward()
{
	isForwardKeyDown = true;
}

void robot::startMovingBackward()
{
	isBackwardKeyDown = true;
}

void robot::startRotatingClockwise()
{
	isClockwiseKeyDown = true;
}

void robot::startRotatingAnticlockwise()
{
	isAnticlockwiseKeyDown = true;
}

void robot::stopMovingForward()
{
	isForwardKeyDown = false;
}

void robot::stopMovingBackward()
{
	isBackwardKeyDown = false;
}

void robot::stopRotatingClockwise()
{
	isClockwiseKeyDown = false;
}

void robot::stopRotatingAnticlockwise()
{
	isAnticlockwiseKeyDown = false;
}

void robot::fire()
{
	playerBullet.fire(x, y, angle);
}

void robot::service()
{
	playerBullet.service();

	if (isForwardKeyDown)
	{
		double radians = (angle * 2 * 3.142) / 360;
		x = x + sin(radians);
		y = y - cos(radians);
	}

	if (isBackwardKeyDown) 
	{
		double radians = (angle * 2 * 3.142) / 360;
		x = x - sin(radians);
		y = y + cos(radians);
	}
	
	if (isClockwiseKeyDown)
	{
		angle = angle + 1;

		if (angle >= 360)
		{
			angle = angle - 360;
		}
	}
	if (isAnticlockwiseKeyDown)
	{
		angle = angle - 1;
		if (angle < 0)
		{
			angle = angle + 360;
		}
	}
}
