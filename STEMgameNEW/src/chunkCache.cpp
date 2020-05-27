#include "chunkCache.h"



chunkCache::chunkCache() {
	for (int k = 0; k < 12; k++) {
		cache[k].heapPointer = new int[1024];
	}
}

chunkCache::~chunkCache() {
	for (int k = 0; k < 12; k++) {
		delete cache[k].heapPointer;
	}
}

//adds an item to cache (reads files aswell)
void chunkCache::addItem(int fileNumber) {

	//takes a copy of heap pointer
	int* tempPointer = cache[0].heapPointer;

	//cycles the array
	for (int k = 0; k < 11; k++) {
		cache[k] = cache[k + 1];
	}

	//allocates the new one with the temp pointer
	cache[11].heapPointer = tempPointer;
	cache[11].filePresent = false;

	//generates a file name to be saved
	std::string fileName;
	fileName = "MapFiles\\" + std::to_string(fileNumber) + ".txt";

	//creates a reader object
	std::ifstream reader(fileName);

	//integer for the tile ID being read
	int tileID = 0;

	//fills cache array with the file
	int i = 0;
	while (reader >> tileID) {
		*(cache[11].heapPointer + i) = tileID;
		i++;
	}

	//closes the reader file
	reader.close();

	//sets the file present attribute accordingly
	cache[11].filePresent = (i != 1024 ? false : true);

	//names the cache
	cache[11].fileNumber = fileNumber;
}

//checks cache for a filenumber
bool chunkCache::inCache(int fileNumber) {
	for (int x = 0; x < 12; x++) {
		if (cache[x].fileNumber == fileNumber) { return true; }
	}
	return false;
};

//checks if a file is present
bool chunkCache::filePresent(int fileNumber) {
	for (int x = 0; x < 12; x++) {
		if (cache[x].fileNumber == fileNumber) { return cache[x].filePresent; }
	}
	return false;
};

int chunkCache::getTileID(int fileNumber, int x, int y) {
	for (int k = 0; k < 12; k++) {
		if (cache[k].fileNumber == fileNumber) {
			return(cache[k].heapPointer[(y * 32) + x]);
		}
	}
}