#pragma once
#include<sdl.h>
#include<map>
#include<SDL_image.h>
#include<string>
#include<filesystem>

class textureHandler {
private:
	SDL_Renderer *SDLRenderer = nullptr;
	std::map<std::string, SDL_Texture*> textures;
public:
	//loads all the textures from a file
	void loadTextures();
	textureHandler(SDL_Renderer*);

	SDL_Texture* getTexture(std::string);
};