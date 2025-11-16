// Auteur : Ahmed Boukra Bettayeb
// Version : 3.0
// Date : 08/11/2025
// Classe Cercle - Implémentation

#include "stdafx.h"
#include "Cercle.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

// Définition portable de PI
constexpr double PI = 3.14159265358979323846;

// Constructeurs
Cercle::Cercle() : Ellipse(0, 0), rayon(0) {
    cout << "Creation d un cercle par defaut (rayon = 0)" << endl;
}

Cercle::Cercle(double r) : Ellipse(r, r), rayon(r) {
    if (r <= 0)
        throw invalid_argument("Le rayon doit etre positif.");
    cout << "Creation d un objet de type Cercle, rayon = " << rayon << endl;
}

// Destructeur
Cercle::~Cercle() {
    cout << "Destruction d'un objet de type Cercle (rayon = " << rayon << ")" << endl;
}

// Getter
double Cercle::getRayon() const {
    return rayon;
}

// Surface : πr²
double Cercle::getSurface() const {
    return PI * rayon * rayon;
}

// Périmètre : 2πr
double Cercle::getPerimetre() const {
    return 2 * PI * rayon;
}
