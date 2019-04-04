#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Arbre.h"

Arbre::Arbre(void) : Decors() {
}

Arbre::Arbre(double x, double z, double rot) : Decors(x, z, rot) {
}

Arbre::~Arbre() {}

void Arbre::affObjet() {
}