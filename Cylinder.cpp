#include "Cylinder.h"
#define _USE_MATH_DEFINES
#include <cmath>

Cylinder::Cylinder(){
	this->height = 0;
	this->radius = 0;
}

Cylinder::Cylinder(double radius, double height) {
	this->height = height;
	this->radius = radius;
}

Cylinder::~Cylinder(){
	
}

double Cylinder::GetRadius() const{
	return this->radius;
}

void Cylinder::SetRadius(int value) {
	this->radius = value;
}

double Cylinder::GetHeight() const{
	return this->height;
}

void Cylinder::SetHeight(int value) {
	this->height = value;
}

double Cylinder::GetSideSurfaceArea() {
	return
		2 * M_PI * this->radius * this->height
		+ M_PI * this->radius * this->radius;
}
