#include "GameManager.h"
#include "GameLogic.h"
#include "Map.h"
#include "UnitMap.h"
#include "Utils.h"
#include <string>
#include <exception>
#include <iostream>

GameManager::GameManager() {
	std::string currentLevel = "level";

	UnitMap units = UnitMap(currentLevel);
	Map map = Map(currentLevel);
	GameLogic game;
	Utils utils;
	std::string tmpInput;
	int tmpInt;

	while (gameIsRunning) {
		game.printLevel(units.getUnitMap(), map.getMap());
		std::cin >> tmpInput;

		tmpInt = utils.parseInteger(tmpInput);

		std::cout << tmpInt;
	}	
}

GameManager::~GameManager() {
}