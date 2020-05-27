#include"textures.h"

//////////
#include<iostream>

textureHandler::textureHandler(SDL_Renderer *renderer) :SDLRenderer(renderer) {
	loadTextures();
}

void textureHandler::loadTextures() {
	SDL_Surface* surface;
	surface = IMG_Load("Textures\\Default");

	std::experimental::filesystem::path folder{ "Textures" };
	for (auto& entry : std::experimental::filesystem::directory_iterator(folder)) {
		std::string name = entry.path().filename().string();

		if (std::experimental::filesystem::path(name).extension() == ".png") {
			//loads it an a surface
			surface = IMG_Load(("Textures\\" + name).c_str());
			//converts it to a texture
			textures[name.substr(0, name.find_last_of("."))] = SDL_CreateTextureFromSurface(SDLRenderer, surface);
		}

	}



	SDL_FreeSurface(surface);

}

SDL_Texture* textureHandler::getTexture(std::string name) {
	return(textures[name]);
}