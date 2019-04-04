#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>

#include "Montagne.h"
#include "Outils.h"

Montagne::Montagne(void) : Decors() {
	hauteur = 10;
	circ = 24;
	nbPente = 50;
	nbMont = 10;
	tr = time(NULL);
}
Montagne::Montagne(double x, double z, double h, int c, int p, int m) : Decors(x, z, 0) {
	hauteur = h;
	circ = c;
	nbPente = p;
	nbMont = m;
	tr = time(NULL);
}
Montagne::~Montagne(){}

void Montagne::affObjet() {
	srand(tr);
	glPushMatrix();
	glTranslatef(posX, 0, posZ);
	affMont(posX, posZ, hauteur, circ, nbPente);
	glPopMatrix();
	for (int i = 0; i < nbMont; i++) {
		int rx = rand() % (int)(circ / 4);
		int rz = rand() % (int)(circ / 4);
		int rh = rand() % (int)(hauteur / 2);
		int rc = rand() % (int)(circ / 2);
		int rrot = rand() % 360;
		glPushMatrix();
		glRotatef(rrot, 0.0F, 1.0F, 0.0F);
		glTranslatef(posX + (circ / 3) - rx, 0, posZ + (circ / 3) - rz);
		affMont(0, 0, (hauteur / 2) + rh, (circ / 2) - rc, (nbPente / 3));
		glPopMatrix();
	}
}

void Montagne::affMont(double x, double z, double h, int c, int p) {
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0F, 1.0F, 0.0F);
	glVertex3f(x, h, z);

	for (int i = 0; i <= p; i++) {
		float rp = (float)i / p;
		float a = 2.0*Outils::PI()*rp;
		float cs = cos(a);
		float sn = -sin(a);
		glNormal3f(cs, 0.0F, sn);
		if (i == 0 || i == p) {
			float xx = (c / 2) * cs;
			float zz = (c / 2) * sn;
			glVertex3f(xx, 0, zz);
		} else {
			if ((c / 4) == 0) {
				float xx = (c / 2) * cs;
				float zz = (c / 2) * sn;
				glVertex3f(xx, 0, zz);
			}
			else {
				float xx = (c / 2 - (rand() % (int)(c / 4))) * cs;
				float zz = (c / 2 - (rand() % (int)(c / 4))) * sn;
				glVertex3f(xx, 0, zz);
			}
			
		}
	}
	glEnd();
	glPopMatrix();
}