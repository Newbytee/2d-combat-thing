#pragma once

class ArmyUnit {
public:
	ArmyUnit(unsigned int x, unsigned int y, int hp, int atk, char type);
	~ArmyUnit();
	void move(int x, int y);
private:
	int _x;
	int _y;
	int _hp;
	int _atk;
	char _type;
};