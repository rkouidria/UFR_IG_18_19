#pragma once

#include "Camera.h"
#include "Pos3D.h"
#include "Voiture.h"

class Camera
{
public:

	Camera();
	~Camera();

	Pos3D posCam;
	Pos3D posEye;
	int fov;
	int ratio;
	int cmin;
	int cmax;

	void Camera::CameraInit(int camX, int camY, int camZ, int eyeX, int eyeY,int eyeZ, int fovea, int ratio, int min, int max);
	void Camera::UpdateCamera2(Voiture &car);


};


