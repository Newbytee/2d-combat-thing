#include "Level.h"
#include <iostream>
#include <string>
#include <fstream>

Level::Level(int levelN) {
	std::ifstream *levelFile = new std::ifstream("level.txt");
	
	if (!(levelFile->is_open())) {
		std::cout << *perror;
		return;
	}

	std::string input;

	for (int i = 0; std::getline(*levelFile, input); i++) {
		_level->push_back(input + '\0');
	}
}


Level::~Level() {
	delete[] _level;
}

char Level::getTile(unsigned int x, unsigned int y) {
	return 0;
}

void Level::setTile(unsigned int x, unsigned int y) {
}

void Level::printLevel() {
	int levelHeight = _level->size();
	std::vector<std::string>& levelRef = *_level;
	
	for (int x = 0; x < levelHeight; x++) {
		for (unsigned int y = 0; y < levelRef[x].size(); y++) {
			//std::cout << x << '\t' << y;
			printf("%c%c", _level[x][y], ' ');
		}
		printf("\n");
	}
}
