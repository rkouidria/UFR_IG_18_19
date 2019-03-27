/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE Rémi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Commande.h"
#include "Camera.h"

/* Variables globales                           */



Commande::Commande() {}
Commande::~Commande() {}


void Commande::CommandeInit(int x, int y, int z) {
	camPOSX = x;
	camPOSY = y;
	camPOSZ = z;
}

/* ajouter autant d'agrument Camera, qu'il en existera */
void Commande::CamMoveSpecial(int sk, Camera &cam) {
	switch (sk) {
		/*  */
	case GLUT_KEY_UP:
		cam.posCam.px += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		cam.posCam.px -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		cam.posCam.pz -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		cam.posCam.pz += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		cam.posCam.py -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		cam.posCam.py += 1;
		glutPostRedisplay();
		break;
	}

}

void Commande::CamMove(int sk, int gridX, int gridZ, Camera &cam) {
	switch (sk) {
	case 'o':
		printf("Camera's back to origin\n");
		cam.posCam.px = gridX / 2;
		cam.posCam.py = gridX / 2;
		cam.posCam.pz = -gridZ / 2;
		glutPostRedisplay();
		break;
	}
}

