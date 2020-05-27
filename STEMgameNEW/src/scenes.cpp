#include"scenes.h"

mainScene::mainScene(SDL_Window* window, SDL_Renderer* renderer, tileHandler* tiles, textureHandler* textures, int width, int height) :
	window(window),
	renderer(renderer),
	width(width),
	height(height),
	tiles(tiles),
	textures(textures)
{
	overworld = new map();
};

void mainScene::renderTile(int x, int y, int ID) {
	SDL_Rect tile;
	tile.x = x;
	tile.y = y + (-15 * tiles->getLayer(ID));
	tile.w = tileSize;
	tile.h = tileSize + tiles->getHeight(ID) * 15;
	SDL_RenderCopy(renderer, textures->getTexture(tiles->getTextureName(ID)), NULL, &tile);
};


void mainScene::renderScene() {
	for (int y = -2; y < height / tileSize + 1; y++) {
		for (int x = 0; x < width / tileSize + 1; x++) {
			int tileID = overworld->getTile(x, y);
			renderTile((x*tileSize), (y*tileSize), tileID);
		}
	}
};
