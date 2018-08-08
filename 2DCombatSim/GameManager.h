#pragma once

#include "Level.h"

class GameManager {
public:
	GameManager();
	~GameManager();
	void clearScreen();
private:
	Level *_level = nullptr;
};