#include<iostream>
#include <SDL.h>
#include <string>
#include "inputHandler.h"
#include "scenes.h"
#include "sprites.h"
#include "textures.h"
#include "tiles.h"


int main(int argc, char *argv[]) {
	
	int width = 800;
	int height = 600;
	const int frameRate = 120;
	const std::string title = "STEMGAME";
	int mouseXPos;
	int mouseYPos;

	Uint32 startingtick;

	//initializes SDL
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *SDLWindow = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_RESIZABLE
	);
	SDL_Renderer *SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	player Jeff = player();
	inputHandler handler = inputHandler();

	//bound inputs should be specific to scene
	////////////////////////////////////////////////////////////////
	startUpCommand upStart = startUpCommand(&Jeff);
	startDownCommand downStart = startDownCommand(&Jeff);
	startLeftCommand leftStart = startLeftCommand(&Jeff);
	startRightCommand rightStart = startRightCommand(&Jeff);
	stopUpCommand upStop = stopUpCommand(&Jeff);
	stopDownCommand downStop = stopDownCommand(&Jeff);
	stopLeftCommand leftStop = stopLeftCommand(&Jeff);
	stopRightCommand rightStop = stopRightCommand(&Jeff);
	handler.bindWDown(&upStart);
	handler.bindSDown(&downStart);
	handler.bindADown(&leftStart);
	handler.bindDDown(&rightStart);
	handler.bindWUp(&upStop);
	handler.bindSUp(&downStop);
	handler.bindAUp(&leftStop);
	handler.bindDUp(&rightStop);
	/////////////////////////////////////////////////////////////////////////

	tileHandler tiles = tileHandler();
	textureHandler textures = textureHandler(SDLRenderer);
	mainScene scene = mainScene(SDLWindow, SDLRenderer, &tiles, &textures, width, height);

	while (!handler.getClosed()) {

		handler.handleInputs();

		scene.renderScene();


		//presents the stuff
		SDL_RenderPresent(SDLRenderer);
	}

	SDL_DestroyRenderer(SDLRenderer);
	SDL_DestroyWindow(SDLWindow);
	SDL_Quit();

	return 0;
}



/*
TO DO:

add error checking when starting up
add an error log

let each scene have a different control scheme
*/