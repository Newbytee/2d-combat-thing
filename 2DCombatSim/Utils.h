#pragma once
#include <string>
#include <array>
class Utils {
public:
	Utils();
	~Utils();
	std::array<int, 2> parseInteger(std::string input);
	void clearScreen();
};