#include <string>
#include <algorithm>
#include "Polynomial.h"

using namespace std;

void Polynomial::Init(int deg, int * pCoefs) {
	this->deg = deg;
	this->pCoefficients = new int[deg + 1];

	if (pCoefs == nullptr)
		for (int i = 0; i < deg + 1; i++)
			this->pCoefficients[i] = 0;
	else
		memcpy_s(this->pCoefficients, (deg + 1) * sizeof(int), pCoefs, (deg + 1) * sizeof(int));
}

Polynomial Polynomial::AlgebraicAdding(const Polynomial& a, const Polynomial& b, bool isPlus) {
	
	int resultDeg = max(a.deg, b.deg);
	int * pTempCoefs = new int[resultDeg + 1];
	int sign = isPlus ? 1 : -1;

	fill(pTempCoefs, pTempCoefs + resultDeg + 1, 0);

	for (int i = 0; i <= resultDeg; i++)
	{
		if (i <= a.deg)
			pTempCoefs[i] += a.pCoefficients[i];

		if (i <= b.deg)
			pTempCoefs[i] = pTempCoefs[i] + sign * b.pCoefficients[i];
	}

	// Пропускаем нулевые коэффициенты в старших разрядах
	while (pTempCoefs[resultDeg] == 0)
		resultDeg--;

	// Если все нулевые - просто число
	if (resultDeg == -1)
		resultDeg = 0;

	Polynomial res = Polynomial(resultDeg, pTempCoefs);
	delete[] pTempCoefs;
	return res;
}

Polynomial::Polynomial() {
	Init(0);
	
	return;
}
Polynomial::Polynomial(int deg, int * pCoefs) {
	Init(deg, pCoefs);

	return;
}

Polynomial::Polynomial(const Polynomial& p) {
	Init(p.deg, p.pCoefficients);
}

Polynomial::~Polynomial() {
	delete[] this->pCoefficients;

	return;
}

Polynomial Polynomial::operator - () {
	Polynomial opposite = Polynomial(*this);
	for (int i = 0; i <= opposite.deg; i++)
	{
		opposite.pCoefficients[i] = -opposite.pCoefficients[i];
	}

	return opposite;
}

Polynomial Polynomial::operator + (const Polynomial& other) {
	return AlgebraicAdding(*this, other, true);
}

Polynomial Polynomial::operator - (const Polynomial& other) {
	return AlgebraicAdding(*this, other, false);
}

Polynomial Polynomial::operator * (const Polynomial& other) {
	Polynomial res = Polynomial(this->deg + other.deg);
	for (int i = 0; i <= this->deg; i++)
	{
		for (int j = 0; j <= other.deg; j++)
		{
			res.pCoefficients[i + j] += this->pCoefficients[i] * other.pCoefficients[j];
		}
	}

	return res;
}

int Polynomial::operator[] (int i) {
	if (i < 0)
		throw out_of_range("Incorrect index of polynomial!");

	if (i <= this->deg)
		return pCoefficients[i];
	else
		return 0;
}

int Polynomial::GetDeg() {
	return this->deg;
}

void Polynomial::SetCoef(int index, int value) {
	if (index < 0)
		throw out_of_range("Incorrect index of polynomial!");

	if (index <= this->deg)
		pCoefficients[index] = value;

	else {
		if (value == 0)
			return;

		int newDeg = index;
		int* buf = new int[newDeg + 1];
		copy(this->pCoefficients, this->pCoefficients + this->deg + 1, buf);
		for (int i = this->deg + 1; i < newDeg; i++)
		{
			buf[i] = 0;
		}
		buf[newDeg] = value;

		delete[] this->pCoefficients;
		this->pCoefficients = buf;
		this->deg = newDeg;
	}
}

ostream& operator << (ostream& s, const Polynomial& p) {
	s << p.pCoefficients[0];

	for (int i = 1; i <= p.deg; i++)
	{
		s << ((p.pCoefficients[i] >= 0) ? " + " : " - ");
		s << to_string(abs(p.pCoefficients[i])) + "x^" + to_string(i);
	}

	return s;
}