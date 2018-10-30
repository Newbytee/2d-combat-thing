#include "Unit.h"

Unit::Unit(int hp, int atk, char type) {
	_hp = hp;
	_atk = atk;
	_type = type;
}

Unit::~Unit() {
}

void Unit::modHp(int hp) {
	_hp += hp;
}

int Unit::getHp() {
	return _hp;
}

int Unit::getAtk() {
	return _atk;
}

char Unit::getType() {
	return _type;
}