#include "Maths.h"

Maths::Maths() {
}

int Maths::getDelta(int x, int y) {
	if (x < y) {
		return y - x;
	} else if (x > y) {
		return x - y;
	} else {
		return 0;
	}
}

int Maths::getVector(int x, int y) {
	return x - y;
}

int Maths::getAbsoluteValue(int x) {
	if (x < 0) {
		x = x * -1;
	}
	return x;
}
