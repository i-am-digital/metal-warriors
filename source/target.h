#ifndef TARGET_H
#define TARGET_H

/*
destroy on hit
display on screen
-texture
-image
-location
*/

class target
{
public:
	int getX();
	int getY();
	bool hasBeenHit(int bulletX, int bulletY);
	bool getVisible();

private:
	double x{ 200 };
	double y{ 200 };
	int radius{ 50 };
	bool visible{ true };
};

#endif // TARGET_H
