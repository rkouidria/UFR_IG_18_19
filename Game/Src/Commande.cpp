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


/* Permet de déplaecr la voiture */
void Commande::CarMoveSpecial(int sk, Tmp &car) {
	switch (sk) {
		/*  */
	case GLUT_KEY_UP:
		if (car.acc <= 1) {
			car.acc += 0.1;
		}

		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		if (car.acc >= 0) {
			car.acc -= 0.1;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		if (car.dir <= 0.5) {
			car.dir += 0.1;
			car.rot += 9;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		if(car.dir >= -0.5) {
			car.dir -= 0.1;
			car.rot -= 9;
		}
		glutPostRedisplay();
		break;
	
	}

}




