#include "Level.h"
#include "ArmyUnit.h"
#include "Maths.h"
#include <iostream>
#include <string>
#include <fstream>

Level::Level(int levelN) {
	std::ifstream levelFile = std::ifstream("level.txt");
	
	if (!(levelFile.is_open())) {
		std::cout << perror;
		return;
	}

	std::string input;
	std::string level;
	std::vector<ArmyUnit *> units;

	for (int y = 0; std::getline(levelFile, input); y++) {
		for (int x = 0; x < input.length(); x++) {
			char currentChar = input[x];
			switch (currentChar) {
			case '$':
			case '&':
				units.push_back(new ArmyUnit(10, 10, currentChar));
				level.push_back('.');
				break;
			default:
				units.push_back(nullptr);
				level.push_back(input[x]);
				break;
			}
		}
		_units.push_back(units);
		_level.push_back(level + '\0');
		level.clear();
		units.clear();
	}
}

Level::~Level() {
}

std::vector<std::string> Level::getCombinedVector() {
	int levelHeight = _level.size();
	std::vector<std::string> combinedVector = _level;

	for (int y = 0; y < levelHeight; y++) {
		for (int x = 0; x < combinedVector[y].size() - 1; x++) {
			if (_units[y][x] != nullptr) {
				combinedVector[y][x] = _units[y][x]->getType();
				std::cout << x << '\t' << y << '\n';
			}
		}
	}

	return combinedVector;
}

char Level::getTile(unsigned int x, unsigned int y) {
	return _level[y][x];
}

int Level::simulate() {
	Maths maths;
	unsigned int levelHeight = _level.size();
	char type;
	bool noTarget;
	int searchDistance, moveX, moveY, deltaX, deltaY;

	for (int unitY = 0; unitY < levelHeight; unitY++) {
		for (int unitX = 0; unitX < _units[unitY].size(); unitX++) {
			if (_units[unitY][unitX] != nullptr) {
				type = _units[unitY][unitX]->getType();
				noTarget = true;
				searchDistance = 1;
				while (noTarget) {
					for (int searchY = unitY - searchDistance; searchY < searchDistance; searchY++) {
						//std::cout << searchY << '\t';
						for (int searchX = unitX - searchDistance; searchX <= searchDistance; searchX++) {
							if (searchY >= 0 && searchX >= 0 && searchY < levelHeight - 1 && searchX < _level[0].size() - 1) {
								if (_units[searchY][searchX] != nullptr && noTarget) {
									//std::cout << "it was run, at least";
									deltaX = maths.getVector(unitX, searchX);
									deltaY = maths.getVector(unitY, searchY);
									if (maths.getAbsoluteValue(deltaX) == maths.getAbsoluteValue(deltaY)) {
										if (deltaX > 0) {
											moveX = -1;
										}
										else {
											moveX = 1;
										}
										if (deltaY > 0) {
											moveY = -1;
										}
										else {
											moveY = 1;
										}
									}
									else if (deltaY < deltaX) {
										if (deltaX > 0) {
											moveX = 1;
										}
										else {
											moveX = -1;
										}
										moveY = 0;
									}
									else if (deltaY > deltaX) {
										if (deltaY > 0) {
											moveY = 1;
										}
										else {
											moveY = -1;
										}
										moveX = 0;
									}
									else {
										std::cout << "halp";
									}
									std::cout << unitX << '\t' << unitY << '\n';
									noTarget = false;
									moveUnit(unitX, unitY, moveX, moveY);									
								}
							}
						}
					}
					searchDistance++;
					if (searchDistance == 500) {
						std::cout << "ERROR: Max distance reached!\n";
						noTarget = false;
					}
				}
			}
		}
	}

	return 0;
}

int Level::checkTile(unsigned int x, unsigned int y, char type) {
	switch (_level[y][x]) {

	}
	return 0;
}

void Level::setTile(unsigned int x, unsigned int y, char type) {
	_level[y][x] = type;
}

void Level::printLevel() {
	int levelHeight = _level.size();
	std::vector<std::string> outputVector = getCombinedVector();
	
	for (int y = 0; y < levelHeight; y++) {
		for (unsigned int x = 0u; x < outputVector[y].size(); x++) {
			//std::cout << x << '\t' << y;
			printf("%c%c", outputVector[y][x], ' ');
		}
		printf("\n");
	}
}

int Level::moveUnit(unsigned int originX, unsigned int originY, int moveX, int moveY) {
	std::cout << "look at me: " << moveX << '\t' << moveY << '\n';
	if (_units[originY][originX] != nullptr) {
		int tmpHp = _units[originY][originX]->getHp();
		int tmpAtk = _units[originY][originX]->getAtk();
		char tmpType = _units[originY][originX]->getType();

		if (_units[originY + moveY][originX + moveX] == nullptr) {
			delete _units[originY + moveY][originX + moveX];
			_units[originY + moveY][originX + moveX] = new ArmyUnit(tmpHp, tmpAtk, tmpType);
			delete _units[originY][originX];
			_units[originY][originX] = nullptr;
			std::cout << "hi";
			return 0;
		}
		else {
			std::cout << "not hi";
			return -1;
		}
	} else {
		std::cout << "unable to move: unit undefined!\n";
	}
}

int Level::moveUnit2(unsigned int unitX, unsigned int unitY, int moveFactorX, int moveFactorY) {
	ArmyUnit *unitOrigin = _units[unitY][unitX];
	ArmyUnit *unitMoveTo = _units[unitY + moveFactorY][unitX + moveFactorX];
	delete unitMoveTo;
	unitMoveTo = new ArmyUnit(*unitOrigin);
	delete unitOrigin;
	unitOrigin = nullptr;

	return 0;
}
