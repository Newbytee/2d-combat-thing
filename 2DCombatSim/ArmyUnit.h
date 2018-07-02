#pragma once

class ArmyUnit {
public:
	ArmyUnit();
	~ArmyUnit();
	void move(int x, int y);
private:
	int _x;
	int _y;
	int _hp;
	int _atk;
	int _type;
};