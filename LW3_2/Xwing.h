#pragma once

#include "Devices.h"

class Xwing
{
public:
	Xwing(MotionDevice* m, CombatDevice* c);
	~Xwing();

private:
	MotionDevice* motionDevice;
	CombatDevice* combatDevice;

public:
	void Move(int power);
	void Stop();
	void Fire(int power);
};
