#pragma once
#include "Decors.h"

class Panneau : public Decors {
public:

	Panneau(void);
	Panneau(double x, double z, double rot);
	~Panneau();
	void affObjet();

private:
};
