#pragma once
#include "Noise.h"
#include "chunkCache.h"

class map {
public:
	map();
	~map();
	int getTile(int, int);
private:
	perlinNoise* noise = nullptr;
	chunkCache* cache = nullptr;
	int calculateTile(int, int);
};