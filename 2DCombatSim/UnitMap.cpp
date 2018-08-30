#include "UnitMap.h"



UnitMap::UnitMap(std::string levelName) {
	std::ifstream
}


UnitMap::~UnitMap() {
	for (int y = 0; y < _unitMap.size(); y++) {
		for (int x = 0; x < _unitMap[y].size(); x++) {
			if (_unitMap[y][x] != nullptr) {
				delete _unitMap[y][x];
			}
		}
	}
}

Unit * UnitMap::getUnit(unsigned int x, unsigned int y) {
	return _unitMap[y][x];
}
