#include "Volume.h"
#include <iostream>
#include <string>

using namespace std;

Volume::Volume() {
	Init();
}
Volume::Volume(int a, int b, int c) {
	Init(a, b, c);
}

Volume::Volume(const Volume& v) {
	Init(v.a, v.b, v.c);
}

Volume::~Volume() {

}

void Volume::Init(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

int Volume::GetA() const {
	return this->a;
}

int Volume::GetB() const {
	return this->b;
}

int Volume::GetC() const {
	return this->c;
}

void Volume::SetA(int value) {
	this->a = value;
}
void Volume::SetB(int value) {
	this->b = value;
}
void Volume::SetC(int value) {
	this->c = value;
}

Volume operator + (const Volume& left, const Volume& right) {
	return Volume(left.a + right.a, left.b + right.b, left.c + right.c);
}
Volume operator - (const Volume& left, const Volume& right) {
	return Volume(left.a - right.a, left.b - right.b, left.c - right.c);
}
Volume operator * (const Volume& left, const Volume& right) {
	return Volume(left.a * right.a, left.b * right.b, left.c * right.c);
}

ostream& operator << (ostream& s, const Volume& v) {
	s << "( " + to_string(v.a) + ", " + to_string(v.b) + ", " + to_string(v.c) + ")";
	return s;
}
