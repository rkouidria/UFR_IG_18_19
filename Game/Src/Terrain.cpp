/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE R�mi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Terrain.h"

/* Variables globales                           */


Terrain::Terrain() {}
Terrain::~Terrain() {}


/* Grille de lon x lar : fonctionnelle */
void Terrain::LoadGrid(int lon, int lar){
  glPushMatrix();
  for (int i = 0 ; i < lar ; i++){
    glBegin(GL_LINES);
    glVertex3i(i,0,0);
    glVertex3i(i,0,-lon);
    glEnd();
  }
  for (int i = 0 ; i < lon ; i++){
    glBegin(GL_LINES);
    glVertex3i(0,0,-i);
    glVertex3i(lar,0,-i);
    glEnd();
  }
  glPopMatrix();
}

void Terrain::LoadGap(int lon, int lar) {
	glPushMatrix();

	glPopMatrix();
}