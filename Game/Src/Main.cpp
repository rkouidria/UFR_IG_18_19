/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE Rémi KOUIDRIA                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Terrain.h"
#include "Commande.h"
#include "Camera.h"
#include "Pos3D.h"
#include "Tmp.h"

/*  Création des objet instanciés */
Terrain *terrain = new Terrain();
Commande *cmd = new Commande();
Camera *camera1 = new Camera();
Camera *camera2 = new Camera();
Tmp *car = new Tmp();

/* Variables globales */
const float PI = 3.1415926;			// Variable mathématique PI
int numCam = 1;						// Numéro de caméra active

static int wTx = 900;              // Resolution horizontale de la fenetre
static int wTy = 560;              // Resolution verticale de la fenetre
static int wPx = 50;               // Position horizontale de la fenetre
static int wPy = 50;               // Position verticale de la fenetre

const float gridX = 500.0F;			// Taille plateau en X : 1X == 1 metre
const float gridZ = 500.0F;			// Taille plateau en Z : 1Z == 1 metre
const float distCam = 500.0F;		// Distance de la caméra 1


static void init(void) {

	glDepthFunc(GL_LESS);		/* Elimination des parties cachées moins profond */
	glEnable(GL_DEPTH_TEST);	/* Active l'élination des PC */
	glEnable(GL_NORMALIZE);		/* Normalise les vecteurs pour calculs illum. */
	
	/* Initialisation des objets instanciés */
	//car->Init(250, 1, -250, 10);
	car->Init(350, 1, -420, 10);
	camera1->CameraInit((int)gridX / 2, (int)gridX / 2, (int)-gridZ / 2, (int)gridX / 2,0, (int)-gridZ / 2,91,1,1,700);
	camera2->CameraInit(car->pos.px, (int)gridX / 10, car->pos.pz, car->pos.px, car->pos.py, car->pos.pz, 2, 1, 1, 700);
	
}

void scene(void) {

	glPushMatrix();
	terrain->LoadGrid(gridX, gridZ);
	terrain->LoadGap(gridX, gridZ);
	terrain->LoadRoad();
	car->Draw();
	glPopMatrix();
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

static void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	switch (numCam) {
		case 1 : 
			gluLookAt(camera1->posCam.px, camera1->posCam.py, camera1->posCam.pz, camera1->posEye.px, camera1->posEye.py, camera1->posEye.pz, 1, 0, 0);
			break;
		case 2: 
			camera2->UpdateCamera2(*car);
			gluLookAt(camera2->posCam.px, camera2->posCam.py, camera2->posCam.pz, camera2->posEye.px, camera2->posEye.py, camera2->posEye.pz, 1, 0, 0);
			break;
	}
	
	scene();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	int error = glGetError();
	error = glGetError();
	if (error != GL_NO_ERROR)
		printf("Attention erreur %d\n", error);
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

static void reshape(int wx, int wy) {
	wTx = wx;
	wTy = wy;
	glViewport(0, 0, wx, wy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (numCam) {
		case 1: gluPerspective(camera1->fov, camera1->ratio, camera1->cmin, camera1->cmax);
			break;
		case 2: gluPerspective(camera2->fov, camera2->ratio, camera2->cmin, camera2->cmax);
			break;
	}

	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

/*	Fonction executee lors de l'appui 
	d'une touche alphanumerique du clavier */
static void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	/* permet de switch de camera */
	case 'c': 
		numCam == 2 ? numCam = 1 : numCam++;
		glutPostRedisplay();
		break;
	}
}

/* Fonction executee lors de l'appui            */
/* d'une touche speciale du clavier :           */
/*   - touches de curseur                       */
/*   - touches de fonction                      */

static void special(int specialKey, int x, int y) {
	cmd->CarMoveSpecial(specialKey, *car);
}

/* Fonction exécutée automatiquement            */
/* lors de l'exécution de la fonction exit()    */

static void clean(void) {
	printf("Goodbye\n");
}

/* Fonction principale                          */

int main(int argc, char **argv) {

	atexit(clean);	/* A faire en cas d'exit */

	glutInit(&argc, argv);	/* Initialise la librairie glut */
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(wTx, wTy);
	glutInitWindowPosition(wPx, wPy);
	glutCreateWindow("Course sur circuit");

	init();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}
