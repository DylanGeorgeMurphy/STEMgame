#include"inputHandler.h"


void inputHandler::handleInputs() {
	SDL_Event event;
	while(SDL_PollEvent(&event)!=0) {

		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_w:
				controls->wDown->execute();
				break;
			case SDLK_s:
				controls->sDown->execute();
				break;
			case SDLK_a:
				controls->aDown->execute();
				break;
			case SDLK_d:
				controls->dDown->execute();
				break;
			case SDLK_e:
				controls->eDown->execute();
				break;
			case SDLK_F4:
				fullscreen = (fullscreen?false:true);
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_w:
				controls->wUp->execute();
				break;
			case SDLK_s:
				controls->sUp->execute();
				break;
			case SDLK_a:
				controls->aUp->execute();
				break;
			case SDLK_d:
				controls->dUp->execute();
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				controls->leftMouseDown->execute();
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				controls->leftMouseUp->execute();
			}
			break;

		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&xPos, &yPos);
			break;

		case SDL_QUIT:
			closed = true;
			break;
		}
	}
}

void inputHandler::setControls(controlScheme* c) {
	controls = c;
}

inputHandler::inputHandler() : closed(false), fullscreen(false), xPos(0), yPos(0) {}

bool inputHandler::getClosed() { return closed; }
bool inputHandler::getFullscreen() { return fullscreen; }


//set this to a default command not just null to avoid read access violations when a command is not defined by a scene
controlScheme::controlScheme() :
	wDown(NULL),
	sDown(NULL),
	aDown(NULL),
	dDown(NULL),
	wUp(NULL),
	sUp(NULL),
	aUp(NULL),
	dUp(NULL),
	eDown(NULL),
	leftMouseDown(NULL),
	leftMouseUp(NULL)
{};

controlScheme::~controlScheme() {
	delete wUp;
	delete sUp;
	delete aUp;
	delete dUp;
	delete wDown;
	delete sDown;
	delete aDown;
	delete dDown;
	delete eDown;
	delete leftMouseDown;
	delete leftMouseUp;
}

int inputHandler::getMouseXPos() { return(xPos); }
int inputHandler::getMouseYPos() { return(yPos); }
