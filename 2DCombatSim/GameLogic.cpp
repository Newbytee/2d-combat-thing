#include "GameLogic.h"
#include "Unit.h"
#include <iostream>
#include <random>

GameLogic::GameLogic(std::vector<std::vector<Unit*> > * units, std::vector<std::string> * map) {
	_units = units;
	_map = map;
}

GameLogic::~GameLogic() {
}

void GameLogic::printLevel() {
	char outputChar;

	for (unsigned int y = 0; y < _map->size(); y++) {
		for (unsigned int x = 0; x < (*_map)[y].size(); x++) {
			if (!(*_units)[y][x]) {
				outputChar = (*_map)[y][x];
			} else {
				outputChar = (*_units)[y][x]->getType();
			}
			
			printf("%c ", outputChar);
		}
		printf("\n");
	}
}

void GameLogic::simulate() {
	std::vector<std::vector<Unit*> > bufferedUnits(_units->size());
	unsigned int moveX = 0, moveY = 0, deltaX = 0, deltaY = 0;
	bool targetFound = false;

	for (unsigned int y = 0; y < _units->size(); y++) {
		for (unsigned int x = 0; x < (*_units)[y].size(); x++) {
			bufferedUnits[y].push_back(nullptr);
		}		
	}

	for (unsigned int y = 0; y < _units->size(); y++) {
		for (unsigned int x = 0; x < (*_units)[y].size(); x++) {
			if ((*_units)[y][x]) {
				//std::cout << "Unit found";
				targetFound = false;
				moveX = x, moveY = y;
				for (int searchRadius = 2; searchRadius < 100 && !targetFound; searchRadius++) {
					//if (searchRadius == 99) std::cout << "Max radius reached\n";
					for (int searchX = 1 - searchRadius; searchX < searchRadius && !targetFound; searchX++) {
						for (int searchY = 1 - searchRadius; searchY < searchRadius && !targetFound; searchY++) {
							deltaX = x + searchX;
							deltaY = y + searchY;
							if (deltaX > 0 && deltaY > 0 && deltaY < _units->size() && deltaX < (*_units)[deltaY].size()) {
								switch (searchRadius) {
								case 2:
									if ((*_units)[deltaY][deltaX]) {
										if ((*_units)[deltaY][deltaX]->getType() != (*_units)[y][x]->getType()) {
											targetFound = true;
											std::cout << "Attack!!\n";
											std::cout << deltaX << '\t' << deltaY << '\n';
										}
									}
									break;
								default:
									if ((*_units)[deltaY][deltaX]) {
										if ((*_units)[deltaY][deltaX]->getType() != (*_units)[y][x]->getType()) {
											targetFound = true;
											printf("%i %i", deltaX, deltaY);
											//printf("%c %c", (*_units)[deltaY][deltaX]->getType(), (*_units)[y][x]->getType());
											if (searchX > 0) {
												moveX += 1;
											}
											else if (searchX == 0) {
												moveX += 0;
											}
											else if (searchX < 0) {
												moveX += -1;
											}
											if (searchY > 0) {
												moveY += 1;
											}
											else if (searchY == 0) {
												moveY += 0;
											}
											else if (searchY < 0) {
												moveY += -1;
											}
											//printf("%i, %i\n", moveX, moveY);
										}
									}
								}
							}
							//if (targetFound) printf("target: %i %i, self: %i %i", deltaX, deltaY, x, y);
						}
					}
				}
				if (moveX > 0 && moveX < (*_units)[y].size() && moveY > 0 && moveY < _units->size()) {
					if (checkMoveAllowed(moveX, moveY)) {
						bufferedUnits[moveY][moveX] = new Unit((*_units)[y][x]->getHp(), (*_units)[y][x]->getAtk(), (*_units)[y][x]->getType());
						delete (*_units)[y][x];
						(*_units)[y][x] = nullptr;
					}
				}				
			}
		}
	}

	for (unsigned int y = 0; y < bufferedUnits.size(); y++) {
		for (int x = 0; x < bufferedUnits[y].size(); x++) {
			if (bufferedUnits[y][x]) {
				(*_units)[y][x] = new Unit(bufferedUnits[y][x]->getHp(), bufferedUnits[y][x]->getAtk(), bufferedUnits[y][x]->getType());
				delete bufferedUnits[y][x];
				bufferedUnits[y][x] = nullptr;
			}
		}
	}
}

bool GameLogic::checkMoveAllowed(unsigned int x, unsigned int y) {
	switch ((*_map)[y][x]) {
	case '#':
		return false;
		break;
	default:
		if ((*_units)[y][x]) {
			return false;
		} else {
			return true;
		}
		break;
	}
}