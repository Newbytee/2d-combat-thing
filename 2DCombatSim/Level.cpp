#include "Level.h"



Level::Level(int levelN) {
	std::ifstream test("levels/level1.txt", std::ifstream::in);

}


Level::~Level() {
	delete[] _level;
}

char Level::getTile(char x, char y) {
	return 0;
}
