#include "GameManager.h"
#include "GameLogic.h"
#include "Map.h"
#include "UnitMap.h"
#include "Utils.h"
#include <string>
#include <iostream>

GameManager::GameManager() {
	std::string currentLevel = "level";

	UnitMap units = UnitMap(currentLevel);
	Map map = Map(currentLevel);
	GameLogic game(units.getUnitMapPtr(), map.getMapPtr());
	Utils utils;
	std::string tmpInput;
	std::array<int, 2> inputArray;

	while (!_gameIsOver) {		
		utils.clearScreen();
		_gameIsOver = game.checkWin();
		if (!_gameIsOver) {
			game.printLevel();
			std::cin >> tmpInput;
			inputArray = utils.parseInteger(tmpInput);
			if (inputArray[1] == 0) {
				printf("Invalid input!\n");
			}
			else {
				for (int i = 0; i < inputArray[0]; i++) {
					game.simulate();
				}
			}
		}
	}
	if (!game.getDraw()) {
		printf("Team %c wins!", game.getWinner());
	}
	else {
		printf("It's a draw!");
	}
}

GameManager::~GameManager() {
}