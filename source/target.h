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
private:
	double x{ 200 };
	double y{ 200 };
};

#endif // TARGET_H
