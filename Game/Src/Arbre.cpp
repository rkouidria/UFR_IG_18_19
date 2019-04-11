#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Arbre.h"
#include "Outils.h"

Arbre::Arbre(void) : Decors() {
	modele = 0;
}

Arbre::Arbre(double x, double z, double rot, int mod) : Decors(x, z, rot) {
	modele = mod;
}

Arbre::~Arbre() {}

void Arbre::affObjet() {
	switch (modele) {
	case 0:
		arbre0();
		break;
	case 1:
		arbre1();
		break;
	case 2:
		arbre2();
		break;
	case 3:
		arbre3();
		break;

	}
}

void Arbre::arbre0() {
	glPushMatrix();
	glRotatef(rot, 0.0F, 1.0F, 0.0F);
	glTranslatef(posX, 1.5, posZ);
	Outils::mySolidCylinder(3.0, 0.25, 10.0);
	glTranslatef(0, 2.5, 0);
	glScalef(1.0, 1.5, 1.0);
	glutSolidCube(2.0);
	glPopMatrix();
}

void Arbre::arbre1() {
	glPushMatrix();
	glRotatef(rot, 0.0F, 1.0F, 0.0F);
	glTranslatef(posX, 1.5, posZ);
	Outils::mySolidCylinder(3.0, 0.25, 10.0);
	glTranslatef(0, 3.0, 0);
	glScalef(1.0, 3.0, 1.0);
	glutSolidSphere(1.0, 30.0, 10.0);
	glPopMatrix();
}

void Arbre::arbre2() {
	glPushMatrix();
	glRotatef(rot, 0.0F, 1.0F, 0.0F);
	glTranslatef(posX, 1.5, posZ);
	Outils::mySolidCylinder(3.0, 0.25, 10.0);
	glTranslatef(0, 3.0, 0);
	glScalef(1.0, 10.0, 1.0);
	glutSolidSphere(1.0,10.0,30.0);
	glPopMatrix();
}

void Arbre::arbre3() {
	glPushMatrix();
	glRotatef(rot, 0.0F, 1.0F, 0.0F);
	glTranslatef(posX, 1.5, posZ);
	Outils::mySolidCylinder(3.0, 0.25, 10.0);
	glTranslatef(0, 2.5, 0);
	glScalef(1.0, 1.5, 1.0);
	glutSolidCube(2.0);
	glPopMatrix();
}