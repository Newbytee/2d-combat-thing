#include "GameLogic.h"

GameLogic::GameLogic() {
}

GameLogic::~GameLogic() {
}

void GameLogic::printLevel(std::vector<std::vector<Unit*> > units, std::vector<std::string> map) {
	char outputChar;

	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
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