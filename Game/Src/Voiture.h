#pragma once

class Voiture
{
public:

	double posVX;
	double posVZ;

	double angleV;
	float rotRoue;

	double tailleVX;
	double tailleVZ;
	double tailleVY;

	int echap;
	int nbEchap;

	char* nom;

	Voiture(void);
	Voiture(double x, double z);
	Voiture(double x, double z, double tx, double tz, double ty);
	~Voiture();
	void changePos(double x, double z);
	void affVoiture();
	void toString();

private:
	void init(double x, double z, double tx, double tz, double ty);
	void vitreAvant();
	void cote();
	void coteDroit();
	void coteGauche();
	void pareBrise();
	void capo();
	void coffre();
	void pavillion();
	void interieur();
	void facePneu(double hauteur, double r1, double r2, int ns);
	void roue(float x, float y, float z);
	void jeuDeRoue();
	void pot();
	void echappement(int etat);
	void basDeCaisse();

	//void Voiture::CameraInit(int x, int y, int z);


};
