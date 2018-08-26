#pragma once
#include "ArmyUnit.h"

class StoredArmyUnit {
public:
	StoredArmyUnit(ArmyUnit *unit, int originX, int originY, int moveX, int moveY);
	~StoredArmyUnit();
	int getOriginX(), getOriginY(), getMoveX(), getMoveY();
	ArmyUnit getUnit();
private:
	ArmyUnit *_unit = nullptr;
	unsigned int _originX, _originY, _moveX, _moveY;
};