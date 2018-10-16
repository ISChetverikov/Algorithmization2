#include <iostream>
#include "Machine.h"
#include "Tank.h"
#include "Abrams.h"
#include "T-90.h"
#include "F22.h"
#include "MIG-31.h"
#include "Aircraft.h"
using namespace std;

int main() {
	Point p = { 4,5 };
	//Machine m = Machine(); Нельзя создать абстрактный класс
	Abrams abrams = Abrams();
	T90 t90 = T90();
	F22 f22 = F22();
	MIG31 mig31 = MIG31();

	T90 enemy = T90();

	int n = 4;
	Machine * machines[] = {&abrams, &t90, &f22, &mig31};

	cout << "Health of enemy: " << enemy.GetHealth() << endl;
	for (int i = 0; i < n; i++)
	{
		machines[i]->Move(p);
		machines[i]->Attack(enemy);
	}
	cout << "Health of enemy has remain: " << enemy.GetHealth() << endl;
	return 0;
}