#include "GameManager.h"
#include <iostream>
#include <conio.h>

GameManager::GameManager() {
	int tmp;
	_level = new Level(1);
	_level->printLevel();
	std::cin >> tmp;
	_level->simulate();
	clearScreen();
	_level->printLevel();
	std::cin >> tmp;
}

GameManager::~GameManager() {
	delete _level;
}

void GameManager::clearScreen() {
	printf("%s", (std::string(100, '\n')).c_str());
}