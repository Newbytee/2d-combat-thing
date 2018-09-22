#include "UnitMap.h"
#include <fstream>
#include <iostream>
#include <string>

UnitMap::UnitMap(std::string levelName) {
	std::ifstream mapFile = std::ifstream("levels/" + levelName + ".txt");

	if (!(mapFile.is_open())) {
		std::cout << perror;
		return;
	}

	std::string input;
	std::vector<Unit*> inputVector;
	char currentChar;

	for (int y = 0; std::getline(mapFile, input); y++) {
		for (int x = 0; x < input.length(); x++) {
			currentChar = input[x];
			switch (currentChar) {
			case '$':
			case '&':
				inputVector.push_back(new Unit(10, 10, currentChar));
				break;
			default:
				inputVector.push_back(nullptr);
				break;
			}
		}
		_unitMap.push_back(inputVector);
		inputVector.clear();
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

std::vector<std::vector<Unit*> > UnitMap::getUnitMap() {
	return _unitMap;
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
