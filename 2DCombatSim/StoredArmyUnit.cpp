#include "StoredArmyUnit.h"

StoredArmyUnit::StoredArmyUnit(ArmyUnit *unit, int originX, int originY, int moveX, int moveY) {
	_unit = unit;
	_originX = originX;
	_originY = originY;
	_moveX = moveX;
	_moveY = moveY;
}

StoredArmyUnit::~StoredArmyUnit() {
}

int StoredArmyUnit::getOriginX() {
	return _originX;
}

int StoredArmyUnit::getOriginY() {
	return _originY;
}

int StoredArmyUnit::getMoveX() {
	return _moveX;
}

int StoredArmyUnit::getMoveY() {
	return _moveY;
}

ArmyUnit StoredArmyUnit::getUnit() {
	return *_unit;
}