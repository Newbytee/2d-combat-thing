#pragma once
#include <vector>
#include <string>

class Map {
public:
	Map(std::string levelName);
	~Map();
	std::vector<std::string> getMap();
private:
	std::vector<std::string> _map;
};