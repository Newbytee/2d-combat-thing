#pragma once
class Unit {
public:
	Unit();
	Unit(int hp, int atk, char type);
	~Unit();
	char getType();
private:
	int _hp, _atk;
	char _type;
};