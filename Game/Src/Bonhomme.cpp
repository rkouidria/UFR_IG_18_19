#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Bonhomme.h"
#include "Outils.h"

Bonhomme::Bonhomme(void) : Decors() {
	modele = 0;
	tete = 0.25;
}

Bonhomme::Bonhomme(double x, double z, double rot, int mod, double taille) : Decors(x, z, rot) {
	modele = mod;
	tete = taille / 8; printf("tete : %f\n", tete);
}

Bonhomme::~Bonhomme() {}

void Bonhomme::affObjet() {
	glPushMatrix();
	glRotatef(rot, 0.0F, 1.0F, 0.0F);
	glTranslatef(posX, 0.0, posZ);
	switch (modele) {
	case 0:
		Bonhomme0();
		break;
	case 1:
		Bonhomme1();
		break;
	case 2:
		Bonhomme2();
		break;
	case 3:
		Bonhomme3();
		break;
	}
	glPopMatrix();
}

void Bonhomme::Bonhomme0() {
	glPushMatrix();
	//jambes
	glPushMatrix();
	glTranslatef(tete / 2.0, tete * 2, 0.0);
	Outils::mySolidCylinder(tete * 4.0, (tete * 8.0) / 25.0, 10.0);
	glTranslatef(-tete, 0.0, 0.0);
	Outils::mySolidCylinder(tete * 4.0, (tete * 8.0) / 25.0, 10.0);
	glPopMatrix();
	//corp
	glPushMatrix();
	glTranslatef(0.0, tete * 5.0, 0.0);
	glScalef(1.2, 2.0, 0.75);
	glutSolidSphere(tete, 20.0, 20.0);
	glPopMatrix();
	//tete
	glPushMatrix();
	glTranslatef(0.0, tete * 7.5, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(tete, 10.0, 10.0);
	glPopMatrix();
	//bras

	glPopMatrix();
}

void Bonhomme::Bonhomme1() {
	glPushMatrix();

	glPopMatrix();
}

void Bonhomme::Bonhomme2() {
	glPushMatrix();

	glPopMatrix();
}

void Bonhomme::Bonhomme3() {
	glPushMatrix();

	glPopMatrix();
}