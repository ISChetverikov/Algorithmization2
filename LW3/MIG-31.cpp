#include <string>
#include <iostream>
#include "MIG-31.h"
#include "Point.h"
#include "Machine.h"
#include "Aircraft.h"

using namespace std;

MIG31::MIG31() {
	hitPoints = 35;
	attackPoints = 18;
	//priority = 500; НЕдоступен
};
MIG31::~MIG31() {};

void MIG31::Move(Point p) {
	coordinate = p;
	cout << "MIG31 is flying to the point (" + to_string(p.x)
		+ "," + to_string(p.y) + ")" << endl;
}

void MIG31::Attack(Machine& m) {
	int damage = attackPoints + bonus;
	m.DecreaseHealth(damage);
	cout << "MIG31 is attacking! Damage: " + to_string(damage) << endl;
}