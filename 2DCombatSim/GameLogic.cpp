#include "GameLogic.h"
#include "Unit.h"
#include <iostream>

GameLogic::GameLogic() {
}

GameLogic::~GameLogic() {
}

void GameLogic::printLevel(std::vector<std::vector<Unit*> > units, std::vector<std::string> map) {
	char outputChar;

	for (unsigned int y = 0; y < map.size(); y++) {
		for (unsigned int x = 0; x < map[y].size(); x++) {
			if (units[y][x] == nullptr) {
				outputChar = map[y][x];
			} else {
				outputChar = units[y][x]->getType();
			}
			
			printf("%c ", outputChar);
		}
		printf("\n");
	}
}

void GameLogic::simulate(std::vector<std::vector<Unit*> > * units) {
	std::vector<std::vector<Unit*> > bufferedUnits((*units).size());

	for (int y = 0; y < (*units).size(); y++) {
		for (int x = 0; x < (*units)[y].size(); x++) {
			bufferedUnits[y].push_back(nullptr);
		}		
	}

	for (int y = 0; y < (*units).size(); y++) {
		for (int x = 0; x < (*units)[y].size(); x++) {
			if ((*units)[y][x]) {
				bufferedUnits[y][x + 1] = (*units)[y][x];
				delete (*units)[y][x];
			}
		}
	}

	for (int y = 0; y < bufferedUnits.size(); y++) {
		for (int x = 0; x < bufferedUnits[y].size(); x++) {
			if (bufferedUnits[y][x]) {
				(*units)[y][x] = bufferedUnits[y][x];
			}
		}
	}
}
