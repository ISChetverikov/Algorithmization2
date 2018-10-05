#pragma once

class Cylinder
{
private:
	double radius;
	double height;

public:
	Cylinder();
	Cylinder(double radius, double height);
	~Cylinder();

	double GetRadius();
	void SetRadius(int value);

	double GetHeight();
	void SetHeight(int value);

	double GetSideSurfaceArea();

};
