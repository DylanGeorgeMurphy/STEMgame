#pragma once
#include<sdl.h>
#include<iostream>
#include"sprites.h"

class command {
public:
	virtual ~command() {};
	virtual void execute() = 0;
};


class startUpCommand : public command {
public:
	virtual void execute();
	startUpCommand(player*);
private:
	player* target;
};

class startDownCommand : public command {
public:
	virtual void execute();
	startDownCommand(player*);
private:
	player* target;
};

class startLeftCommand : public command {
public:
	virtual void execute();
	startLeftCommand(player*);
private:
	player* target;
};

class startRightCommand : public command {
public:
	virtual void execute();
	startRightCommand(player*);
private:
	player* target;
};

class stopUpCommand : public command {
public:
	virtual void execute();
	stopUpCommand(player*);
private:
	player* target;
};

class stopDownCommand : public command {
public:
	virtual void execute();
	stopDownCommand(player*);
private:
	player* target;
};

class stopLeftCommand : public command {
public:
	virtual void execute();
	stopLeftCommand(player*);
private:
	player* target;
};

class stopRightCommand : public command {
public:
	virtual void execute();
	stopRightCommand(player*);
private:
	player* target;
};

class inputHandler {
public:
	inputHandler();
	void handleInputs();
	void bindWDown(command*);
	void bindSDown(command*);
	void bindADown(command*);
	void bindDDown(command*);
	void bindWUp(command*);
	void bindSUp(command*);
	void bindAUp(command*);
	void bindDUp(command*);
	bool getClosed();
private:
	command* wDown;
	command* sDown;
	command* aDown;
	command* dDown;
	command* wUp;
	command* sUp;
	command* aUp;
	command* dUp;
	bool closed;
};

