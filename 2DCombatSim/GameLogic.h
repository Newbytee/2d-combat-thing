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
	bool checkWin();
	bool getDraw();
	char getWinner();
private:
	std::vector<std::vector<Unit*> > * _units = nullptr;
	std::vector<std::string> * _map = nullptr;
	char _winner = NULL;
	bool _draw = false;
};