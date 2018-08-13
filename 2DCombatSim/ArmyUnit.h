#pragma once

class ArmyUnit {
public:
	ArmyUnit(int hp, int atk, char type);
	~ArmyUnit();
	int getHp();
	int getAtk();
	char getType();
private:
	int _hp;
	int _atk;
	char _type;
};