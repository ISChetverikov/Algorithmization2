#include <string>
#include <iostream>
#include "Good.h"

using namespace std;

void Good::Init(string name, string manufacturer, double price) {
	this->name = name;
	this->price = price;
	this->manufacturer = manufacturer;

	return;
}


Good::Good(){
	Init();
}

Good::Good(string name, string manufacturer, double price){
	Init(name, manufacturer, price);

	return;
}

Good::Good(string name, double price) {
	Init(name, "", price);
	return;
}

Good::~Good(){
	cout << "Object of good \"" + name +"\" has been destroyed!" << endl;
}

double Good::GetDollarPrice(double course) {
	return this->price / course;
}

void Good::IncDollarPriceForToyota(double course, double increase) {

	if (this->name.find("Toyota") == string::npos)
		return;

	this->price += increase * course;

	return;
}
