#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Decors.h"

Decors::Decors(void) {
	init(0, 0, 0);
}

Decors::Decors(double x, double z, double rot) {
	init(x, z, rot);
}

Decors::~Decors() {}

void Decors::init(double x, double z, double rota) {
	posX = x;
	posZ = z;
	rot = rota;
}

