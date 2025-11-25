// Auteur : Ahmed Boukra Bettayeb
// class Losange
// date : 2025-11-25

#include "Losange.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

constexpr double PI = 3.14159265358979323846;

Losange::Losange() : d1(0), d2(0), cote(0), angle(0), surface(0), perimetre(0) {
    SaisirCote();
    SaisirAngle();
    d1 = 2 * cote * sin(angle/2);
    d2 = 2 * cote * cos(angle/2);
    CalculerSurface(); CalculerPerimetre();
    cout << "Creation d'un Losange (cote+angle). total formes=" << forme::compteurFormes << endl;
}

Losange::Losange(bool fromDiagonales) : d1(0), d2(0), cote(0), angle(0), surface(0), perimetre(0) {
    if (fromDiagonales) {
        SaisirDiagonal1(); SaisirDiagonal2();
        cote = sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
        CalculerSurface(); CalculerPerimetre();
    } else {
        SaisirCote(); SaisirAngle();
        d1 = 2 * cote * sin(angle/2);
        d2 = 2 * cote * cos(angle/2);
        CalculerSurface(); CalculerPerimetre();
    }
    cout << "Creation d'un Losange. total formes=" << forme::compteurFormes << endl;
}

Losange::~Losange() {
    cout << "Destruction d'un Losange." << endl;
}

void Losange::setDiagonal1(double d) { if (d<=0) throw invalid_argument("d>0"); d1 = d; }
void Losange::setDiagonal2(double d) { if (d<=0) throw invalid_argument("d>0"); d2 = d; }
void Losange::setCote(double c) { if (c<=0) throw invalid_argument("c>0"); cote = c; }
void Losange::setAngle(double a) { if (a<=0 || a>=PI) throw invalid_argument("angle"); angle = a; }

void Losange::SaisirDiagonal1() { double x; do { cout<<"d1 (>0): "; cin>>x; } while(x<=0); d1 = x; }
void Losange::SaisirDiagonal2() { double x; do { cout<<"d2 (>0): "; cin>>x; } while(x<=0); d2 = x; }
void Losange::SaisirCote() { double x; do { cout<<"cote (>0): "; cin>>x; } while(x<=0); cote = x; }
void Losange::SaisirAngle() { double deg; do { cout<<"angle deg (0<deg<180): "; cin>>deg; } while(deg<=0||deg>=180); angle = deg * PI / 180.0; }

void Losange::CalculerSurface(){ surface = cote * cote * sin(angle); }
void Losange::CalculerPerimetre(){ perimetre = 4 * cote; }

void Losange::SaisirDimension() {
    SaisirCote(); SaisirAngle();
    d1 = 2 * cote * sin(angle/2);
    d2 = 2 * cote * cos(angle/2);
    CalculerSurface(); CalculerPerimetre();
}

void Losange::SaisirDimension(double _dim1) {
    setCote(_dim1);
    SaisirAngle();
    d1 = 2 * cote * sin(angle/2);
    d2 = 2 * cote * cos(angle/2);
    CalculerSurface(); CalculerPerimetre();
}

void Losange::SaisirDimension(double _dim1, double _dim2) {
    setDiagonal1(_dim1);
    setDiagonal2(_dim2);
    cote = sqrt((d1/2)*(d1/2) + (d2/2)*(d2/2));
    CalculerSurface(); CalculerPerimetre();
}

void Losange::SaisirDimension(double, double, double) {
    // no-op
}

double Losange::getSurface() const { return surface; }
double Losange::getPerimetre() const { return perimetre; }
