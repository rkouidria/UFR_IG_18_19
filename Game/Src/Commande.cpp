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

void Commande::CamMoveSpecial(int sk, Camera &cam) {
	switch (sk) {
	case GLUT_KEY_UP:
		cam.camPOSX += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		cam.camPOSX -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		cam.camPOSZ -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		cam.camPOSZ += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		cam.camPOSY -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		cam.camPOSY += 1;
		glutPostRedisplay();
		break;
	}

}

void Commande::CamMove(int sk, int gridX, int gridZ, Camera &cam) {
	switch (sk) {
	case 'o':
		printf("Camera's back to origin\n");
		cam.camPOSX = gridX / 2;
		cam.camPOSY = gridX / 2;
		cam.camPOSZ = -gridZ / 2;
		glutPostRedisplay();
		break;
	}
}

