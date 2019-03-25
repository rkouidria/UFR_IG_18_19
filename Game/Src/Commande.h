#pragma once

#include "Commande.h"
#include "Camera.h"

class Commande
{
public:
	
	Commande();
	~Commande();

	int camPOSX;
	int camPOSY;
	int camPOSZ;

	void CommandeInit(int x, int y, int z);
	void Commande::CamMoveSpecial(int sk, Camera &cam);
	void Commande::CamMove(int sk, int gridX, int gridZ, Camera &cam);

	
};


