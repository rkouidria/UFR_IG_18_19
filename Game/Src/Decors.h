#pragma once


class Decors{
public:

	double posX;
	double posZ;

	double rot;

	Decors(void);
	Decors(double x, double z, double rot);
	virtual ~Decors();
	virtual void affObjet()=0;

private:
	void init(double x, double z, double rota);
};