#include "Ellipse.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

constexpr double PI = 3.14159265358979323846;

Ellipse::Ellipse(double A, double B)
    : GrandAxe(A), PetitAxe(B), surface(0), perimetre(0)
{
    if (A <= 0 || B <= 0) throw invalid_argument("Axes doivent etre positifs");
    CalculerSurface();
    CalculerPerimetre();
    cout << "Creation d'une Ellipse. a=" << GrandAxe << " b=" << PetitAxe
         << ", total formes=" << forme::compteurFormes << endl;
}

Ellipse::~Ellipse() {
    cout << "Destruction d'une Ellipse." << endl;
}

void Ellipse::CalculerSurface() {
    surface = PI * GrandAxe * PetitAxe;
}

void Ellipse::CalculerPerimetre() {
    perimetre = PI * (3*(GrandAxe + PetitAxe) - sqrt((3*GrandAxe + PetitAxe)*(GrandAxe + 3*PetitAxe)));
}

void Ellipse::SaisirDimension() {
    double a,b;
    do { cout << "Grand axe (>0): "; cin >> a; } while (a <= 0);
    do { cout << "Petit axe (>0): "; cin >> b; } while (b <= 0);
    GrandAxe = a; PetitAxe = b;
    CalculerSurface(); CalculerPerimetre();
}

void Ellipse::SaisirDimension(double _dim1) {
    // Saisir grand axe = _dim1, demander petit axe
    GrandAxe = _dim1;
    SaisirDimension();
}

void Ellipse::SaisirDimension(double _dim1, double _dim2) {
    GrandAxe = _dim1;
    PetitAxe = _dim2;
    CalculerSurface(); CalculerPerimetre();
}

void Ellipse::SaisirDimension(double /*_d1*/, double /*_d2*/, double /*_d3*/) {
    // non applicable (no-op)
}

double Ellipse::getSurface() const { return surface; }
double Ellipse::getPerimetre() const { return perimetre; }
