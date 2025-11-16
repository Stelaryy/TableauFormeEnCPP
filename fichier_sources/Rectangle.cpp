//	Auteur : Wilfrid Grassi
//	Version : 1.1
//	Date 13/09/2016
//	Objet : Definition des methodes de la classe Rectangle 
//			Calcul de Perimetre et de surface
//			Instanciation statique des objets (pas de pointeurs)

//#include "stdafx.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(double Long, double Large)
{
	this->setLongueur(Long);
	this->setLargeur(Large);
}

Rectangle::~Rectangle()
{
	cout << "Suppression de la memoire d un objet Rectangle ..." << endl;
}

void Rectangle::setLongueur(double Long)
{
	this->Longueur = Long;
	this->CalculerSurface();
	this->CalculerPerimetre();
}

void Rectangle::setLargeur(double Large)
{
	this->Largeur = Large;
	this->CalculerSurface();
	this->CalculerPerimetre();
}

void Rectangle::SaisirLongueur()
{
	double Long;

	do
	{
		cout << "Entrez la longueur du rectangle: " << endl;
		cin >> Long;
	} while (Long < 0.0);

	this->Longueur = Long;
	this->CalculerSurface();
	this->CalculerPerimetre();
}

void Rectangle::SaisirLargeur()
{
	double Large;

	do
	{
		cout << "Entrez la largeur du rectangle: " << endl;
		cin >> Large;
	} while (Large < 0.0);

	this->Largeur = Large;
	this->CalculerSurface();
	this->CalculerPerimetre();
}

void Rectangle::SaisirDimension()
{
	this->SaisirLongueur();
	this->SaisirLargeur();
}

void Rectangle::SaisirDimension(double _dim1, double _dim2)
{
	this->setLongueur(_dim1);
	this->setLargeur(_dim2);
}

void Rectangle::CalculerPerimetre()
{
	this->Perimetre = (2 * this->Longueur) + (2 * this->Largeur);
}

void Rectangle::CalculerSurface()
{
	this->surface = this->Longueur * this->Largeur;
}

double Rectangle::getSurface() const
{
	return(this->surface);
}

double Rectangle::getPerimetre() const
{
	return(this->Perimetre);
}


