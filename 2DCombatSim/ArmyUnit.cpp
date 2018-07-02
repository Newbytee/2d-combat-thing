#include "ArmyUnit.h"



ArmyUnit::ArmyUnit()
{
}


ArmyUnit::~ArmyUnit() {

}

void ArmyUnit::move(int x, int y) {
	_x += x;
	_y += y;
}