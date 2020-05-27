#pragma once
#include<string>
#include<map>
#include<fstream>

class tileHandler {
private:
	struct tile {
		std::string texture;
		int layer;
		int height;
	};
	//holds the tile data
	std::map<int, tile> tiles;

public:
	tileHandler();
	void loadTileData();
	std::string getTextureName(int);
	int getLayer(int);
	int getHeight(int);
};