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

Terrain *terrain = new Terrain();
Commande *cmd = new Commande();
Camera *camera1 = new Camera();

/* Variables globales                           */
const float PI = 3.1415926535897932384626433832795;
const float marge = 2.0F;

static int wTx = 900;              // Resolution horizontale de la fenetre
static int wTy = 560;              // Resolution verticale de la fenetre
static int wPx = 50;               // Position horizontale de la fenetre
static int wPy = 50;               // Position verticale de la fenetre

const float gridX = 500.0F;				// Taille plateau en X : 1X == 1 metre
const float gridZ = 500.0F;				// Taille plateau en Z : 1Z == 1 metre

const float distCam = 500.0F;
//const float fov =  ((atan((gridX / 2.0F)/distCam))*(360.F/PI)) + marge;			// Taille ouverture caméra
const float fov = 90 + marge;			// Taille ouverture caméra
const float tmpFov = 15;	/* Pour reglage temporaire afin de mieux y voir */
const float fovRatio = atan((gridX / 2.0F) / distCam) / atan((gridZ / 2.0F) / distCam); // Ratio d'ouverture vertical




								   /* Fonction d'initialisation des parametres     */
								   /* OpenGL ne changeant pas au cours de la vie   */
								   /* du programme                                 */

static const GLfloat blanc[] = { 1.0,1.0,1.0,1.0 };

static void init(void) {

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
	glEnable(GL_LIGHTING);		/* Activation des éclairages */
	glEnable(GL_LIGHT0);		/* Une seule lumière : Soleil */
	glDepthFunc(GL_LESS);		/* Elimination des parties cachées moins profond */
	glEnable(GL_DEPTH_TEST);	/* Active l'élination des PC */
	glEnable(GL_NORMALIZE);		/* Normalise les vecteurs pour calculs illum. */
	glClearColor(0.25,0.25,0.25,1.0);
	//
	//cmd->CommandeInit((int)gridX / 2, (int)gridX / 2, (int)-gridZ / 2 );
	camera1->CameraInit((int)gridX / 2, (int)gridX / 2, (int)-gridZ / 2);

}

void scene(void) {

	glPushMatrix();
	terrain->LoadGrid(gridX, gridZ);
	//terrain->LoadGap(gridX, gridZ);
	glPopMatrix();
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

static void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(camera1->camPOSX, camera1->camPOSY, camera1->camPOSZ, camera1->camPOSX, 0, camera1->camPOSZ, 1, 0, 0);
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

	gluPerspective(fov, fovRatio, 1.0, 700);
	printf("\n fov : %f     ration : %f\n   gridX = %f      gridZ = %f\n",fov, fovRatio, gridX,gridZ);
	printf("dist : %f     \n", distCam);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */

static void keyboard(unsigned char key, int x, int y) {
	cmd->CamMove(key, gridX, gridZ,*camera1);
	

}

/* Fonction executee lors de l'appui            */
/* d'une touche speciale du clavier :           */
/*   - touches de curseur                       */
/*   - touches de fonction                      */

static void special(int specialKey, int x, int y) {
	cmd->CamMoveSpecial(specialKey, *camera1);
	printf("Camera poisition = (%i ; %i ; %i)\n", camera1->camPOSX, camera1->camPOSY, camera1->camPOSZ);
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
