#pragma once

#include "Terrain.h"
#include "Pos3D.h"

class Terrain
{
public:
	Terrain();
	~Terrain();

	void Terrain::LoadGrid(int lon, int lar);
	void Terrain::LoadRoad();
	void Terrain::DrawStraight(Pos3D & pos, int lar, int lon);
	void Terrain::LoadGap(int lon, int lar);
	void Terrain::DrawVirage(Pos3D &pos, int choix);


};