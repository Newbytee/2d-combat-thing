#pragma once

class ArmyUnit {
public:
	ArmyUnit(unsigned int x, unsigned int y, int hp, int atk, int type);
	~ArmyUnit();
	void move(int x, int y);
private:
	int *_x = nullptr;
	int *_y = nullptr;
	int *_hp = nullptr;
	int *_atk = nullptr;
	int *_type = nullptr;
};