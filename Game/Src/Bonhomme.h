#pragma once
#include "Decors.h"

class Bonhomme : public Decors {
public:
	int modele;
	double tete;

	Bonhomme(void);
	Bonhomme(double x, double z, double rot, int mod, double taille);
	~Bonhomme();
	void affObjet();

private:
	void Bonhomme0();
	void Bonhomme1();
	void Bonhomme2();
	void Bonhomme3();
};