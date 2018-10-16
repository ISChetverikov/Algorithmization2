#include "Machine.h"

int Machine::GetHealth() {
	return this->hitPoints;
}
void Machine::SetHealth(int hp) {
	this->hitPoints = hp;
}

void Machine::DecreaseHealth(int d) {
	this->hitPoints -= d;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
}

int Machine::GetPriority() {
	return this->priority;
}
void Machine::SetPriority(int value) {
	this->priority = value;
}

Machine::Machine() {};
Machine::~Machine() {};