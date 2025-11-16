// Auteur : Ahmed Boukra Bettayeb
// Version : 3.2
// Date : 08/11/2025
// Classe Ellipse - Implémentation

#include "ellipse.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

constexpr double PI = 3.14159265358979323846;

// -----------------------------
// Constructeur
// -----------------------------
Ellipse::Ellipse(double A, double B)
    : GrandAxe(A), PetitAxe(B)
{
    if (A <= 0 || B <= 0)
        throw invalid_argument("Les axes doivent etre positifs.");

    CalculerSurface();
    CalculerPerimetre();

    cout << "Creation d une ellipse : "
         << "GrandAxe = " << GrandAxe
         << ", PetitAxe = " << PetitAxe << endl;
}

// -----------------------------
// Destructeur
// -----------------------------
Ellipse::~Ellipse() {
    cout << "Destruction d une ellipse." << endl;
}

// -----------------------------
// Méthodes protégées
// -----------------------------
void Ellipse::setGrandAxe(double A) {
    if (A <= 0)
        throw invalid_argument("Le grand axe doit être positif.");
    GrandAxe = A;
}

void Ellipse::setPetitAxe(double B) {
    if (B <= 0)
        throw invalid_argument("Le petit axe doit être positif.");
    PetitAxe = B;
}

void Ellipse::CalculerSurface() {
    Surface = PI * GrandAxe * PetitAxe;
}

void Ellipse::CalculerPerimetre() {
    // Formule approchée de Ramanujan
    Perimetre = PI * (3 * (GrandAxe + PetitAxe) -
                      sqrt((3 * GrandAxe + PetitAxe) * (GrandAxe + 3 * PetitAxe)));
}

// -----------------------------
// Méthodes publiques
// -----------------------------
void Ellipse::SaisirDimension() {
    cout << "Entrez le grand axe : ";
    cin >> GrandAxe;
    cout << "Entrez le petit axe : ";
    cin >> PetitAxe;

    if (GrandAxe <= 0 || PetitAxe <= 0)
        throw invalid_argument("Les axes doivent etre positifs.");

    CalculerSurface();
    CalculerPerimetre();
}

void Ellipse::SaisirDimension(double A, double B) {
    setGrandAxe(A);
    setPetitAxe(B);
    CalculerSurface();
    CalculerPerimetre();
}

double Ellipse::getSurface() const {
    return Surface;
}

double Ellipse::getPerimetre() const {
    return Perimetre;
}
