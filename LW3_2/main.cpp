#include <iostream>
#include "Xwing.h"
#include "Devices.h"

using namespace std;

int main() {

	Engine e = Engine();
	HyperDrive h = HyperDrive();
	LaserCannon l = LaserCannon();
	ProtonTorpedoLauncher p = ProtonTorpedoLauncher();

	Xwing x1 = Xwing(&e, &l);
	Xwing x2 = Xwing(&h, &p);

	x1.Move(6);
	x1.Stop();

	x2.Move(14);
	x2.Stop();

	x1.Fire(34);
	x2.Fire(23);

	return 0;
}