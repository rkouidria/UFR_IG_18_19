/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE R�mi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Terrain.h"
#include "Pos3D.h"
/* Variables globales                           */


Terrain::Terrain() {}
Terrain::~Terrain() {}


/* Grille de lon x lar : fonctionnelle */
void Terrain::LoadGrid(int lon, int lar){
	glColor3f(0, 0, 0);
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


/* Dessine le plateau du circuit :
	A optimiser avec des gl_quad_strip*/
void Terrain::LoadGap(int lon, int lar) {

	glColor3f(0.1, 0.75, 0.25);
	glPushMatrix();
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 1.0f, 0.0f);

	glVertex3i(0, 0, 0);
	glVertex3i(lar, 0, 0);
	glVertex3i(lar, 0, -lon);
	glVertex3i(0, 0, -lon);
	glEnd();
	glPopMatrix();
}


/* Cette fonction trace le circuit */
void Terrain::LoadRoad() {
	

	Pos3D *p = new Pos3D();

	p->px = 80; p->py = 1; p->pz = -80;
	DrawStraight(*p, 80, -6);
		p->px = 160; p->py = 1; p->pz = -74;
		DrawVirage(*p, 3); 
	p->px = 160; p->py = 1; p->pz = -60;
	DrawStraight(*p, 6, -20);
		p->px = 166; p->py = 1; p->pz = -54;
		DrawVirage(*p, 1);
	p->px = 166; p->py = 1; p->pz = -54;
	DrawStraight(*p, 150, -6);
		p->px = 316; p->py = 1; p->pz = -60;
		DrawVirage(*p, 4);
	p->px = 316; p->py = 1; p->pz = -60;
	DrawStraight(*p, 6, -60);
		p->px = 322; p->py = 1; p->pz = -114;
		DrawVirage(*p, 2);
	p->px = 322; p->py = 1; p->pz = -120;
	DrawStraight(*p, 110, -6);
		p->px = 432; p->py = 1; p->pz = -126;
		DrawVirage(*p, 4);
	p->px = 432; p->py = 1; p->pz = -126;
	DrawStraight(*p, 6, -80);
		p->px = 432; p->py = 1; p->pz = -200;
		DrawVirage(*p, 3);
	p->px = 390; p->py = 1; p->pz = -206;
	DrawStraight(*p, 42, -6);
		p->px = 390; p->py = 1; p->pz = -206;
		DrawVirage(*p, 1);
	p->px = 384; p->py = 1; p->pz = -212;
	DrawStraight(*p, 6, -175);
		p->px = 384; p->py = 1; p->pz = -381;
		DrawVirage(*p, 3);
	p->px = 344; p->py = 1; p->pz = -387;
	DrawStraight(*p, 40, -6);
		p->px = 344; p->py = 1; p->pz = -387;
		DrawVirage(*p, 1);
	p->px = 338; p->py = 1; p->pz = -392;
	DrawStraight(*p, 6, -46);
		p->px = 338; p->py = 1; p->pz = -432;
		DrawVirage(*p, 3);
	p->px = 68; p->py = 1; p->pz = -438;
	DrawStraight(*p, 270, -6);
		p->px = 68; p->py = 1; p->pz = -432;
		DrawVirage(*p, 2);
	p->px = 62; p->py = 1; p->pz = -300;
	DrawStraight(*p, 6, -138);
		p->px = 68; p->py = 1; p->pz = -294;
		DrawVirage(*p, 1);
	p->px = 68; p->py = 1; p->pz = -294;
	DrawStraight(*p, 60, -6);
		p->px = 128; p->py = 1; p->pz = -288;
		DrawVirage(*p, 3);
	p->px = 128; p->py = 1; p->pz = -244;
	DrawStraight(*p, 6, -50);
		p->px = 134; p->py = 1; p->pz = -238;
		DrawVirage(*p, 1);
	p->px = 134; p->py = 1; p->pz = -238;
	DrawStraight(*p, 40, -6);
		p->px = 174; p->py = 1; p->pz = -232;
		DrawVirage(*p, 3);
	p->px = 174; p->py = 1; p->pz = -138;
	DrawStraight(*p, 6, -100);
		p->px = 174; p->py = 1; p->pz = -138;
		DrawVirage(*p, 4);
	p->px = 74; p->py = 1; p->pz = -132;
	DrawStraight(*p, 100, -6);
		p->px = 74; p->py = 1; p->pz = -126;
		DrawVirage(*p, 2);
	p->px = 68; p->py = 1; p->pz = -112;
	DrawStraight(*p, 6, -20);
		p->px = 74; p->py = 1; p->pz = -106;
		DrawVirage(*p, 1);
		p->px = 74; p->py = 1; p->pz = -100;
		DrawVirage(*p, 3);
	p->px = 74; p->py = 1; p->pz = -86;
	DrawStraight(*p, 6, -20);
		p->px = 80; p->py = 1; p->pz = -80;
		DrawVirage(*p, 1);
	
}

/* Dessine un morceau de route droit 
	pos représente le coin inférieur droit
	*/
void Terrain::DrawStraight(Pos3D &pos, int lar, int lon) {
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3i(pos.px, pos.py, pos.pz);
	glVertex3i(pos.px+lar, pos.py, pos.pz);
	glVertex3i(pos.px+lar, pos.py, pos.pz+lon);
	glVertex3i(pos.px, pos.py, pos.pz+lon);
	glEnd();
	glPopMatrix();
}

/* Dessine un virage
	choix permet de decider le sens
	1 : BD
	2 : BG
	3 : HD
	4 : HG
	pos : centre du cercle */
void Terrain::DrawVirage(Pos3D &pos, int choix) {
	glPushMatrix();
	switch (choix) {
		case 1 :
			glTranslatef(0, 0, -6.0f);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(pos.px, 1,pos.pz); 
			for (float i = 90.0f; i <= 180.0f; i++)
				glVertex3f(6*cos(3.14 * i / 180.0) + pos.px, 1,6*sin(3.14 * i / 180.0) + pos.pz);
			glEnd();
		break;
		case 2 :
			glTranslatef(0, 0, -6.0f);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(pos.px, 1, pos.pz);
			for (float i = 180.0f; i <= 270.0f; i++)
				glVertex3f(6 * cos(3.14 * i / 180.0) + pos.px, 1, 6 * sin(3.14 * i / 180.0) + pos.pz);
			glEnd();
		break;
		case 3:
			glTranslatef(0, 0, -6.0f);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(pos.px, 1, pos.pz);
			for (float i = 270; i-1 <= 360; i++)
				glVertex3f(6 * cos(3.14 * i / 180.0) + pos.px, 1, 6 * sin(3.14 * i / 180.0) + pos.pz);
			glEnd();
		break;
		case 4 :
			glBegin(GL_TRIANGLE_FAN);
			glVertex3f(pos.px, 1, pos.pz);
			for (float i = 0; i <= 90; i++)
				glVertex3f(6 * cos(3.14 * i / 180.0) + pos.px, 1, 6 * sin(3.14 * i / 180.0) + pos.pz);
			glEnd();
		break;
	}
	glPopMatrix();
}

