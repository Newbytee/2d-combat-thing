#include "ArmyUnit.h"
#include <iostream>

ArmyUnit::ArmyUnit(int hp, int atk, char type) {
	_hp = hp;
	_atk = atk;
	_type = type;
}

ArmyUnit::~ArmyUnit() {
}

int ArmyUnit::getHp() {
	return _hp;
}

int ArmyUnit::getAtk() {
	return _atk;
}

char ArmyUnit::getType() {
	return _type;
}

void ArmyUnit::setType(char type) {
	_type = type;
}
