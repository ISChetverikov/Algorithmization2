#include <iostream>
#include <string>
#include "F22.h"
#include "Point.h"
#include "Machine.h"
#include "Aircraft.h"

using namespace std;

F22::F22() { attackPoints = 15; hitPoints = 30; bonus = 4; };
F22::~F22() {};


void F22::Move(Point p)  {
	coordinate = p;
	cout << "F22 is flying to the point (" + to_string(p.x)
		+ "," + to_string(p.y) + ")" << endl;
}
void F22::Attack(Machine& m)  {
	int damage = attackPoints + bonus;
	m.DecreaseHealth(attackPoints + bonus);
	cout << "F22 is attacking! Damage: " + to_string(damage) << endl;
}