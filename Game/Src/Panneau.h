#pragma once
#include "Decors.h"

class Panneau : public Decors {
public:
	int modele;
	double taille;

	Panneau(void);
	Panneau(double x, double z, double rot, int model, double t);
	~Panneau();
	void affObjet();
	void affCarre(double taille);
	void affRectangle(double taille);
	void affDepart(double taille, double ecart);

private:
};
