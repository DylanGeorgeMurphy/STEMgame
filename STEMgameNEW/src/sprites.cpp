#include"sprites.h"

float sprite::getXPos() {return(xPos);}

float sprite::getYPos() {return(yPos);}

void sprite::translate(float x, float y) {
	xPos += x;
	yPos += y;
}

void player::update() { 
	if (movingUp)yPos -= vel;
	if (movingDown)yPos += vel;
	if (movingLeft)xPos -= vel;
	if (movingRight)xPos += vel;
};


