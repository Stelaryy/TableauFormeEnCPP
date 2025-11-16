#include "Carre.h"
#include <iostream>
using namespace std;

// ===== Définition du compteur statique =====
int Carre::compteurCarre = 0;

// ===== Fonctions statiques =====
void Carre::incrementerCompteur() { compteurCarre++; }
void Carre::decrementerCompteur() { compteurCarre--; }
int Carre::getCompteurCarre() { return compteurCarre; }

// ===== Constructeur par défaut (OBLIGATOIRE) =====
Carre::Carre() : Rectangle(1, 1)
{
    incrementerCompteur();
    forme::incrementerFormes();

    cout << "Creation d'un Carre (defaut). Compteur : " << compteurCarre
         << ", total formes : " << forme::compteurFormes << endl;
}

// ===== Constructeur avec côté =====
Carre::Carre(double cote) : Rectangle(cote, cote)
{
    incrementerCompteur();
    forme::incrementerFormes();

    cout << "Creation d'un Carre. Compteur : " << compteurCarre
         << ", total formes : " << forme::compteurFormes << endl;
}

// ===== Destructeur =====
Carre::~Carre()
{
    decrementerCompteur();
    forme::decrementerFormes();

    cout << "Suppression d'un Carre. Restants : " << compteurCarre
         << ", total formes : " << forme::compteurFormes << endl;
}

// ===== Saisies =====
void Carre::SaisirDimension()
{
    double c;
    do {
        cout << "Cote du carre : ";
        cin >> c;
    } while (c <= 0);

    this->setLongueur(c);
    this->setLargeur(c);
}

void Carre::SaisirDimension(double _dim1)
{
    this->setLongueur(_dim1);
    this->setLargeur(_dim1);
}

void Carre::SaisirDimension(double _dim1, double _dim2)
{
    // Un carré : un seul côté, on ignore _dim2
    this->setLongueur(_dim1);
    this->setLargeur(_dim1);
}

void Carre::SaisirDimension(double, double, double)
{
    // Obligatoire même vide sinon le linker plante
}
