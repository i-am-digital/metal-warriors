#ifndef ROBOT_H
#define ROBOT_H

class robot
{
private:
	int x{ 50 };
	int y{ 100 };
	double angle{ 0 };
	bool isForwardKeyDown{ false };
	bool isBackwardKeyDown{ false };
	bool isClockwiseKeyDown{ false };
	bool moveForward();
	bool moveBackward();
	

public:
	int getX();
	int getY();
	double getRotation();
	void startMovingForward();
	void startMovingBackward();
	void startRotatingClockwise();
	void stopMovingForward();
	void stopMovingBackward();
	void stopRotatingClockwise();
	void service();



};
#endif
