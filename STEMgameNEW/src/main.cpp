#include<iostream>
#include <SDL.h>
#include <string>
#include "inputHandler.h"
#include "scenes.h"
#include "textures.h"
#include "tiles.h"

template<class T>
void renderScene(T* target) {
	target->renderScene();
}

int main(int argc, char *argv[]) {
	
	int width = 1920;
	int height = 1080;
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
		SDL_WINDOW_FULLSCREEN
	);
	SDL_Renderer *SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	inputHandler handler = inputHandler();

	tileHandler tiles = tileHandler();
	textureHandler textures = textureHandler(SDLRenderer);
	mainScene scene = mainScene(SDLWindow, SDLRenderer, &tiles, &textures, width, height);

	handler.setControls(scene.getControls());


	//game loop
	while (!handler.getClosed()) {

		Uint32 startingTick = SDL_GetTicks();

		SDL_SetRenderDrawColor(SDLRenderer, 255, 0, 0, 255);
		SDL_RenderClear(SDLRenderer);

		handler.handleInputs();

		renderScene(&scene);

		if ((1000 / frameRate) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / frameRate - (SDL_GetTicks() - startingTick));
		};

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