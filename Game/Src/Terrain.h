#pragma once

#include "Terrain.h"

class Terrain
{
public:
	Terrain();
	~Terrain();

	void Terrain::LoadGrid(int lon, int lar);
	void Terrain::LoadGap(int lon, int lar);
	

private:
	int id_Skybox;
};