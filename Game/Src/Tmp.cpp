/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE R�mi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Tmp.h"

/* Variables globales                           */

Tmp::Tmp() {}
Tmp::~Tmp() {}

void Tmp::Draw() {
	glPushMatrix();
	glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0f, 1.0f, 0.0f);

	pos.px = pos.px + acc;
	pos.pz = pos.pz + acc*dir;
	glRotatef(rot, 0, 1, 0);
	glVertex3i(pos.px+2, 1, pos.pz+2);
	glVertex3i(pos.px - 2, 1, pos.pz + 2);
	glVertex3i(pos.px , 1, pos.pz -2);
	printf("Triangle = (%i, %i, %i)  acc =  %i     rot = %i      dir = %i\n", pos.px, pos.py, pos.pz, acc, rot, dir);
	glEnd();
	glPopMatrix();
}

void Tmp::Init(int x, int y , int z, int rota) {
	pos.px = x;
	pos.py = y;
	pos.pz = z;
	rot = rota;
	acc = 0.0F;
	dir = 0.0F;
}