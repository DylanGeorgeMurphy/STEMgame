#pragma once
#include<vector>
#include "textures.h"
#include "sprites.h"

#include<iostream>


//add a cpp file

class window {
public:
	window(int w, int h, int x, int y) : width(w), height(h), xPos(x), yPos(y), closed(false), moving(false), resizing(false), grabXPos(0), grabYPos(0) {};
	void show(SDL_Renderer* renderer, textureHandler* textures) {
		SDL_Rect segment;

		//background
		SDL_SetRenderDrawColor(renderer, 48, 88, 135, 255);
		segment.x = xPos + 10;
		segment.y = yPos + 10;
		segment.w = width - 20;
		segment.h = height - 20;
		SDL_RenderFillRect(renderer, &segment);


		//top
		segment.w = width - 24;
		segment.h = 30;
		segment.x = xPos + 12;
		segment.y = yPos;
		SDL_RenderCopy(renderer, textures->getTexture("Top"), NULL, &segment);

		//bottom
		segment.w = width - 24;
		segment.h = 10;
		segment.x = xPos + 12;
		segment.y = yPos + height - 10;
		SDL_RenderCopy(renderer, textures->getTexture("Bottom"), NULL, &segment);

		//left
		segment.w = 10;
		segment.h = height - 40;
		segment.x = xPos;
		segment.y = yPos + 32;
		SDL_RenderCopy(renderer, textures->getTexture("Side"), NULL, &segment);

		//right
		segment.w = 10;
		segment.h = height - 40;
		segment.x = xPos + width - 10;
		segment.y = yPos + 32;
		SDL_RenderCopy(renderer, textures->getTexture("Side"), NULL, &segment);

		//top left
		segment.w = 12;
		segment.h = 32;
		segment.x = xPos;
		segment.y = yPos;
		SDL_RenderCopy(renderer, textures->getTexture("TopLeft"), NULL, &segment);

		//top right
		segment.w = 12;
		segment.h = 32;
		segment.x = xPos + width - 12;
		segment.y = yPos;
		SDL_RenderCopy(renderer, textures->getTexture("TopRight"), NULL, &segment);

		//bottom left
		segment.w = 12;
		segment.h = 12;
		segment.x = xPos;
		segment.y = yPos + height - 12;
		SDL_RenderCopy(renderer, textures->getTexture("BottomLeft"), NULL, &segment);

		//bottom right
		segment.w = 12;
		segment.h = 12;
		segment.x = xPos + width - 12;
		segment.y = yPos + height - 12;
		SDL_RenderCopy(renderer, textures->getTexture("BottomRight"), NULL, &segment);

		//close
		segment.w = 20;
		segment.h = 20;
		segment.x = xPos + width - 25;
		segment.y = yPos + 5;
		SDL_RenderCopy(renderer, textures->getTexture("Close"), NULL, &segment);

		//help
		segment.w = 20;
		segment.h = 20;
		segment.x = xPos + width - 48;
		segment.y = yPos + 5;
		SDL_RenderCopy(renderer, textures->getTexture("Help"), NULL, &segment);

		showContent(renderer);

	}
	void click(int x, int y) {
		//if its the close button
		if (x > width - 25 && x < width - 25 + 20 && y>5 && y < 5 + 20)closed = true;
		//if its the help button
		else if (x > width - 48 && x < width - 48 + 20 && y>5 && y < 5 + 20)std::cout << "help" << std::endl;
		//if its resizing
		else if (y > height - 12 && x > width - 12) { resizing = true;}
		//if its content
		else if (y >= 30 && y < height - 10 && x >= 10 && x < width - 10) {
			clickContent(x-10, y-30);
		}
		else { moving = true; grabXPos = x; grabYPos = y; };
	}
	void unClick() {
		moving = false;
		resizing = false;
	}
	int getXPos() { return xPos; }
	int getYPos() { return yPos; }
	int getWidth() { return(width); }
	int getHeight() { return(height); }
	bool getClosed() { return(closed); }
	bool getMoving() { return(moving); }
	bool getResizing() { return(resizing); }
	int getGrabXPos() { return(grabXPos); }
	int getGrabYPos() { return(grabYPos); }
	void setXPos(int x) { xPos = x; }
	void setYPos(int y) { yPos = y; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	int getContentWidth() { return(width - 20); };
	int getContentHeight() { return(height - 40); };
	virtual void showContent(SDL_Renderer* renderer) = 0;
	virtual void clickContent(int x, int y) = 0;

private:
	int xPos;
	int yPos;
	int width;
	int height;
	bool closed;
	bool moving;
	bool resizing;
	int grabXPos;
	int grabYPos;
};

class inventory : public window {
public:
	inventory(textureHandler* t) :window(90+20, 90+10+30, 100, 100), textures(t) {};
	textureHandler* textures;
private:
	virtual void showContent(SDL_Renderer* renderer) {
		SDL_Rect iconBack;
		iconBack.w = 42 - 10;
		iconBack.h = 42 - 10;

		SDL_SetRenderDrawColor(renderer, 35, 73, 112, 255);
		for (int x = 0; x < (getContentWidth())/42; x++) {
			for (int y = 0; y < (getContentHeight())/42; y++) {
				iconBack.x = (x * 42 + getXPos()) + 10 + (getContentWidth()%42)/2 + 5;
				iconBack.y = (y * 42 + getYPos()) + 30 + (getContentHeight()%42)/2 + 5;
				SDL_RenderFillRect(renderer, &iconBack);
				//SDL_RenderCopy(renderer, textures->getTexture("Default"), NULL, &iconBack);
			}
		}

	};
	virtual void clickContent(int x, int y) {
		std::cout << x << "," << y << std::endl;
	};
};


class windowHandler {
private:
	//array of window pointers
	std::vector<window*> windows;
	SDL_Renderer* renderer;
	textureHandler* textures;
	int mouseXPos, mouseYPos;
public:

