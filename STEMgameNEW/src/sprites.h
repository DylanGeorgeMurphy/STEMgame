#pragma once
#include<iostream>

class sprite {
public:
	float xPos, yPos;
	float getXPos();
	float getYPos();
	void translate(float, float);
};

class player : public sprite {
public:
	bool movingUp, movingDown, movingLeft, movingRight;
	void update();
	int getXTile();
	int getYTile();
	float getXOff();
	float getYOff();
private:
	float vel = 0.1;
};

