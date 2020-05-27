#include"inputHandler.h"

void inputHandler::bindWDown(command* w) { wDown = w; }
void inputHandler::bindSDown(command* s) { sDown = s; }
void inputHandler::bindADown(command* a) { aDown = a; }
void inputHandler::bindDDown(command* d) { dDown = d; }
void inputHandler::bindWUp(command* w) { wUp = w; }
void inputHandler::bindSUp(command* s) { sUp = s; }
void inputHandler::bindAUp(command* a) { aUp = a; }
void inputHandler::bindDUp(command* d) { dUp = d; }

void inputHandler::handleInputs() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_w:
			wDown->execute();
			break;
		case SDLK_s:
			sDown->execute();
			break;
		case SDLK_a:
			aDown->execute();
			break;
		case SDLK_d:
			dDown->execute();
			break;
		}
		break;

	case SDL_QUIT:
		closed = true;
		break;
	}

}

inputHandler::inputHandler() { closed = false; }

bool inputHandler::getClosed() { return closed; }

void startUpCommand::execute() {
	target->movingUp = true;
}
startUpCommand::startUpCommand(player* p):target(p){};

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
	target->movingUp = true;
}
stopUpCommand::stopUpCommand(player* p) :target(p) {};

void stopDownCommand::execute() {
	target->movingDown = true;
}
stopDownCommand::stopDownCommand(player* p) :target(p) {};

void stopLeftCommand::execute() {
	target->movingLeft = true;
}
stopLeftCommand::stopLeftCommand(player* p) :target(p) {};

void stopRightCommand::execute() {
	target->movingRight = true;
}
stopRightCommand::stopRightCommand(player* p) :target(p) {};