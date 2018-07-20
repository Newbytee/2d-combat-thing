#pragma once

#include <vector>
#include "ArmyUnit.h"

class Level {
public:
	Level(int levelN);
	~Level();
	char getTile(unsigned int x, unsigned int y);
	void setTile(unsigned int x, unsigned int y);
	void printLevel();
private:
	int currentLevel;
	std::vector<std::string> _level;
	std::vector<std::vector<ArmyUnit> > _units;
};