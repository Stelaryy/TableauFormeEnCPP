// Auteur : Ahmed Boukra Bettayeb
// class TriangleQuelconque
// date : 2025-11-25

#include "TriangleQuelconque.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

constexpr double PI = 3.14159265358979323846;
int TriangleQuelconque::compteur = 0;

void TriangleQuelconque::incrementerCompteur(){ compteur++; }
void TriangleQuelconque::decrementerCompteur(){ compteur--; }
int TriangleQuelconque::getCompteurTriangle(){ return compteur; }

bool TriangleQuelconque::estValide(double A,double B,double C) const {
    return A>0 && B>0 && C>0 && A+B> C && A+C> B && B+C> A;
}

TriangleQuelconque::TriangleQuelconque(double A,double B,double C)
    : a(A), b(B), c(C), surface(0), perimetre(0)
{
    incrementerCompteur();
    if (!estValide(A,B,C)) throw invalid_argument("Triangle invalide");
    CalculerPerimetre(); CalculerSurface();
    cout << "Creation Triangle (3 cotes). total formes=" << forme::compteurFormes << endl;
}

TriangleQuelconque::TriangleQuelconque(double A,double B,double angleDegres,bool fromAngle)
    : a(0), b(0), c(0), surface(0), perimetre(0)
{
    incrementerCompteur();
    if (!fromAngle) throw invalid_argument("fromAngle doit etre vrai");
    double angleRad = angleDegres * PI / 180.0;
    double C = sqrt(A*A + B*B - 2*A*B*cos(angleRad));
    if (!estValide(A,B,C)) throw invalid_argument("Triangle invalide (angle)");
    a=A; b=B; c=C;
    CalculerPerimetre(); CalculerSurface();
    cout << "Creation Triangle (2 cotes + angle). total formes=" << forme::compteurFormes << endl;
}

TriangleQuelconque::~TriangleQuelconque(){
    decrementerCompteur();
    cout << "Destruction d'un Triangle." << endl;
}

void TriangleQuelconque::setA(double A){ if (A<=0) throw invalid_argument("A>0"); a=A; }
void TriangleQuelconque::setB(double B){ if (B<=0) throw invalid_argument("B>0"); b=B; }
void TriangleQuelconque::setC(double C){ if (C<=0) throw invalid_argument("C>0"); c=C; }

void TriangleQuelconque::CalculerPerimetre(){ perimetre = a + b + c; }
void TriangleQuelconque::CalculerSurface(){
    double p = perimetre / 2.0;
    surface = sqrt(p*(p-a)*(p-b)*(p-c));
}

void TriangleQuelconque::SaisirCoteA(){ do{ cout<<"cote A (>0): "; cin>>a; } while (a<=0); }
void TriangleQuelconque::SaisirCoteB(){ do{ cout<<"cote B (>0): "; cin>>b; } while (b<=0); }
void TriangleQuelconque::SaisirCoteC(){ do{ cout<<"cote C (>0): "; cin>>c; } while (c<=0); }

void TriangleQuelconque::SaisirDimension(){
    SaisirCoteA(); SaisirCoteB(); SaisirCoteC();
    if (!estValide(a,b,c)) throw invalid_argument("Triangle invalide");
    CalculerPerimetre(); CalculerSurface();
}

void TriangleQuelconque::SaisirDimension(double _dim1){
    // sensible: on lit 2 autres côtés
    a = _dim1;
    SaisirCoteB(); SaisirCoteC();
    if (!estValide(a,b,c)) throw invalid_argument("Triangle invalide");
    CalculerPerimetre(); CalculerSurface();
}

void TriangleQuelconque::SaisirDimension(double _dim1, double _dim2){
    // on calcule côté c par loi des cosinus en demandant un angle? ici on suppose côté3 = third
    a = _dim1; b = _dim2;
    SaisirCoteC();
    if (!estValide(a,b,c)) throw invalid_argument("Triangle invalide");
    CalculerPerimetre(); CalculerSurface();
}

void TriangleQuelconque::SaisirDimension(double _dim1, double _dim2, double _dim3){
    if (!estValide(_dim1,_dim2,_dim3)) throw invalid_argument("Triangle invalide");
    setA(_dim1); setB(_dim2); setC(_dim3);
    CalculerPerimetre(); CalculerSurface();
}

double TriangleQuelconque::getSurface() const { return surface; }
double TriangleQuelconque::getPerimetre() const { return perimetre; }
double TriangleQuelconque::getA() const { return a; }
double TriangleQuelconque::getB() const { return b; }
double TriangleQuelconque::getC() const { return c; }
