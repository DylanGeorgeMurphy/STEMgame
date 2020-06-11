#include"mainscene.h"

//////////
#include<iostream>

mainScene::mainScene(SDL_Window* window, SDL_Renderer* renderer, textureHandler* textures, int width, int height, int* mouseX, int* mouseY) :
	window(window),
	renderer(renderer),
	width(width),
	height(height),
	textures(textures),
	controls(new controlScheme()),
	overworld(new map()),
	mouseXPos(mouseX),
	mouseYPos(mouseY)
{
	windows = new windowHandler(textures, renderer);
	currentPlayer = new player(overworld);
	controls->wDown = new startUpCommand(currentPlayer);
	controls->sDown = new startDownCommand(currentPlayer);
	controls->aDown = new startLeftCommand(currentPlayer);
	controls->dDown = new startRightCommand(currentPlayer);
	controls->wUp = new stopUpCommand(currentPlayer);
	controls->sUp = new stopDownCommand(currentPlayer);
	controls->aUp = new stopLeftCommand(currentPlayer);
	controls->dUp = new stopRightCommand(currentPlayer);
	controls->eDown = new addWindowCommand(windows);
	controls->leftMouseDown = new clickCommand(windows);
	controls->leftMouseUp = new unClickCommand(windows);
};

mainScene::~mainScene() {
	delete windows;
	delete controls;
	delete overworld;
	delete currentPlayer;
}
void mainScene::renderTile(int x, int y, int ID) {
	SDL_Rect tile;
	tile.x = x;
	tile.y = y + (-15 * overworld->getLayer(ID));
	//width and height have a padding of 1 pixel to stop line gaps
	tile.w = tileSize+1;
	tile.h = (tileSize + overworld->getHeight(ID) * 15) + 1;
	SDL_RenderCopy(renderer, textures->getTexture(overworld->getTextureName(ID)), NULL, &tile);
};

void mainScene::renderScene() {

	currentPlayer->update();
	windows->updateWindows(*mouseXPos, *mouseYPos);

	//cameras position
	int xPos = currentPlayer->getXTile() - (width/tileSize)/2;
	int yPos = currentPlayer->getYTile() - (height / tileSize) / 2;
	float xOff = currentPlayer->getXOff();
	float yOff = currentPlayer->getYOff();


	//draws tiles
	for (int y = -2; y < (height / tileSize) + 2; y++) {
		for (int x = 0; x < (width / tileSize) + 1; x++) {
			int tileID = overworld->getTile(x + xPos, y + yPos);
			renderTile((x*tileSize) - (xOff*tileSize), (y*tileSize) - (yOff*tileSize), tileID);
		}
	}

	//draws the player
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(renderer,
			width / 2 - 10,
			height / 2 - 10,
			width / 2 + 10,
			height / 2 + 10
		);
		SDL_RenderDrawLine(renderer,
			width / 2 - 10,
			height / 2 + 10,
			width / 2 + 10,
			height / 2 - 10
		);
	}

	windows->showWindows();
};

controlScheme* mainScene::getControls() {
	return(controls);
}

void startUpCommand::execute() {target->movingUp = true;}
startUpCommand::startUpCommand(player* p) :target(p) {};

void startDownCommand::execute() {target->movingDown = true;}
startDownCommand::startDownCommand(player* p) :target(p) {};

void startLeftCommand::execute() {target->movingLeft = true;}
startLeftCommand::startLeftCommand(player* p) :target(p) {};

void startRightCommand::execute() {target->movingRight = true;}
startRightCommand::startRightCommand(player* p) :target(p) {};

void stopUpCommand::execute() {target->movingUp = false;}
stopUpCommand::stopUpCommand(player* p) :target(p) {};

void stopDownCommand::execute() {target->movingDown = false;}
stopDownCommand::stopDownCommand(player* p) :target(p) {};

void stopLeftCommand::execute() {target->movingLeft = false;}
stopLeftCommand::stopLeftCommand(player* p) :target(p) {};

void stopRightCommand::execute() {target->movingRight = false;}
stopRightCommand::stopRightCommand(player* p) :target(p) {};

void addWindowCommand::execute() { target->addWindow(); };
addWindowCommand::addWindowCommand(windowHandler* p) :target(p) {};

void clickCommand::execute() {
	windows->windowClicked();
};
clickCommand::clickCommand(windowHandler* w) : windows(w){};

void unClickCommand::execute() {
	windows->windowUnClicked();
};
unClickCommand::unClickCommand(windowHandler* w) : windows(w) {};