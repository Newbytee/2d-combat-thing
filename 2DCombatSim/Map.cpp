#include "Map.h"
#include <fstream>
#include <iostream>
#include <string>

Map::Map(std::string levelName) {
	std::ifstream mapFile = std::ifstream("levels/" + levelName + ".txt");

	if (!(mapFile.is_open())) {
		std::cout << perror;
		return;
	}

	std::string input;
	char currentChar;

	for (int y = 0; std::getline(mapFile, input); y++) {
		for (int x = 0; x < input.size(); x++) {
			switch (input[x]) {
			case '$':
			case '&':
				if (x > 0) {
					input[x] = input[x - 1];
				} else {
					input[x] = '#';
				}				
				break;
			}
		}
		_map.push_back(input);
	}
}

Map::~Map() {
}

std::vector<std::string> Map::getMap() {
	return _map;
}