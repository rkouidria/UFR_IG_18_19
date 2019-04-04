#pragma once
#include "Decors.h"

class Immeuble : public Decors {
public:
	int nbEtage;
	int nbPartie;

	Immeuble(void);
	Immeuble(double x, double z, double rot, int e, int p);
	~Immeuble();
	void affObjet();
};
