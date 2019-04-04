#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Maison.h"

Maison::Maison(void) : Decors() {
}

Maison::Maison(double x, double z, double rot) : Decors(x, z, rot) {
}

Maison::~Maison() {}

void Maison::affObjet() {
}