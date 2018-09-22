#include "GameManager.h"
#include "GameLogic.h"
#include "Map.h"
#include "UnitMap.h"

GameManager::GameManager() {
	std::string currentLevel = "level";

	UnitMap units = UnitMap(currentLevel);
	Map map = Map(currentLevel);
	GameLogic game;

	game.printLevel(units.getUnitMap(), map.getMap());
}

GameManager::~GameManager() {
}