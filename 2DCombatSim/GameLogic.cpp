#include "GameLogic.h"
#include "Unit.h"
#include <iostream>

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
	int moveX = 0, moveY = 0;

	for (int y = 0; y < _units->size(); y++) {
		for (int x = 0; x < (*_units)[y].size(); x++) {
			bufferedUnits[y].push_back(nullptr);
		}		
	}

	for (int y = 0; y < _units->size(); y++) {
		for (int x = 0; x < (*_units)[y].size(); x++) {
			if ((*_units)[y][x]) {
				moveX = x, moveY = y - 1;
				if (moveX > 0 && moveX < (*_units)[y].size() && moveY > 0 && moveY < _units->size()) {
					if (checkMoveAllowed(moveX, moveY)) {
						bufferedUnits[moveY][moveX] = new Unit((*_units)[y][x]->getHp(), (*_units)[y][x]->getAtk(), (*_units)[y][x]->getType());
						delete (*_units)[y][x];
						(*_units)[y][x] = nullptr;
					} else {

					}
				}				
			}
		}
	}

	for (int y = 0; y < bufferedUnits.size(); y++) {
		for (int x = 0; x < bufferedUnits[y].size(); x++) {
			if (bufferedUnits[y][x]) {
				(*_units)[y][x] = new Unit(bufferedUnits[y][x]->getHp(), bufferedUnits[y][x]->getAtk(), bufferedUnits[y][x]->getType());
				delete bufferedUnits[y][x];
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