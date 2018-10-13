#include <iostream>
#include "Polynomial.h"

using namespace std;

void FirstTaskRoutine() {

	int pDeg = 4;
	int qDeg = 5;
	int pCoefs[5] = { 4,-3, 5, 6, 4 };
	int qCoefs[6] = { 1,1,1,2,1,1 };
	Polynomial p = Polynomial(pDeg, pCoefs);
	Polynomial q = Polynomial(qDeg, qCoefs);

	cout << "First p polynomial:" << endl;
	cout << p << endl;
	cout << "Second q polynomial:" << endl;
	cout << q << endl << endl;

	cout << "Adding of polynomials q and p:" << endl;
	cout << p + q << endl;

	cout << "Substructing of polynomials q and p:" << endl;
	cout << p - q << endl;

	cout << "Extension polynomial p with one senior coefficient:" << endl;
	p.SetCoef(6, 8);
	cout << p << endl;

	cout << "Adding opposite polynomial -p to p:" << endl;
	cout << p + (-p) << endl;

	cout << "Multiplying of plynomials p and q:" << endl;
	cout << p * q << endl << endl;

	cout << "Getting degree of a polynomial p:" << endl;
	cout << p.GetDeg() << endl;

	cout << "Getting elements of p with []:" << endl;
	for (int i = 0; i <= pDeg; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	cout << "Getting out of range element with []:" << endl;
	try {
		cout << p[-123] << endl;
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

	return;
}

int main() {
	
	FirstTaskRoutine();

	return 0;
}