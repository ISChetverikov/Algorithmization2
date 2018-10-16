#pragma once
#include "Aircraft.h"

class MIG31 : public Aircraft {
public:
	MIG31();
	~MIG31();

public:
	void Move(Point p) override final;

	void Attack(Machine& m) override final;
};