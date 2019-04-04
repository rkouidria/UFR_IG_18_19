#pragma once
#include "Decors.h"

class Montagne : public Decors {
public:
	double hauteur;
	int circ;
	int nbPente;
	int tr;
	int nbMont;

	Montagne(void);
	Montagne(double x, double z, double h, int c, int p, int m);
	~Montagne();
	void affObjet();

private:
	void affMont(double x, double z, double h, int c, int p);
};