#pragma once

#include <vector>

class Level {
public:
	Level(int levelN);
	~Level();
	char getTile(char x, char y);
private:
	std::vector<std::string> *_level;
};