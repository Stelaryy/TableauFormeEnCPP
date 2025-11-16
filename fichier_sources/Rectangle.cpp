#include "Rectangle.h"
#include <iostream>

using namespace std;

int Rectangle::compteur = 0;

void Rectangle::incrementerCompteur(){ compteur++; }
void Rectangle::decrementerCompteur(){ compteur--; }
int Rectangle::getCompteurRectangle(){ return compteur; }

Rectangle::Rectangle(double Long, double Large)
    : Longueur(Long), Largeur(Large), surface(0), perimetre(0)
{
    incrementerCompteur();
    // le compteur global est déjà incrémenté par forme::forme()
    CalculerSurface();
    CalculerPerimetre();
    cout << "Creation d'un Rectangle. Count=" << compteur
         << ", total formes=" << forme::compteurFormes << endl;
}

Rectangle::~Rectangle()
{
    decrementerCompteur();
    cout << "Suppression d'un Rectangle. Restants=" << compteur
         << ", total formes=" << forme::compteurFormes << endl;
}

void Rectangle::setLongueur(double Long) {
    Longueur = Long;
    CalculerSurface(); CalculerPerimetre();
}
void Rectangle::setLargeur(double Large) {
    Largeur = Large;
    CalculerSurface(); CalculerPerimetre();
}

void Rectangle::SaisirLongueur() {
    double L;
    do { cout << "Entrez la longueur (>0): "; cin >> L; } while (L <= 0);
    setLongueur(L);
}
void Rectangle::SaisirLargeur() {
    double L;
    do { cout << "Entrez la largeur (>0): "; cin >> L; } while (L <= 0);
    setLargeur(L);
}

void Rectangle::SaisirDimension() {
    SaisirLongueur();
    SaisirLargeur();
}

void Rectangle::SaisirDimension(double _dim1) {
    // Saisir longueur = _dim1, demander largeur
    setLongueur(_dim1);
    SaisirLargeur();
}

void Rectangle::SaisirDimension(double _dim1, double _dim2) {
    setLongueur(_dim1);
    setLargeur(_dim2);
}

void Rectangle::SaisirDimension(double _dim1, double _dim2, double _dim3) {
    // Pas applicable -> on prend les 2 premières valeurs
    setLongueur(_dim1);
    setLargeur(_dim2);
}

void Rectangle::CalculerSurface(){ surface = Longueur * Largeur; }
void Rectangle::CalculerPerimetre(){ perimetre = 2*(Longueur + Largeur); }

double Rectangle::getSurface() const { return surface; }
double Rectangle::getPerimetre() const { return perimetre; }
