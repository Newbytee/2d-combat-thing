#include "GameManager.h"

GameManager::GameManager() {
	_level = new Level(1);
	//_level->printLevel();
}

GameManager::~GameManager() {
	delete _level;
}