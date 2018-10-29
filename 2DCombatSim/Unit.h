#pragma once
class Unit {
public:
	Unit(int hp, int atk, char type);
	~Unit();
	int getHp();
	int getAtk();
	char getType();
private:
	int _hp, _atk;
	char _type;
};