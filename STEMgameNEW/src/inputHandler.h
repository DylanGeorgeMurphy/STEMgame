#pragma once
#include<sdl.h>
#include<iostream>
#include"sprites.h"

class command {
public:
	virtual ~command() {};
	virtual void execute() {};
};


class controlScheme {
public:
	controlScheme();
	~controlScheme();
	command* wDown;
	command* sDown;
	command* aDown;
	command* dDown;
	command* wUp;
	command* sUp;
	command* aUp;
	command* dUp;
	command* eDown;
	command* leftMouseDown;
	command* leftMouseUp;
};

class inputHandler {
public:
	inputHandler();
	void handleInputs();
	bool getClosed();
	bool getFullscreen();
	int getMouseXPos();
	int getMouseYPos();
	void setControls(controlScheme*);
private:
	controlScheme* controls;
	int xPos, yPos;
	bool closed;
	bool fullscreen;
};

