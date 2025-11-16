// Auteur : Ahmed Boukra Bettayeb
// Version : 2.0
// Date : 14/10/2025
// Classe Rectangle - Declaration

#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE

#pragma once
#include <iostream>
#include "forme.h"
using namespace std;

class Rectangle : public forme
{
private:
    static int compteur;
    static int decrementer;
    double Longueur;
    double Largeur;
    double surface, Perimetre;

    void SaisirLongueur();
    void SaisirLargeur();

protected:
    void setLongueur(double Long);
    void setLargeur(double Large);
    void CalculerSurface();
    void CalculerPerimetre();


public:
    Rectangle(double Long = 1, double Large = 1);
    ~Rectangle();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1, double _dim2) override;
    double getSurface() const override;
    double getPerimetre() const override;

    static int getCompteurRectangle();
    static void incrementerCompteur();
    static void decrementerCompteur();

};

#endif