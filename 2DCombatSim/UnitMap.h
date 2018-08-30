#pragma once
#include <vector>
#include "Unit.h"

class UnitMap {
public:
	UnitMap(std::string levelName);
	~UnitMap();
	Unit *getUnit(unsigned int x, unsigned int y);
private:
	std::vector<std::vector<Unit*> > _unitMap;
};