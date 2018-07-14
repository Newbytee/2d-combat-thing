#pragma once

#include <vector>

class Level {
public:
	Level(int levelN);
	~Level();
	char getTile(unsigned int x, unsigned int y);
	void setTile(unsigned int x, unsigned int y);
	void printLevel();
private:
	int *currentLevel = nullptr;
	std::vector<std::string> *_level = nullptr;
};