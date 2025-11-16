// Auteur : Ahmed Boukra Bettayeb
// Version : 2.1
// Date : 14/10/2025
// Classe HexagoneIrregulier - Implémentation

#include "HexagoneIrregulier.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// -----------------------------
// Compteurs
// -----------------------------
int HexagoneIrregulier::compteur = 0;
int HexagoneIrregulier::decrementer = 0;

int HexagoneIrregulier::getCompteurHexagone() { return compteur; }
void HexagoneIrregulier::incrementerCompteur() { compteur++; }
void HexagoneIrregulier::decrementerCompteur() { decrementer--; }

// --------------------------------------------------
// Constructeur avec tableau de sommets
// --------------------------------------------------
HexagoneIrregulier::HexagoneIrregulier(const double s[6][2])
{
    incrementerCompteur();

    for (int i = 0; i < 6; i++)
        setSommet(i, s[i][0], s[i][1]);

    CalculerPerimetre();
    CalculerSurface();

    cout << "Creation d un HexagoneIrregulier via tableau de sommets." << endl;
    cout << "Hexagones en memoire : " << compteur << endl;
}

// --------------------------------------------------
// Constructeur par saisie
// --------------------------------------------------
HexagoneIrregulier::HexagoneIrregulier()
{
    incrementerCompteur();

    cout << "Saisie des 6 sommets de l hexagone :" << endl;
    for (int i = 0; i < 6; i++)
        SaisirSommet(i);

    CalculerPerimetre();
    CalculerSurface();

    cout << "Creation d un HexagoneIrregulier (saisie manuelle)." << endl;
    cout << "Hexagones en memoire : " << compteur << endl;
}

// --------------------------------------------------
// Destructeur
// --------------------------------------------------
HexagoneIrregulier::~HexagoneIrregulier()
{
    decrementerCompteur();
    cout << "Destruction d un HexagoneIrregulier." << endl;
    cout << "Hexagones restants : " << compteur << endl;
}

// --------------------------------------------------
// Setters protégés
// --------------------------------------------------
void HexagoneIrregulier::setSommet(int index, double x, double y)
{
    if (index < 0 || index >= 6)
        throw invalid_argument("Index de sommet invalide.");

    sommets[index][0] = x;
    sommets[index][1] = y;
}

// --------------------------------------------------
// Méthodes privées de saisie
// --------------------------------------------------
void HexagoneIrregulier::SaisirSommet(int index)
{
    double x, y;
    cout << "Sommet " << index + 1 << " (x y) : ";
    cin >> x >> y;
    setSommet(index, x, y);
}

// --------------------------------------------------
// Calcul du périmètre
// --------------------------------------------------
void HexagoneIrregulier::CalculerPerimetre()
{
    perimetre = 0.0;

    for (int i = 0; i < 6; i++)
    {
        int j = (i + 1) % 6;
        double dx = sommets[j][0] - sommets[i][0];
        double dy = sommets[j][1] - sommets[i][1];
        perimetre += sqrt(dx * dx + dy * dy);
    }
}

// --------------------------------------------------
// Calcul de la surface (méthode du « shoelace »)
// --------------------------------------------------
void HexagoneIrregulier::CalculerSurface()
{
    double somme = 0.0;

    for (int i = 0; i < 6; i++)
    {
        int j = (i + 1) % 6;
        somme += sommets[i][0] * sommets[j][1]
               - sommets[j][0] * sommets[i][1];
    }

    surface = fabs(somme) / 2.0;
}

// --------------------------------------------------
// Méthodes publiques héritées
// --------------------------------------------------
void HexagoneIrregulier::SaisirDimension()
{
    cout << "Saisie des 6 sommets de l hexagone :" << endl;

    for (int i = 0; i < 6; i++)
        SaisirSommet(i);

    CalculerPerimetre();
    CalculerSurface();
}

double HexagoneIrregulier::getSurface() const
{
    return surface;
}

double HexagoneIrregulier::getPerimetre() const
{
    return perimetre;
}
