#include "UnitMap.h"
#include <fstream>
#include <iostream>
#include <string>

UnitMap::UnitMap(std::string levelName) {
	std::ifstream mapFile = std::ifstream(levelName + ".txt");

	if (!(mapFile.is_open())) {
		std::cout << perror;
		return;
	}

	std::string input;
	
	for (int y = 0; std::getline(mapFile, input); y++) {
		for (int x = 0; x < input.length(); x++) {

		}
	}
}


UnitMap::~UnitMap() {
	for (int y = 0; y < _unitMap.size(); y++) {
		for (int x = 0; x < _unitMap[y].size(); x++) {
			if (_unitMap[y][x] != nullptr) {
				delete _unitMap[y][x];
			}
		}
	}
}

Unit * UnitMap::getUnit(unsigned int x, unsigned int y) {
	return _unitMap[y][x];
}

int UnitMap::getWidth(unsigned int y) {
	return _unitMap[y].size();
}

int UnitMap::getHeight() {
	return _unitMap.size();
}

void UnitMap::setUnit(unsigned int x, unsigned int y, Unit *unit) {
	_unitMap[y][x] = unit;
}
