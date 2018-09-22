#pragma once
#include "UnitMap.h"
#include "Map.h"

class GameLogic {
public:
	GameLogic();
	~GameLogic();
	void printLevel(std::vector<std::vector<Unit*> > units, std::vector<std::string> map);
};

