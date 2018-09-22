#pragma once
#include <vector>
#include "Unit.h"

class UnitMap {
public:
	UnitMap(std::string levelName);
	~UnitMap();
	std::vector<std::vector<Unit*> > getUnitMap();
	Unit *getUnit(unsigned int x, unsigned int y);
	int getWidth(unsigned int y);
	int getHeight();
	void setUnit(unsigned int x, unsigned int y, Unit *unit);
private:
	std::vector<std::vector<Unit*> > _unitMap;
};