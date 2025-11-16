#include "Cercle.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

constexpr double PI = 3.14159265358979323846;

Cercle::Cercle() : Ellipse(1.0,1.0), rayon(1.0) {
    cout << "Creation d'un Cercle par defaut." << endl;
}

Cercle::Cercle(double r) : Ellipse(r, r), rayon(r) {
    if (r <= 0) throw invalid_argument("Rayon doit etre positif");
    cout << "Creation d'un Cercle. rayon=" << rayon << endl;
}

Cercle::~Cercle() {
    cout << "Destruction d'un Cercle." << endl;
}

void Cercle::SaisirDimension() {
    double r;
    do { cout << "Entrez le rayon (>0): "; cin >> r; } while (r <= 0);
    rayon = r;
    SaisirDimension(r);
}

void Cercle::SaisirDimension(double _dim1) {
    rayon = _dim1;
    // mettre à jour ellipse aussi
    Ellipse::SaisirDimension(_dim1, _dim1);
}

void Cercle::SaisirDimension(double _dim1, double _dim2) {
    // si deux valeurs: prendre la première comme rayon
    SaisirDimension(_dim1);
}

void Cercle::SaisirDimension(double, double, double) {
    // no-op
}

double Cercle::getSurface() const {
    return PI * rayon * rayon;
}

double Cercle::getPerimetre() const {
    return 2 * PI * rayon;
}
