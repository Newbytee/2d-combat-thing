#pragma once

#include "Level.h"

class GameManager {
public:
	GameManager();
	~GameManager();
private:
	Level *_level = nullptr;
};