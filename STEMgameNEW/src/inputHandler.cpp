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


		case SDL_QUIT:
			closed = true;
			break;
		}
	}
}

void inputHandler::setControls(controlScheme* c) {
	controls = c;
}

inputHandler::inputHandler() : closed(false) {}

bool inputHandler::getClosed() { return closed; }

controlScheme::controlScheme() :
	wDown(NULL),
	sDown(NULL),
	aDown(NULL),
	dDown(NULL),
	wUp(NULL),
	sUp(NULL),
	aUp(NULL),
	dUp(NULL)
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
}