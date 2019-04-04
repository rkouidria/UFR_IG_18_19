#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Voiture.h"
#include "Outils.h"
#include "Panneau.h"
#include "Montagne.h"
#include "Immeuble.h"

static int wTx = 800;              // Resolution horizontale de la fenetre
static int wTy = 800;              // Resolution verticale de la fenetre
static int wPx = 800;               // Position horizontale de la fenetre
static int wPy = 0;               // Position verticale de la fenetre

static int colorMat = 0;


static float blanc[] = { 1.0F,1.0F,1.0F,1.0F };
static float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static float bleu[] = { 0.0F,0.0F,1.0F,1.0F };
static float gris[] = { 0.25F,0.25F,0.25F,1.0F };
static float noir[] = { 0.0F,0.0F,0.0F,1.0F };

static double vx = 1.0;
static double vy = 1.0;
static double vz = 10.0;

static Voiture *voiture;
static Decors *decors;
static Decors *decors2;
static Decors *mont;

static void init() {
	voiture = new Voiture();
	decors = new Panneau(5, 0, 25, 0, 2);
	decors2 = new Panneau(-5, 0, 150, 1, 1.5);
	mont = new Immeuble();

	glClearColor(0.25F, 0.25F, 0.25F, 1.0F);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	//glEnable(GL_COLOR_MATERIAL);
	glutPostRedisplay();
}

static void scene(void) {

	glPushMatrix();
	float pos0[4] = { 0.0F,10.0F,-5.0F,0.0F };
	float pos1[4] = { 0.0F,10.0F,5.0F,0.0F };
	//glRotated(90.0F,0.0F,1.0F,0.0F);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, blanc);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blanc);
	glPopMatrix();
	glPushMatrix();
	Outils::repere();
	voiture->affVoiture();
	decors->affObjet();
	decors2->affObjet();
	mont->affObjet();
	glPopMatrix();
}

static void display(void) {
	printf("D\nx : %f, y : %f, z : %f\n", vx, vy, vz);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.25F, 0.25F, 0.25F, 1.0F);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();
	gluLookAt(vx, vy, vz, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0);
	scene();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	int error = glGetError();
	if (error != GL_NO_ERROR)
		printf("Attention erreur %d\n", error);
}

static void reshape(int wx, int wy) {
	printf("R\n");
	wTx = wx;
	wTy = wy;
	glViewport(0, 0, wx, wy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30.0, -30.0, 30.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 0x20:
		//aff = (aff + 1) % 2;
		glutPostRedisplay();
		break;
	case 0x1B:
		exit(0);
		break;
	}
}

static void special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		vy += 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		vy -= 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		vx -= 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		vx += 0.2;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		vz -= 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		vz += 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_F1:
		vx = 1.0;
		vy = 1.0;
		vz = 10.0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_F2:
		vx = 1.0;
		vy = 1.0;
		vz = -10.0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_F3:
		vx = 10.0;
		vy = 1.0;
		vz = 1.0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_F4:
		vx = -10.0;
		vy = 1.0;
		vz = 1.0;
		glutPostRedisplay();
		break;
	case GLUT_KEY_F5:
		voiture->changePos(5, 2);
		glutPostRedisplay();
		break;
	case GLUT_KEY_F6:
		voiture->echap++;
		if (voiture->echap > voiture->nbEchap) {
			voiture->echap = 1;
		}
		voiture->rotRoue -= 30;
		if (voiture->rotRoue == 0) {
			voiture->rotRoue = 360;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_F10:
		if (colorMat == 0) {
			glEnable(GL_COLOR_MATERIAL);
			colorMat = 1;
		}
		else {
			glDisable(GL_COLOR_MATERIAL);
			colorMat = 0;
		}
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(wTx, wTy);
	glutInitWindowPosition(wPx, wPy);
	glutCreateWindow("Gestion événementielle de GLUt");
	init();
	//glutPassiveMotionFunc(passiveMouseMotion);
	glutReshapeFunc(reshape);
	//glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMainLoop();
	return(0);
}