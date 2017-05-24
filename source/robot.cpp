#include "robot.h"

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

void robot::service()
{
	if (isForwardKeyDown)
	{
		y = y - 1;
	}

	if (isBackwardKeyDown) 
	{
		y = y + 1;
	}
	
	if (isClockwiseKeyDown)
	{
		angle = angle + 1;

		if (angle >= 360)
		{
			angle = angle - 360;
		}
	}
}
