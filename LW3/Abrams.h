#pragma once
#include "Abrams.h"
#include "Tank.h"

class Abrams : public Tank
{
public:
	Abrams();
	~Abrams();

public:
	// Нельзя override
	//void Move() override;
	//void Attack(Machine& m) override;
};