//Dylan Murphy 2020

#include<iostream>
#include <SDL.h>
#include <string>
#include "inputHandler.h"
#include "mainscene.h"
#include "textures.h"

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
	textureHandler textures = textureHandler(SDLRenderer);
	mainScene scene = mainScene(SDLWindow, SDLRenderer, &textures, width, height, &mouseXPos, &mouseYPos);

	handler.setControls(scene.getControls());


	//game loop
	while (!handler.getClosed()) {

		Uint32 startingTick = SDL_GetTicks();

		//clears screen
		SDL_SetRenderDrawColor(SDLRenderer, 255, 0, 0, 255);
		SDL_RenderClear(SDLRenderer);

		//does keyboard controls
		handler.handleInputs();

		//gets the mouse position
		mouseXPos = handler.getMouseXPos();
		mouseYPos = handler.getMouseYPos();

		renderScene(&scene);

		if ((1000 / frameRate) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / frameRate - (SDL_GetTicks() - startingTick));
		};

		SDL_RenderPresent(SDLRenderer);
	}

	SDL_DestroyRenderer(SDLRenderer);
	SDL_DestroyWindow(SDLWindow);
	SDL_Quit();

	return 0;
}


/*
TO DO:

allow for the player to stand behind a block/sprite

allow for correct window resizing

change the chunk cache so that it is no longer cyclical
change the chunk cache system so that it can have variable cache size
*/