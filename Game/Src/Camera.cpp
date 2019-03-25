/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE Rémi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.h"

/* Variables globales                           */



Camera::Camera() {}
Camera::~Camera() {}


void Camera::CameraInit(int x, int y, int z) {
	camPOSX = x;
	camPOSY = y;
	camPOSZ = z;
}
/*

void Commande::CamMoveSpecial(int sk) {
	switch (sk) {
	case GLUT_KEY_UP:
		camPOSX += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		camPOSX -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		camPOSZ -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		camPOSZ += 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		camPOSY -= 1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		camPOSY += 1;
		glutPostRedisplay();
		break;
	}

}

void Commande::CamMove(int sk, int gridX, int gridZ) {
	switch (sk) {
	case 'o':
		printf("Camera's back to origin\n");
		camPOSX = gridX / 2;
		camPOSY = gridX / 2;
		camPOSZ = -gridZ / 2;
		glutPostRedisplay();
		break;
	}
}*/

