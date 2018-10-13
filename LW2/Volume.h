#pragma once
#include <iostream>

using namespace std;

class Volume
{
public:
	Volume();
	Volume(int a, int b, int c);

	Volume(const Volume& v);
	~Volume();

private:
	int a;
	int b;
	int c;

	void Init(int a = 0, int b = 0, int c = 0);
	

public:
	int GetA() const;
	int GetB() const;
	int GetC() const;
	void SetA(int value);
	void SetB(int value);
	void SetC(int value);

	friend Volume operator + (const Volume& left, const Volume& right);
	friend Volume operator - (const Volume& left, const Volume& right);
	friend Volume operator * (const Volume& left, const Volume& right);

	friend ostream& operator << (ostream& s, const Volume& v);
};
