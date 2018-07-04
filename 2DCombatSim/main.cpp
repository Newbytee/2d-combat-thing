#include "GameManager.h"
#include <iostream>
#include <vector>"

int main() {
	GameManager *gamePtr = nullptr;
	std::vector<int> *testVector = nullptr;
	unsigned int *testPtr =  new unsigned int(1);
	*testPtr = 5;
	std::cout << *testPtr << std::endl;

	testVector = new std::vector<int>();

	gamePtr = new GameManager;
	
	int test;
	std::cin >> test;
	return 0;
}