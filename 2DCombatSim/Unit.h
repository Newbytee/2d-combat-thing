#pragma once
class Unit {
public:
	Unit(int hp, int atk, char type);
	~Unit();
	void modHp(int hp);
	int getHp();
	int getAtk();
	char getType();
private:
	int _hp, _atk;
	char _type;
};