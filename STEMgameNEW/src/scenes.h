#pragma once
#include"tiles.h"
#include"textures.h"
#include"map.h"
#include<sdl.h>

class mainScene {
public:
	mainScene(SDL_Window*, SDL_Renderer*, tileHandler*, textureHandler*, int, int);
	void renderTile(int x, int y, int ID);
	void renderScene();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	textureHandler* textures;
	tileHandler* tiles;
	map* overworld;
	int width;
	int height;
	int tileSize = 30;
};
