#pragma once

#include <string>

using namespace std;

class Good
{

private:
	string name;
	string manufacturer;
	double price;

	void Init(string name = "", string manufacturer = "", double price = 0);

public:
	Good();
	Good(string name, string manufacturer = "", double price = 0);
	Good(string name, double price);
	~Good();

	double GetDollarPrice(double course);
	void IncDollarPriceForToyota(double course, double increase);
};