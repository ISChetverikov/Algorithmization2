#include <iostream>
#include "Cylinder.h"

using namespace std;

int main() {
	
	Cylinder first = Cylinder();
	Cylinder second = Cylinder(4.5, 5.5);

	first.SetRadius(5);
	first.SetHeight(6);

	cout << "First cylinder:" << endl;
	cout << "\tRadius:" << first.GetRadius() << endl;
	cout << "\tHeight:" << first.GetHeight() << endl;
	cout << "\tArea: " << first.GetSideSurfaceArea() << endl;

	cout << "Second cylinder:" << endl;
	cout << "\tRadius:" << second.GetRadius() << endl;
	cout << "\tHeight:" << second.GetHeight() << endl;
	cout << "\tArea: " << second.GetSideSurfaceArea() << endl;
	

	return 0;
}