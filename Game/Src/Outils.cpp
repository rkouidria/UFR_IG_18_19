#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Outils.h"

Outils::Outils(void){}

void Outils::repere() {
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(0, 0); glVertex2i(0, 100);
	glVertex2i(0, 0); glVertex2i(0, -100);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(0, 0); glVertex2i(100, 0);
	glVertex2i(0, 0); glVertex2i(-100, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, 0); glVertex3i(0, 0, 100);
	glVertex2i(0, 0); glVertex3i(0, 0, -100);
	glEnd();
	glPopMatrix();
}

#ifndef M_PI
#define M_PI 3.14159
#endif

void Outils::mySolidCylinder(double hauteur, double rayon, int ns) {
	glPushMatrix();
	hauteur /= 2.0F;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		float rp = (float)i / ns;
		float a = 2.0*M_PI*rp;
		float cs = cos(a);
		float sn = -sin(a);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;
		glVertex3f(x, hauteur, z);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glPopMatrix();
}

double Outils::PI() {
	return M_PI;
}