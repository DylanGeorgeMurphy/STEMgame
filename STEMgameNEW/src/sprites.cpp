#include"sprites.h"

float sprite::getXPos() {return(xPos);}

float sprite::getYPos() {return(yPos);}

void sprite::translate(float x, float y) {
	xPos += x;
	yPos += y;
}

void player::update() { 
	if (movingUp) {
		if (mapPointer->getSolid(mapPointer->getTile(floor(xPos), floor(yPos - 0.1))) == false)yPos -= vel;
	};

	if (movingDown) {
		if (mapPointer->getSolid(mapPointer->getTile(floor(xPos), floor(yPos + 0.1))) == false)yPos += vel;
	};

	if (movingLeft) {
		if (mapPointer->getSolid(mapPointer->getTile(floor(xPos - 0.1), floor(yPos))) == false)xPos -= vel;
	};

	if (movingRight) {
		if (mapPointer->getSolid(mapPointer->getTile(floor(xPos + 0.1), floor(yPos))) == false)xPos += vel;
	};
};


int player::getXTile() {
	return(floor(xPos));
}

int player::getYTile() {
	return(floor(yPos));
}

float player::getXOff() {
	return(xPos-floor(xPos));
}

float player::getYOff() {
	return(yPos-floor(yPos));
}

player::player(map* m) :mapPointer(m) {
	xPos = -20;
	yPos = 0;
};


