#pragma once
#include <iostream>
#include "Tank.h"

using namespace std;

void Tank::Move(Point p) {
	coordinate = p;
	cout << "Tank is moving to the point (" + to_string(p.x)
		+ "," + to_string(p.y) + ")" << endl;
}

void Tank::Attack(Machine& m) {
	m.DecreaseHealth(attackPoints);
	cout << "Tank is attacking! Damage " + to_string(attackPoints) << endl;
}

Tank::Tank() {

}

Tank::~Tank() {

}