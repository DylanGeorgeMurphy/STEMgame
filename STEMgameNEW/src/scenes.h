#pragma once
#include"tiles.h"
#include"textures.h"
#include"map.h"
#include"inputHandler.h"
#include<sdl.h>


class mainScene {
public:
	mainScene(SDL_Window*, SDL_Renderer*, tileHandler*, textureHandler*, int, int);
	~mainScene();
	void renderTile(int x, int y, int ID);
	void renderScene();
	controlScheme* getControls();
private:
	player* currentPlayer;
	controlScheme* controls;
	SDL_Window* window;
	SDL_Renderer* renderer;
	textureHandler* textures;
	tileHandler* tiles;
	map* overworld;
	int width;
	int height;
	int tileSize = 30;
};

///////////////////////////////////////////////

class testCommand :public command {
public:
	virtual void execute() {
		std::cout << "test" << std::endl;
	}
};

////////////////////////////////

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