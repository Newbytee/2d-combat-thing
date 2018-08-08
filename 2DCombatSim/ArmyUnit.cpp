#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(unsigned int x, unsigned int y, int hp, int atk, char type) {
	_x = x;
	_y = y;
	_hp = hp;
	_atk = atk;
	_type = type;
}

ArmyUnit::~ArmyUnit() {
}

void ArmyUnit::move(int x, int y) {
	_x += x;
	_y += y;
}

char ArmyUnit::getType() {
	return _type;
}

int ArmyUnit::getX() {
	return _x;
}

int ArmyUnit::getY() {
	return _y;
}
