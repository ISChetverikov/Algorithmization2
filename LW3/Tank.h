
#pragma once
#include <string>
#include "Machine.h"

using namespace std;

class Tank : public Machine
{
public:
	Tank();
	virtual ~Tank() = 0; // Хотим чтобы класс был абстрактным

private:

public:
	void Move(Point p);

	void Attack(Machine& m) override final;
};
