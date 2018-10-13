

#pragma once
#include <iostream>

class Polynomial
{
public:
	Polynomial();
	// ������ �� ���� ������ ����������� deg+1!
	Polynomial(int deg, int * pCoefs = nullptr);

	Polynomial(const Polynomial& p);
	~Polynomial();

private:
	// ������������ ����� � ������� ����������� �������
	int * pCoefficients;
	int deg;

	void Init(int deg, int * pCoefs = nullptr);
	Polynomial AlgebraicAdding(const Polynomial& a, const Polynomial& b, bool isPlus);

public:
	int GetDeg();
	void SetCoef(int i, int value);
	Polynomial operator - ();
	Polynomial operator + (const Polynomial& other);
	Polynomial operator - (const Polynomial& other);
	Polynomial operator * (const Polynomial& other);
	int operator[] (int i);

	friend std::ostream& operator << (std::ostream& s, const Polynomial& p);
};
