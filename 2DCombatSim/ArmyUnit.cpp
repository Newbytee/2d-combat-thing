#include "ArmyUnit.h"

ArmyUnit::ArmyUnit() {

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