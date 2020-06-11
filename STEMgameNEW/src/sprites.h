#pragma once
#include<iostream>
#include "map.h"

class sprite {
public:
	float xPos, yPos;
	float getXPos();
	float getYPos();
	void translate(float, float);
};

class player : public sprite {
public:
	player(map* m);
	bool movingUp, movingDown, movingLeft, movingRight;
	void update();
	int getXTile();
	int getYTile();
	float getXOff();
	float getYOff();
private:
	float vel = 0.05;
	map* mapPointer;
};

