#pragma once
#include "UnitMap.h"
#include "Map.h"

class GameLogic {
public:
	GameLogic(std::vector<std::vector<Unit*> > * units, std::vector<std::string> * map);
	~GameLogic();
	void printLevel();
	void simulate();
	bool checkMoveAllowed(unsigned int x, unsigned int y);
private:
	std::vector<std::vector<Unit*> > * _units = nullptr;
	std::vector<std::string> * _map = nullptr;
};