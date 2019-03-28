#pragma once

#include "Tmp.h"
#include "Pos3D.h"

class Tmp
{
public:
	Tmp();
	~Tmp();

	void Tmp::Draw();
	void Tmp::Init(int x, int y , int z, int rot);
	Pos3D pos;
	int rot;
	float acc;
	float dir;



	
};
