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

void robot::startMovingForward()
{
	isForwardKeyDown = true;
}

void robot::startMovingBackward()
{
	isBackwardKeyDown = true;
}

void robot::stopMovingForward()
{
	isForwardKeyDown = false;
}

void robot::stopMovingBackward()
{
	isBackwardKeyDown = false;
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
	
}
