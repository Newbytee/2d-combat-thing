#include "Utils.h"
#include <string>
#include <cmath>

Utils::Utils()
{
}


Utils::~Utils()
{
}

int Utils::parseInteger(std::string input) {
	int parsedValue = 0;
	int tmpInteger;
	int sign = 1;
	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '0':
			tmpInteger = 0;
			break;
		case '1':
			tmpInteger = 1;
			break;
		case '2':
			tmpInteger = 2;
			break;
		case '3':
			tmpInteger = 3;
			break;
		case '4':
			tmpInteger = 4;
			break;
		case '5':
			tmpInteger = 5;
			break;
		case '6':
			tmpInteger = 6;
			break;
		case '7':
			tmpInteger = 7;
			break;
		case '8':
			tmpInteger = 8;
			break;
		case '9':
			tmpInteger = 9;
			break;
		default:
			tmpInteger = 0;
			if (input[i] == '-' && i == 0) {
				sign = -1;
			} else {
				i = input.size();
			}
			break;
		}
		parsedValue = parsedValue * 10 + tmpInteger;
	}
	parsedValue = parsedValue * sign;
	return parsedValue;
}
