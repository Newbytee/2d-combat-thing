#include "Level.h"
#include "ArmyUnit.h"
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

	for (int y = 0; std::getline(*levelFile, input); y++) {
		for (int x = 0; x < input.length(); x++) {
			switch (input[x]) {
			case '$':
			case '&':
				_units[y].push_back(ArmyUnit(x, y, 10, 10, input[x]));
				level.push_back('.');
				break;
			default:
				//_units[y].push_back(ArmyUnit(x, y, 0, 0, ' '));
				level.push_back(input[x]);
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
	int levelHeight = _level.size();
	
	for (int x = 0; x < levelHeight; x++) {
		for (unsigned int y = 0; y < _level[x].size(); y++) {
			//std::cout << x << '\t' << y;
			printf("%c%c", _level[x][y], ' ');
		}
		printf("\n");
	}
}
