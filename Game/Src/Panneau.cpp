#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Panneau.h"

Panneau::Panneau(void) : Decors() {
}

Panneau::Panneau(double x, double z, double rot) : Decors(x,z,rot) {
}

Panneau::~Panneau() {}

void Panneau::affObjet() {
	glPushMatrix();
	glTranslatef(posX, 0, posZ);
	glutSolidCube(6.0); printf("teupah");
	glPopMatrix();
}