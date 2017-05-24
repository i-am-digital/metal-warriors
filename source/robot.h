#ifndef ROBOT_H
#define ROBOT_H

class robot
{
private:
	int x{ 50 };
	int y{ 100 };
	bool isForwardKeyDown{ false };
	bool isBackwardKeyDown{ false };
	bool moveForward();
	bool moveBackward();

public:
	int getX();
	int getY();
	void startMovingForward();
	void startMovingBackward();
	void stopMovingForward();
	void stopMovingBackward();
	void service();



};
#endif
