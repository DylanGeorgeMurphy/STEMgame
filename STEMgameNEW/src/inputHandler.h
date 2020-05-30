#pragma once
#include<sdl.h>
#include<iostream>
#include"sprites.h"

class command {
public:
	virtual ~command() {};
	virtual void execute() = 0;
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
};

class inputHandler {
public:
	inputHandler();
	void handleInputs();
	bool getClosed();
	void setControls(controlScheme*);
private:
	controlScheme* controls;
	bool closed;
};

