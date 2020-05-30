#include"scenes.h"

mainScene::mainScene(SDL_Window* window, SDL_Renderer* renderer, tileHandler* tiles, textureHandler* textures, int width, int height) :
	window(window),
	renderer(renderer),
	width(width),
	height(height),
	tiles(tiles),
	textures(textures),
	controls(new controlScheme()),
	overworld(new map()),
	currentPlayer(new player())
{
	controls->wDown = new startUpCommand(currentPlayer);
	controls->sDown = new startDownCommand(currentPlayer);
	controls->aDown = new startLeftCommand(currentPlayer);
	controls->dDown = new startRightCommand(currentPlayer);
	controls->wUp = new stopUpCommand(currentPlayer);
	controls->sUp = new stopDownCommand(currentPlayer);
	controls->aUp = new stopLeftCommand(currentPlayer);
	controls->dUp = new stopRightCommand(currentPlayer);

};

mainScene::~mainScene() {
	delete controls;
	delete overworld;
	delete currentPlayer;
}

void mainScene::renderTile(int x, int y, int ID) {
	SDL_Rect tile;
	tile.x = x;
	tile.y = y + (-15 * tiles->getLayer(ID));
	tile.w = tileSize;
	tile.h = tileSize + tiles->getHeight(ID) * 15;
	SDL_RenderCopy(renderer, textures->getTexture(tiles->getTextureName(ID)), NULL, &tile);
};

void mainScene::renderScene() {

	currentPlayer->update();

	int xPos = currentPlayer->getXTile();
	int yPos = currentPlayer->getYTile();
	float xOff = currentPlayer->getXOff();
	float yOff = currentPlayer->getYOff();

	for (int y = -2; y < (height / tileSize) + 1.0; y++) {
		for (int x = 0; x < (width / tileSize) + 1.0; x++) {
			int tileID = overworld->getTile(x + xPos, y + yPos);
			renderTile((x*tileSize) - (xOff*tileSize), (y*tileSize) - (yOff*tileSize), tileID);
		}
	}
};

controlScheme* mainScene::getControls() {
	return(controls);
}



void startUpCommand::execute() {
	target->movingUp = true;
}
startUpCommand::startUpCommand(player* p) :target(p) {};

void startDownCommand::execute() {
	target->movingDown = true;
}
startDownCommand::startDownCommand(player* p) :target(p) {};

void startLeftCommand::execute() {
	target->movingLeft = true;
}
startLeftCommand::startLeftCommand(player* p) :target(p) {};

void startRightCommand::execute() {
	target->movingRight = true;
}
startRightCommand::startRightCommand(player* p) :target(p) {};

void stopUpCommand::execute() {
	target->movingUp = false;
}
stopUpCommand::stopUpCommand(player* p) :target(p) {};

void stopDownCommand::execute() {
	target->movingDown = false;
}
stopDownCommand::stopDownCommand(player* p) :target(p) {};

void stopLeftCommand::execute() {
	target->movingLeft = false;
}
stopLeftCommand::stopLeftCommand(player* p) :target(p) {};

void stopRightCommand::execute() {
	target->movingRight = false;
}
stopRightCommand::stopRightCommand(player* p) :target(p) {};