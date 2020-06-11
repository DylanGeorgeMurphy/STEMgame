#pragma once
#include "Noise.h"
#include "chunkCache.h"
#include<map>
#include<fstream>

class map {
public:
	map();
	~map();
	int getTile(int, int);

	void loadTileData();
	std::string getTextureName(int);
	int getLayer(int);
	int getHeight(int);
	bool getSolid(int);

private:
	perlinNoise* noise = nullptr;
	chunkCache* cache = nullptr;
	int calculateTile(int, int);

	struct tile {
		std::string texture;
		int layer;
		int height;
		bool solid;
	};
	//holds the tile data
	std::map<int, tile> tiles;
};