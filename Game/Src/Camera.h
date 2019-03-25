#pragma once

#include "Camera.h"

class Camera
{
public:

	Camera();
	~Camera();

	int camPOSX;
	int camPOSY;
	int camPOSZ;

	void Camera::CameraInit(int x, int y, int z);


};


