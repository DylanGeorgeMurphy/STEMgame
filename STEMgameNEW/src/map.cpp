#include "map.h"

map::map() {
	noise = new perlinNoise();
	cache = new chunkCache();
	loadTileData();
}

map::~map() {
	delete noise;
	delete cache;
}

int map::calculateTile(int x, int y) {
	double noiseL = noise->getValue(x*0.005, y*0.005);
	double noiseM = noise->getValue(x*0.025, y*0.025);
	double noiseS = noise->getValue(x*0.4, y*0.4);

	double noiseT = (noiseL + 0.3*noiseM + 0.05*noiseS) / 1.35;

	if (noiseT < 0.45) {
		return(1);
	}
	else if (noiseT < 0.5) {
		return(2);
	}
	else if (noiseT < 0.55) {
		return(3);
	}
	else if (noiseT < 0.57) {
		return(4);
	}
	return(5);
}

int map::getTile(int x, int y) {
	int xChunk = floor(x >> 5);
	int yChunk = floor(y >> 5);

	//this probs needs checking :/
	int fileNumber = xChunk + (yChunk*(51200 / 32));

	//if its not in cache
	if (!(cache->inCache(fileNumber))) {
		//add it to cache
		cache->addItem(fileNumber);
	}

	//if it has a file associated
	if (cache->filePresent(fileNumber)) {
		int ID = cache->getTileID(fileNumber, x - (32 * xChunk), y - (32 * yChunk));
		if (ID != 0)return(ID);
	}


	return(calculateTile(x, y));
}


void map::loadTileData() {
	std::ifstream reader("Tiles.txt");

	std::string texture;
	int ID;
	int layer;
	int height;
	bool solid;

	while (reader >> ID >> texture >> layer >> height >> solid) {
		tiles[ID] = { texture, layer, height, solid };
	}

	reader.close();
}

std::string map::getTextureName(int ID) {
	if (ID < 0 || ID >= tiles.size())return("Default");
	return(tiles[ID].texture);
}

int map::getLayer(int ID) {
	if (ID < 0 || ID >= tiles.size())return(0);
	return(tiles[ID].layer);
}

int map::getHeight(int ID) {
	if (ID < 0 || ID >= tiles.size())return(0);
	return(tiles[ID].height);
}

bool map::getSolid(int ID) {
	if (ID < 0 || ID >= tiles.size())return(false);
	return(tiles[ID].solid);
}
