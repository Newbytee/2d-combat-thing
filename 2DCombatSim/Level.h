#pragma once

#include <vector>
#include "ArmyUnit.h"

class Level {
public:
	Level(int levelN);
	~Level();
	std::vector<std::string> getCombinedVector();
	char getTile(unsigned int x, unsigned int y);
	int simulate();
	int checkTile(unsigned int x, unsigned int y, char type);	
	void setTile(unsigned int x, unsigned int y, char type);
	void printLevel();
	int moveUnit(unsigned int originX, unsigned int originY, int moveX, int moveY);
private:
	int currentLevel;
	std::vector<std::string> _level;
	std::vector<std::vector<ArmyUnit *> > _units;
};