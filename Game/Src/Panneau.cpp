#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Panneau.h"
#include "Outils.h"

Panneau::Panneau(void) : Decors() {
	modele = 0;
	taille = 1.5;
}

Panneau::Panneau(double x, double z, double rot, int model, double t) : Decors(x,z,rot) {
	modele = model;
	taille = t;
}

Panneau::~Panneau() {}

void Panneau::affObjet() {
	switch (modele) {
	case 0:
		affCarre(taille);
		break;
	case 1:
		affRectangle(taille);
		break;
	case 2:
		affDepart(taille,6);
		break;
	}
}

void Panneau::affCarre(double taille) {
	glPushMatrix();
	glTranslatef(posX, taille / 2, posZ);
	Outils::mySolidCylinder(taille,0.1,10);
	glTranslatef(0, (taille / 2) + (taille / 4), 0);
	glScalef(1.0,1.0,0.2);
	glutSolidCube(taille / 2);
	glPopMatrix();
}

void Panneau::affRectangle(double taille) {
	glPushMatrix();
	glTranslatef(posX - (taille / 2), taille / 2, posZ);
	Outils::mySolidCylinder(taille, 0.1, 10);
	glTranslatef(taille, 0, 0);
	Outils::mySolidCylinder(taille, 0.1, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(posX, taille + (taille / 2), posZ);
	glScalef(4.0, 2.0, 0.2);
	glutSolidCube(taille / 2);
	glPopMatrix();
}

void Panneau::affDepart(double taille, double ecart) {
	glPushMatrix();
	glTranslatef(posX - (ecart / 2), taille * 2, posZ);
	Outils::mySolidCylinder(taille * 4, 0.1, 10);
	glTranslatef(ecart, 0, 0);
	Outils::mySolidCylinder(taille * 4, 0.1, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(posX, (taille * 4) - (taille / 4), posZ);
	glScalef(ecart, 1.0, 0.2);
	glutSolidCube(taille / 2);
	glPopMatrix();
}