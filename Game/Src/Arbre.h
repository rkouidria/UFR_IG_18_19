#pragma once
#include "Decors.h"

class Arbre : public Decors {
public:
	int modele;

	Arbre(void);
	Arbre(double x, double z, double rot, int mod);
	~Arbre();
	void affObjet();

private:
	void arbre0();
	void arbre1();
	void arbre2();
	void arbre3();
};