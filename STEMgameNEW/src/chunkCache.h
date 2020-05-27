#pragma once
#include<string>
#include<fstream>

class chunkCache {
private:
	struct File {
		int fileNumber = -1;
		bool filePresent = false;
		int *heapPointer;
	};

	File cache[12];

public:
	void addItem(int);
	bool inCache(int);
	bool filePresent(int);
	int getTileID(int, int, int);

	chunkCache();
	~chunkCache();
};