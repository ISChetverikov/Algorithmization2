#include <iostream>
#include <iomanip>
#include "Cylinder.h"
#include "Good.h"

using namespace std;

void FirstTaskRoutine() {
	Cylinder first = Cylinder();
	Cylinder second = Cylinder(4.5, 5.5);

	first.SetRadius(5);
	first.SetHeight(6);

	cout << "First task" << endl;
	cout << setfill('=') << setw(60) << "" << endl;

	cout << "First cylinder:" << endl;
	cout << "\tRadius:" << first.GetRadius() << endl;
	cout << "\tHeight:" << first.GetHeight() << endl;
	cout << "\tArea: " << first.GetSideSurfaceArea() << endl;

	cout << "Second cylinder:" << endl;
	cout << "\tRadius:" << second.GetRadius() << endl;
	cout << "\tHeight:" << second.GetHeight() << endl;
	cout << "\tArea: " << second.GetSideSurfaceArea() << endl;
}

void SecondTaskRoutine() {
	double course = 30;
	cout << "Second task" << endl;
	cout << setfill('=') << setw(60) << "" << endl;

	Good g1 = Good();
	Good g2 = Good("Ferrari");
	Good g3 = Good("Changan", "China");
	Good g4 = Good("Chrysler", "USA", 9000);
	Good g5 = Good("Toyota", "Nippon", 6000);
	Good g6 = Good("Fiat", 8000);

	cout << "Toyota price before: " << g5.GetDollarPrice(course) << endl;
	g5.IncDollarPriceForToyota(course, 100);
	cout << "Toyota price after: " << g5.GetDollarPrice(course) << endl << endl;

	cout << "Chrysler price before: " << g4.GetDollarPrice(course) << endl;
	g4.IncDollarPriceForToyota(course, 100);
	cout << "Chrysler price after: " << g4.GetDollarPrice(course) << endl << endl;
}

int main() {
	

	//FirstTaskRoutine();
	SecondTaskRoutine();
	

	return 0;
}