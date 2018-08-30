#pragma once
#include <vector>
#include <string>

class Map {
public:
	Map();
	~Map();
private:
	std::vector<std::string> _map;
};