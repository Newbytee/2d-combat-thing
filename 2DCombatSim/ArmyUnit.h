#pragma once

class ArmyUnit {
public:
	ArmyUnit();
	~ArmyUnit();
	void move(int x, int y);
private:
	int *_x = nullptr;
	int *_y = nullptr;
	int *_hp = nullptr;
	int *_atk = nullptr;
	int *_type = nullptr;
};