#include "GameManager.h"
#include <iostream>
#include <conio.h>

GameManager::GameManager() {
	int tmp;
	char input = 'g';
	_level = new Level(1);
	_level->printLevel();
	do {
		std::cin >> input;
		_level->simulate();
		clearScreen();
		_level->printLevel();
	} while (input != 'q');
}

GameManager::~GameManager() {
	delete _level;
}

void GameManager::clearScreen() {
	printf("%s", (std::string(100, '\n')).c_str());
}