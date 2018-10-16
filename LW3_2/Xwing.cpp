#include "Xwing.h"

Xwing::Xwing(MotionDevice* m, CombatDevice* c) {
	this->motionDevice = m;
	this->combatDevice = c;
}

Xwing::~Xwing() {

}

void Xwing::Move(int power) {
	this->motionDevice->Start(power);
}

void Xwing::Fire(int power) {
	this->combatDevice->Fire(power);
}

void Xwing::Stop() {
	this->motionDevice->Stop();
}