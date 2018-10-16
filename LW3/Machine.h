#pragma once
#include "Point.h"

using namespace std;

class Machine
{
public:
	Machine();
	~Machine();

protected:
	int attackPoints = 0;
	int hitPoints = 0;
	Point coordinate = { 0, 0 };

private:
	int priority = 0;

public:
	int GetPriority();
	void SetPriority(int value);

	int GetHealth();
	void SetHealth(int hp);
	void DecreaseHealth(int d);

	virtual void Move(Point p) = 0;
	virtual void Attack(Machine& m) = 0;
};