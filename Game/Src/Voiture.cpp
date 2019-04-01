#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Voiture.h"
#include "Outils.h"

/* Variables globales                           */

static float blanc[] = { 1.0F,1.0F,1.0F,1.0F };


Voiture::Voiture(void) {
	init(0, 0, 4, 2, 1.5);
}

Voiture::Voiture(double x, double z) {
	init(x, z, 4, 2, 1.5);
}

Voiture::Voiture(double x, double z, double tx, double tz, double ty) {
	init(x, z, tx, tz, ty);
}

Voiture::~Voiture() {}

void Voiture::init(double x, double z, double tx, double tz, double ty) {
	posVX = x;
	posVZ = z;
	tailleVX = tx;
	tailleVZ = tz;
	tailleVY = ty;
	echap = 1;
	nbEchap = 2;
	rotRoue = 360;
	nom = "La meilleur";
	initPos();
}

void Voiture::initPos() {
	posCapo[0] = new Pos3D();
}

void Voiture::toString() {
	printf("Voiture : %s\n\tPos(%f,%f)",nom, posVX, posVZ);
}

void Voiture::vitreAvant() {
	glBegin(GL_QUAD_STRIP);

	glColor3f(1.0, 0.0, 1.0);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex2f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16));
	glVertex3f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16), -(tailleVZ / 16));

	glNormal3f(0.0, 1.0, 0.0);
	glVertex2f((tailleVX / 4) - (tailleVX / 32), (tailleVY / 2) + (tailleVY / 16));
	glVertex3f((tailleVX / 4) - (tailleVX / 32), (tailleVY / 2) + (tailleVY / 16), -(tailleVZ / 16));

	glNormal3f(0.0, 1.0, 0.0);
	glVertex2f((tailleVX / 4) - (tailleVX / 32), tailleVY - (tailleVY / 16));
	glVertex3f((tailleVX / 4) - (tailleVX / 32), tailleVY - (tailleVY / 16), -(tailleVZ / 16));

	glNormal3f(-1.0, 0.0, 1.0);
	glVertex2f((tailleVX / 32), tailleVY - (tailleVY / 16));
	glVertex3f((tailleVX / 32), tailleVY - (tailleVY / 16), -(tailleVZ / 16));

	glNormal3f(1.0, 0.0, 0.0);
	glVertex2f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16));
	glVertex3f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16), -(tailleVZ / 16));
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
}

void Voiture::cote() {
	glBegin(GL_QUADS);//bas de porte
	glVertex2f(-(tailleVX / 2), 0);//1
	glVertex2f(tailleVX / 2, 0);//2
	glVertex2f(tailleVX / 2, (tailleVY / 2));//3
	glVertex2f(-(tailleVX / 2), (tailleVY / 2));//7
	glEnd();

	glBegin(GL_QUADS);//vitre arriere
	glVertex2f((tailleVX / 4), (tailleVY / 2));//6
	glVertex2f(tailleVX / 2, (tailleVY / 2));//3
	glVertex2f((tailleVX / 2) - (tailleVX / 8), tailleVY);//4
	glVertex2f((tailleVX / 4), tailleVY);//5
	glEnd();

	glBegin(GL_QUAD_STRIP);//contour vitre avant
	glVertex2f(-(tailleVX / 8), (tailleVY / 2));//bas avant
	glVertex2f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16));

	glVertex2f((tailleVX / 4), (tailleVY / 2));//bas arriere
	glVertex2f((tailleVX / 4) - (tailleVX / 32), (tailleVY / 2) + (tailleVY / 16));

	glVertex2f((tailleVX / 4), tailleVY);//haut arriere
	glVertex2f((tailleVX / 4) - (tailleVX / 32), tailleVY - (tailleVY / 16));

	glVertex2f(0, tailleVY);//haut avant
	glVertex2f((tailleVX / 32), tailleVY - (tailleVY / 16));

	glVertex2f(-(tailleVX / 8), (tailleVY / 2));//bas avant
	glVertex2f(-(tailleVX / 8) + (tailleVX / 16), (tailleVY / 2) + (tailleVY / 16));
	glEnd();
}

void Voiture::coteDroit() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0F, tailleVY / 4, (tailleVZ / 2) - (tailleVZ / 16));
	glNormal3f(0.0, 0.0, 1.0);
	cote();
	glTranslatef(0.0F, 0, tailleVZ / 16);
	glNormal3f(0.0, 0.0, 1.0);
	cote();
	vitreAvant();
	glPopMatrix();
}

