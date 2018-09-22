#include "Unit.h"

Unit::Unit() {
}

Unit::Unit(int hp, int atk, char type) {
	_hp = hp;
	_atk = atk;
	_type = type;
}

Unit::~Unit() {
}

char Unit::getType() {
	return _type;
}
