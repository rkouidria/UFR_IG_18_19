#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Immeuble.h"

Immeuble::Immeuble(void) : Decors() {
	nbEtage = 10;
	nbPartie = 1;
}

Immeuble::Immeuble(double x, double z, double rot, int e, int p) : Decors(x, z, rot) {
	nbEtage = e;
	nbPartie = p;
}

Immeuble::~Immeuble() {}

void Immeuble::affObjet() {


	for (int j = 0; j < nbEtage; j++) {
		glPushMatrix();
		glTranslatef(0, 2.5 * j, 0);
		for (int i = 0; i < 4; i++) {
			glRotatef(90 * i, 0.0F, 1.0F, 0.0F);
			glPushMatrix();
			glTranslatef(posX + 10, 1.25, posZ + 10);
			glScalef(4.0, 2.5, 4.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(posX + 10, 0.25, posZ);
			glScalef(2.5, 0.5, 16.0);
			glutSolidCube(1.0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(posX + 10, 2.25, posZ);
			glScalef(2.5, 0.5, 16.0);
			glutSolidCube(1.0);
			glPopMatrix();
		}
		glPopMatrix();
	}
}