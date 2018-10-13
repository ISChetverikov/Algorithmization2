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

	double GetRadius() const;
	void SetRadius(int value);

	double GetHeight() const;
	void SetHeight(int value);

	double GetSideSurfaceArea();

};