	//on click
	bool windowClicked() {
		for (int i = windows.size()-1; i>-1; i--) {
			if (mouseXPos >= windows[i]->getXPos() && mouseXPos < windows[i]->getXPos() + windows[i]->getWidth()) {
				if (mouseYPos >= windows[i]->getYPos() && mouseYPos < windows[i]->getYPos() + windows[i]->getHeight()) {

					//click the window
					windows[i]->click(mouseXPos-windows[i]->getXPos(), mouseYPos-windows[i]->getYPos());

					//delete the closed ones
					if (windows[i]->getClosed()) {
						removeWindow(i);
					}
					return true;
				}
			}
		}
		return false;
	}

	void windowUnClicked() {
		for (int i = 0; i < windows.size(); i++) {
			windows[i]->unClick();
		}
	}

	//every frame
	void updateWindows(int x, int y) {
		mouseXPos = x;
		mouseYPos = y;
		for (int i = 0; i < windows.size(); i++) {
			if (windows[i]->getMoving()) {
				windows[i]->setXPos(x - windows[i]->getGrabXPos());
				windows[i]->setYPos(y - windows[i]->getGrabYPos());
			}

			if (windows[i]->getResizing()) {
				int w = mouseXPos - windows[i]->getXPos() + 6;
				int h = mouseYPos - windows[i]->getYPos() + 6;
				if (w >= 100)windows[i]->setWidth(w);
				if (h >= 100)windows[i]->setHeight(h);
			}

		}
	}

	void addWindow() {
		inventory* i  = new inventory(textures);
		windows.push_back(i);
	}

	void removeWindow(int k) {
		delete windows[k];
		windows.erase(windows.begin() + k);
	}

	void showWindows() {
		for (int i = 0; i < windows.size(); i++) {
			windows[i]->show(renderer, textures);
		}
	}

	windowHandler(textureHandler* t, SDL_Renderer* r) : renderer(r), textures(t), mouseXPos(0), mouseYPos(0){}
};