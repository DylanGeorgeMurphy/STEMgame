#include"tiles.h"

tileHandler::tileHandler() {
	loadTileData();
}

void tileHandler::loadTileData() {
	std::ifstream reader("Tiles.txt");

	std::string texture;
	int ID;
	int layer;
	int height;

	while (reader >> ID >> texture >> layer >> height) {
		tiles[ID] = { texture, layer, height };
	}

	reader.close();
}

std::string tileHandler::getTextureName(int ID) {
	if (ID < 0 || ID >= tiles.size())return("Default");
	return(tiles[ID].texture);
}

int tileHandler::getLayer(int ID) {
	if (ID < 0 || ID >= tiles.size())return(0);
	return(tiles[ID].layer);
}

int tileHandler::getHeight(int ID) {
	if (ID < 0 || ID >= tiles.size())return(0);
	return(tiles[ID].height);
}