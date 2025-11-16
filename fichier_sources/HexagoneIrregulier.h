// Auteur : Ahmed Boukra Bettayeb
// Version : 2.1
// Date : 14/10/2025
// Classe HexagoneIrregulier - Déclaration

#ifndef DEF_HEXAGONEIRREGULIER
#define DEF_HEXAGONEIRREGULIER

#pragma once
#include <iostream>
#include "forme.h"
using namespace std;

class HexagoneIrregulier : public forme
{
private:
    static int compteur;
    static int decrementer;

    // 6 sommets : sommets[i][0] = x , sommets[i][1] = y
    double sommets[6][2];

    // valeurs géométriques
    double surface;
    double perimetre;

    // Méthodes privées de saisie
    void SaisirSommet(int index);

protected:
    // Setters protégés
    void setSommet(int index, double x, double y);

    // Calculs géométriques internes
    void CalculerPerimetre();
    void CalculerSurface();

public:
    // Constructeur avec tableau 6x2
    HexagoneIrregulier(const double s[6][2]);

    // Constructeur par saisie
    HexagoneIrregulier();

    // Destructeur
    ~HexagoneIrregulier();

    // Méthodes héritées de forme
    void SaisirDimension() override;                         // saisir les 6 sommets
    void SaisirDimension(double _dim1) override {}           // non utilisé
    void SaisirDimension(double _dim1, double _dim2) override {} 
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override {}

    double getSurface() const override;
    double getPerimetre() const override;

    // Méthodes statiques
    static int getCompteurHexagone();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
