#pragma once
#include "Decors.h"

class Maison : public Decors {
public:

	Maison(void);
	Maison(double x, double z, double rot);
	~Maison();
	void affObjet();
};