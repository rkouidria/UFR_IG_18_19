/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE R�mi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Camera.h"
#include "Pos3D.h"
#include "Tmp.h"

/* Variables globales */

Camera::Camera() {}
Camera::~Camera() {}

/* Initie la cam�ra */
void Camera::CameraInit(int camX, int camY, int camZ, int eyeX, int eyeY, int eyeZ, int fovea, int rat, int min, int max){
	posCam.px = camX;
	posCam.py = camY;
	posCam.pz = camZ;

	posEye.px = eyeX;
	posEye.py = eyeY;
	posEye.pz = eyeZ;

	fov = fovea;
	ratio = rat;
	cmin = min;
	cmax = max;
}

/* Maj donn�es de la cam�ra en fonction de l'emplacement de la voiture */
void Camera::UpdateCamera2(Tmp &car) {
	posCam.px = car.pos.px;
	posCam.py = 50;
	posCam.pz = car.pos.pz;

	posEye.px = car.pos.px;
	posEye.py = car.pos.py;
	posEye.pz = car.pos.pz;
}