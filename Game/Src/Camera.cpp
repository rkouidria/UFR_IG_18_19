/* Programme principal projet Circuit automobile                     */

/* Auteur: Gauthier FERRE Rémi Kouidria                       */

/* Mars 2019                                 */

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.h"
#include "Pos3D.h"

/* Variables globales                           */



Camera::Camera() {}
Camera::~Camera() {}


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