#include "target.h"

int target::getX()
{
	return static_cast<int>(x);
}

int target::getY()
{
	return static_cast<int>(y);
}

bool target::hasBeenHit(int bulletX, int bulletY)
{
	if (visible)
	{
		int xDifference = getX() - bulletX;
		int yDifference = getY() - bulletY;
		int squaredDistance = (xDifference * xDifference) + (yDifference * yDifference);
		int squaredRadius = (radius * radius);
		if (squaredDistance < squaredRadius)
		{
			visible = false;
			return true;
		}
	}
	return false;
}

bool target::getVisible()
{
	return visible;
}
