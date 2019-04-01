#pragma once

class Pos2D
{
public:

	double px;
	double pz;

	Pos2D();
	Pos2D(double x, double z);
	~Pos2D();

private:
	void init(double x, double z);

};