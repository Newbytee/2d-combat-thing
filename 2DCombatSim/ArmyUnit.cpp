#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(unsigned int x, unsigned int y, int hp, int atk, int type) {

}

ArmyUnit::~ArmyUnit() {
	delete _x;
	delete _y;
	delete _hp;
	delete _atk;
	delete _type;
}

void ArmyUnit::move(int x, int y) {
	_x += x;
	_y += y;
}