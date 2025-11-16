// Auteur : Ahmed Boukra Bettayeb
// Version : 3.0
// Date : 04/11/2025
// Classe Carre - Implementation

//#include "stdafx.h"
#include "Carre.h"
#include <iostream>
using namespace std;

// Constructeur
Carre::Carre() : Rectangle(0.0, 0.0){
   this->SaisirDimension();
}

Carre::Carre(double mCote) : Rectangle(mCote, mCote){
   this->cote = mCote;
}

//destructeur
Carre::~Carre() {
    cout << " Destruction d'un objet de type Carre " << endl;
}
void Carre::SaisirDimension()
{
	double mCote;

	do
	{
		cout << "Entrez la longueur du cote du carre: \n" << endl;
		cin >> mCote;
	} while(mCote < 0.0);

	this->cote = mCote;
	this->setLongueur(this->cote);
	this->setLargeur(this->cote);
	this->CalculerSurface();
	this->CalculerPerimetre();
}

void Carre::SaisirDimension(double a)
{
	this->cote = a;
	this->setLongueur(this->cote);
	this->setLargeur(this->cote);
	this->CalculerSurface();
	this->CalculerPerimetre();
}