void Voiture::coteGauche() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0F, tailleVY / 4, -(tailleVZ / 2) + (tailleVZ / 16));
	glNormal3f(0.0, 0.0, -1.0);
	cote();
	vitreAvant();
	glTranslatef(0.0F, 0, -(tailleVZ / 16));
	glNormal3f(0.0, 0.0, -1.0);
	cote();
	glPopMatrix();
}

void Voiture::pareBrise() {

}

void Voiture::capo() {
	glPushMatrix();
	//glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	glNormal3f(1.0, 0.0, 0.0);//avant bas
	glVertex3f(-(tailleVX / 2), (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(-(tailleVX / 2), (tailleVY / 4), (tailleVZ / 2));

	glNormal3f(0.0, 1.0, 0.0);//avant haut
	glVertex3f(-(tailleVX / 2), (tailleVY / 4) * 3, -(tailleVZ / 2));
	glVertex3f(-(tailleVX / 2), (tailleVY / 4) * 3, (tailleVZ / 2));

	glNormal3f(0.0, 1.0, 0.0);//au niveau du pare brise
	glVertex3f(-(tailleVX / 8), (tailleVY / 4) * 3, -(tailleVZ / 2));
	glVertex3f(-(tailleVX / 8), (tailleVY / 4) * 3, (tailleVZ / 2));

	glNormal3f(-1.0, 0.0, 0.0);//au pied du conducteur
	glVertex3f(-(tailleVX / 8), (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(-(tailleVX / 8), (tailleVY / 4), (tailleVZ / 2));
	glEnd();
	glPopMatrix();
}

void Voiture::coffre() {
	glPushMatrix();
	//glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(tailleVX / 2, (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(tailleVX / 2, (tailleVY / 4), (tailleVZ / 2));

	glNormal3f(-1.0, 1.0, 0.0);
	glVertex3f(tailleVX / 2, (tailleVY / 2) + (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(tailleVX / 2, (tailleVY / 2) + (tailleVY / 4), (tailleVZ / 2));

	glNormal3f(-1.0, 1.0, 0.0);
	glVertex3f((tailleVX / 2) - (tailleVX / 8), tailleVY + (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f((tailleVX / 2) - (tailleVX / 8), tailleVY + (tailleVY / 4), (tailleVZ / 2));
	glEnd();
	glPopMatrix();
}

void Voiture::pavillion() {
	glPushMatrix();
	//glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f((tailleVX / 2) - (tailleVX / 8), tailleVY + (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f((tailleVX / 2) - (tailleVX / 8), tailleVY + (tailleVY / 4), (tailleVZ / 2));
	glVertex3f(0, tailleVY + (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(0, tailleVY + (tailleVY / 4), (tailleVZ / 2));
	glEnd();
	glPopMatrix();
}

void Voiture::interieur() {
	glColor3f(0.0, 1.0, 0.0);
	glutSolidTorus(0.2, 0.5, 72, 180);
}

void Voiture::facePneu(double hauteur, double r1, double r2, int ns) {
	glPushMatrix();
	hauteur /= 2.0F;
	glNormal3f(0.0, 1.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		float rp = (float)i / ns;
		float a = 2.0*Outils::PI()*rp;
		float cs = cos(a);
		float sn = -sin(a);
		float x = r1*cs;
		float z = r1*sn;
		float x2 = r2*cs;
		float z2 = r2*sn;
		glVertex3f(x, hauteur, z);
		glVertex3f(x2, hauteur, z2);
	}
	glEnd();
	glNormal3f(0.0, 1.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		float rp = (float)i / ns;
		float a = 2.0*Outils::PI()*rp;
		float cs = cos(a);
		float sn = -sin(a);
		float x = r1*cs;
		float z = r1*sn;
		float x2 = r2*cs;
		float z2 = r2*sn;
		glVertex3f(x, -hauteur, z);
		glVertex3f(x2, -hauteur, z2);
	}
	glEnd();
	glPopMatrix();
}

void Voiture::roue(float x, float y, float z) {
	glPushMatrix();
		//pneu
		glTranslatef(x, y, z);
		glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
		glRotatef(rotRoue, 0.0F, 1.0F, 0.0F);
		Outils::mySolidCylinder((tailleVZ / 8), (tailleVY / 4), 10);
		Outils::mySolidCylinder((tailleVZ / 8), (tailleVY / 4) - (tailleVY / 20), 10);
		facePneu((tailleVZ / 8), (tailleVY / 4), (tailleVY / 4) - (tailleVY / 20), 10);

		glPushMatrix();//jantes
			glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(90.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
			glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
			Outils::mySolidCylinder(((tailleVY / 4) - (tailleVY / 20)) * 2, (tailleVZ / 8) / 3, 10);
		glPopMatrix(); 

	glPopMatrix();
}

void Voiture::jeuDeRoue() {
	roue(-((tailleVX / 4) + (tailleVX / 16)), (tailleVY / 4), (tailleVZ / 2) + (tailleVZ / 16));
	roue(-((tailleVX / 4) + (tailleVX / 16)), (tailleVY / 4), -((tailleVZ / 2) + (tailleVZ / 16)));
	roue((tailleVX / 4) + (tailleVX / 16), (tailleVY / 4), (tailleVZ / 2) + (tailleVZ / 16));
	roue((tailleVX / 4) + (tailleVX / 16), (tailleVY / 4), -((tailleVZ / 2) + (tailleVZ / 16)));
}

void Voiture::pot() {
	glPushMatrix();
		glTranslatef((tailleVX / 2) + (tailleVX / 32), (tailleVY / 4) + (tailleVZ / 16), (tailleVZ / 4));
		glRotatef(90.0F, 0.0F, 0.0F, 1.0F);
		Outils::mySolidCylinder((tailleVX / 16), (tailleVZ / 16), 10);
		echappement(echap + 1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef((tailleVX / 2) + (tailleVX / 32), (tailleVY / 4) + (tailleVZ / 16), -(tailleVZ / 4));
		glRotatef(90.0F, 0.0F, 0.0F, 1.0F);
		Outils::mySolidCylinder((tailleVX / 16), (tailleVZ / 16), 10);
		echappement(echap);
	glPopMatrix();
}

void Voiture::echappement(int etat) {
	int tmpEtat = etat;
	if (tmpEtat > nbEchap) { tmpEtat = 1; }
	if(tmpEtat == 1){
	glPushMatrix();
		glTranslatef(0, -(tailleVX / 8), 0);
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32),16.0,16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -(tailleVX / 5), -(tailleVZ / 12));
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -(tailleVX / 5), (tailleVZ / 12));
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef((tailleVZ / 16), -(tailleVX / 6), 0);
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-(tailleVZ / 16), -(tailleVX / 6), 0);
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef((tailleVZ / 32), -(tailleVX / 4), 0);
		glScalef(0.6, 1.0, 0.6);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-(tailleVZ / 32), -(tailleVX / 16), 0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();
	}else{
	if(tmpEtat == 2){
	glPushMatrix();
		glTranslatef(0, -(tailleVX / 7), 0);
		glScalef(0.5, 1.1, 0.6);
		glutSolidSphere((tailleVX / 32),16.0,16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -(tailleVX / 6), -(tailleVZ / 11));
		glScalef(0.4, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, -(tailleVX / 4), (tailleVZ / 12));
		glScalef(0.5, 1.0, 0.7);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef((tailleVZ / 18), -(tailleVX / 5), 0);
		glScalef(0.7, 0.9, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-(tailleVZ / 14), -(tailleVX / 8), 0);
		glScalef(0.5, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef((tailleVZ / 28), -(tailleVX / 5), 0);
		glScalef(0.7, 1.0, 0.5);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-(tailleVZ / 28), -(tailleVX / 15), 0);
		glScalef(0.6, 0.7, 0.6);
		glutSolidSphere((tailleVX / 32), 16.0, 16.0);
	glPopMatrix();
	}
	}
}

void Voiture::basDeCaisse() {
	glPushMatrix();
	//glRotatef(-90.0F, 1.0F, 0.0F, 0.0F);
	//glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0.0, -1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blanc);
	glBegin(GL_POLYGON);
	glVertex3f(-(tailleVX / 2), (tailleVY / 4), -(tailleVZ / 2));
	glVertex3f(-(tailleVX / 2), (tailleVY / 4), (tailleVZ / 2));
	glVertex3f((tailleVX / 2), (tailleVY / 4), (tailleVZ / 2));
	glVertex3f((tailleVX / 2), (tailleVY / 4), -(tailleVZ / 2));
	glEnd();
	glPopMatrix();
	jeuDeRoue();
}

void Voiture::affVoiture() {
	glPushMatrix();
	glTranslatef(posVX, 0, posVZ);
	basDeCaisse();
	coteDroit();
	coteGauche();
	capo();
	coffre();
	pavillion();
	pot();
	glPopMatrix();

	toString();
	//glutSolidCube(2.0);
}

void Voiture::changePos(double x, double z) {
	posVX = x;
	posVZ = z;
}