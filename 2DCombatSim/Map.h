#pragma once
#include <vector>
#include <string>

class Map {
public:
	Map(std::string levelName);
	~Map();
	std::vector<std::string> getMap();
	std::vector<std::string> * getMapPtr();
private:
	std::vector<std::string> _map;
};