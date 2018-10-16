#pragma once
#include "Aircraft.h"

class F22 : public Aircraft
{
public:
	F22();
	~F22();

public:
	void Move(Point p) override final;
	void Attack(Machine& m) override final;
};