#pragma once

class Pos3D
{
public:

	Pos3D();
	Pos3D(double x, double y, double z);
	~Pos3D();

	double px;
	double py;
	double pz;

private:
	void init(double x, double y, double z);
	
};
