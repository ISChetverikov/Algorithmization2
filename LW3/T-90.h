#pragma once
#include "Tank.h"

class T90 : public Tank {
public:
	T90();
	~T90();

public:
	// Нельзя override
	//void Move() override;
	//void Attack(Machine& m) override;
};
