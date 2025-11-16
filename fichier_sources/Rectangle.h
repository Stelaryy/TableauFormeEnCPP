#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE

#pragma once
#include <iostream>
#include "forme.h"

class Rectangle : public forme
{
private:
    static int compteur;
    double Longueur;
    double Largeur;
    double surface;
    double perimetre;

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
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;

    static int getCompteurRectangle();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
