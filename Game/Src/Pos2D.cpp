#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Pos2D.h"

/* Variables globales */

Pos2D::Pos2D() {}
Pos2D::Pos2D(double x, double z) {
	init(x, z);
}
Pos2D::~Pos2D() {}

void Pos2D::init(double x, double z) {
	px = x;
	pz = z;
}