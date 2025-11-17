#include "HexagoneIrregulier.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

int HexagoneIrregulier::compteur = 0;
void HexagoneIrregulier::incrementerCompteur(){ compteur++; }
void HexagoneIrregulier::decrementerCompteur(){ compteur--; }
int HexagoneIrregulier::getCompteurHexagone(){ return compteur; }

HexagoneIrregulier::HexagoneIrregulier(const double s[6][2]) : surface(0), perimetre(0) {
    incrementerCompteur();
    for (int i=0;i<6;i++){ setSommet(i, s[i][0], s[i][1]); }
    CalculerPerimetre(); CalculerSurface();
    cout << "Creation Hexagone via tableau. total formes=" << forme::compteurFormes << endl;
}

HexagoneIrregulier::HexagoneIrregulier() : surface(0), perimetre(0) {
    incrementerCompteur();
    cout << "Saisie des 6 sommets :" << endl;
    for (int i=0;i<6;i++) SaisirSommet(i);
    CalculerPerimetre(); CalculerSurface();
    cout << "Creation Hexagone (saisie). total formes=" << forme::compteurFormes << endl;
}

HexagoneIrregulier::~HexagoneIrregulier(){
    decrementerCompteur();
    cout << "Destruction Hexagone." << endl;
}

void HexagoneIrregulier::setSommet(int index, double x, double y){
    if (index<0 || index>=6) throw invalid_argument("index");
    sommets[index][0]=x; sommets[index][1]=y;
}

void HexagoneIrregulier::SaisirSommet(int index){
    double x,y;
    cout << "Sommet " << index+1 << " (x): ";
    cin >> x;
    cout << "Sommet " << index+1 << " (y): ";
    cin >> y;

    setSommet(index,x,y);
}

void HexagoneIrregulier::CalculerPerimetre(){
    perimetre = 0;
    for (int i=0;i<6;i++){
        int j=(i+1)%6;
        double dx = sommets[j][0]-sommets[i][0];
        double dy = sommets[j][1]-sommets[i][1];
        perimetre += sqrt(dx*dx + dy*dy);
    }
}
void HexagoneIrregulier::CalculerSurface(){
    double somme=0;
    for (int i=0;i<6;i++){
        int j=(i+1)%6;
        somme += sommets[i][0]*sommets[j][1] - sommets[j][0]*sommets[i][1];
    }
    surface = fabs(somme)/2.0;
}

void HexagoneIrregulier::SaisirDimension(){
    for (int i=0;i<6;i++) SaisirSommet(i);
    CalculerPerimetre(); CalculerSurface();
}
void HexagoneIrregulier::SaisirDimension(double _d1){ (void)_d1; /*no-op*/ }
void HexagoneIrregulier::SaisirDimension(double _d1,double _d2){ (void)_d1; (void)_d2; /*no-op*/ }
void HexagoneIrregulier::SaisirDimension(double,double,double){ /*no-op*/ }

double HexagoneIrregulier::getSurface() const { return surface; }
double HexagoneIrregulier::getPerimetre() const { return perimetre; }
