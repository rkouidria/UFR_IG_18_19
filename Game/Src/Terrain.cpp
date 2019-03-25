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

void Terrain::LoadGrid(int lon, int lar){

  glPushMatrix();
  for (int i = 0 ; i < lar ; i++){
    glPushMatrix();
    glBegin(GL_LINES);
    glTranslatef(i,0,0);
    glVertex3f(0.0F,0.0F,0.0F);
    glTranslatef(0,0,lon);
    glVertex3f(0.0F,0.0F,0.0F);
    glEnd();
    glPopMatrix();
  }
  for (int i = 0 ; i < lon ; i++){
    glPushMatrix();
    glBegin(GL_LINES);
    glTranslatef(0,0,-i);
    glVertex3f(0.0F,0.0F,0.0F);
    glTranslatef(lar,0,0);
    glVertex3f(0.0F,0.0F,0.0F);
    glEnd();
    glPopMatrix();
  }

  glPopMatrix();

}
