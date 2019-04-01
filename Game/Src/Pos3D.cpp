/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE Rémi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Pos3D.h"

/* Variables globales */

Pos3D::Pos3D() {}
Pos3D::Pos3D(double x, double y, double z) {
	init(x, y, z);
}
Pos3D::~Pos3D() {}

void Pos3D::init(double x, double y, double z) {
	px = x;
	py = y;
	pz = z;
}

