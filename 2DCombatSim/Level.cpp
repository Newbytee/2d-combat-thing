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
	std::string level;
	std::string enemies;

	for (int i = 0; std::getline(*levelFile, input); i++) {
		for (int j = 0; j < input.length(); j++) {
			switch (input[j]) {
			case '$':
			case '&':
				enemies.push_back(input[j]);
				level.push_back('.');
				break;
			default:
				break;
			}
		}
		_level.push_back(input + '\0');
	}
}


Level::~Level() {
}

char Level::getTile(unsigned int x, unsigned int y) {
	return 0;
}

void Level::setTile(unsigned int x, unsigned int y) {
}

void Level::printLevel() {
	int levelHeight = _level->size();
	std::vector<std::string> &levelRef = *_level;
	
	for (int x = 0; x < levelHeight; x++) {
		for (unsigned int y = 0; y < levelRef[x].size(); y++) {
			//std::cout << x << '\t' << y;
			printf("%c%c", levelRef[x][y], ' ');
		}
		printf("\n");
	}
}
