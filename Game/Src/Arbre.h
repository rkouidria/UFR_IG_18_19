#pragma once
#include "Decors.h"

class Arbre : public Decors {
public:

	Arbre(void);
	Arbre(double x, double z, double rot);
	~Arbre();
	void affObjet();
};