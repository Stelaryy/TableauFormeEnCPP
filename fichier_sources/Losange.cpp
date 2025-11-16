// Auteur : Ahmed Boukra Bettayeb
// Version : 2.1
// Date : 14/10/2025
// Classe Losange - Implémentation

#include "Losange.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

constexpr double PI = 3.14159265358979323846;

// -----------------------------
// Constructeurs
// -----------------------------

// Constructeur par défaut (saisie du côté et de l’angle)
Losange::Losange() {
    SaisirCote();
    SaisirAngle();

    // Calcul automatique des diagonales
    d1 = 2 * cote * sin(angle / 2);
    d2 = 2 * cote * cos(angle / 2);

    // Calculs géométriques
    surface = cote * cote * sin(angle);
    perimetre = 4 * cote;

    cout << "Creation d'un losange (cote + angle saisis)." << endl;
}

// Constructeur via diagonales
Losange::Losange(bool fromDiagonales) {
    if (fromDiagonales) {
        SaisirDiagonal1();
        SaisirDiagonal2();

        cote = sqrt(pow(d1 / 2, 2) + pow(d2 / 2, 2));
        surface = (d1 * d2) / 2.0;
        perimetre = 4 * cote;

        cout << "Creation d un losange via diagonales." << endl;
    } else {
        SaisirCote();
        SaisirAngle();

        d1 = 2 * cote * sin(angle / 2);
        d2 = 2 * cote * cos(angle / 2);
        surface = cote * cote * sin(angle);
        perimetre = 4 * cote;

        cout << "Creation d un losange via cote + angle." << endl;
    }
}

// Destructeur
Losange::~Losange() {
    cout << "Destruction d un objet Losange." << endl;
}

// -----------------------------
// Setters protégés
// -----------------------------
void Losange::setDiagonal1(double Diagonal1) {
    if (Diagonal1 <= 0)
        throw invalid_argument("La diagonale 1 doit etre positive.");
    d1 = Diagonal1;
}

void Losange::setDiagonal2(double Diagonal2) {
    if (Diagonal2 <= 0)
        throw invalid_argument("La diagonale 2 doit etre positive.");
    d2 = Diagonal2;
}

void Losange::setCote(double _Cote) {
    if (_Cote <= 0)
        throw invalid_argument("Le cote doit etre positif.");
    cote = _Cote;
}

void Losange::setAngle(double Angle) {
    if (Angle <= 0 || Angle >= PI)
        throw invalid_argument("L angle doit etre compris entre 0 et 180 degres.");
    angle = Angle;
}

// -----------------------------
// Méthodes privées de saisie
// -----------------------------
void Losange::SaisirDiagonal1() {
    do {
        cout << "Entrez la premiere diagonale (d1 > 0) : ";
        cin >> d1;
    } while (d1 <= 0);
}

void Losange::SaisirDiagonal2() {
    do {
        cout << "Entrez la deuxieme diagonale (d2 > 0) : ";
        cin >> d2;
    } while (d2 <= 0);
}

void Losange::SaisirCote() {
    do {
        cout << "Entrez la longueur du cote (c > 0) : ";
        cin >> cote;
    } while (cote <= 0);
}

void Losange::SaisirAngle() {
    double deg;
    do {
        cout << "Entrez l angle en degres (0 < angle < 180) : ";
        cin >> deg;
    } while (deg <= 0 || deg >= 180);
    angle = deg * PI / 180.0; // conversion en radians
}

// -----------------------------
// Méthodes publiques héritées
// -----------------------------
void Losange::SaisirDimension(double _dim1) {
    // Saisie par côté uniquement → demande de l’angle ensuite
    setCote(_dim1);
    SaisirAngle();

    // Recalcul complet
    d1 = 2 * cote * sin(angle / 2);
    d2 = 2 * cote * cos(angle / 2);
    surface = cote * cote * sin(angle);
    perimetre = 4 * cote;
}

void Losange::SaisirDimension(double _dim1, double _dim2) {
    // Saisie par diagonales
    setDiagonal1(_dim1);
    setDiagonal2(_dim2);

    // Calculs géométriques
    cote = sqrt(pow(_dim1 / 2, 2) + pow(_dim2 / 2, 2));
    surface = (_dim1 * _dim2) / 2.0;
    perimetre = 4 * cote;
}

double Losange::getSurface() const {
    return surface;
}

double Losange::getPerimetre() const {
    return perimetre;
}
