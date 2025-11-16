// Auteur : Ahmed Boukra Bettayeb
// Version : 2.0
// Date : 14/10/2025
// Classe TriangleQuelconque - Declaration

#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE

#pragma once
#include <iostream>
#include <cmath>
#include "forme.h"

class TriangleQuelconque : public forme
{
private:
    static int compteur;
    static int decrementer;

    double a;
    double b;
    double c;

    double surface;
    double Perimetre;

    // Méthodes privées de saisie internes
    void SaisirCoteA();
    void SaisirCoteB();
    void SaisirCoteC();

    // Vérifie que les 3 côtés forment un triangle
    bool estValide(double A, double B, double C) const;

protected:
    // Setters protégés comme dans Rectangle
    void setA(double A);
    void setB(double B);
    void setC(double C);

    // Méthodes de calcul protégées
    void CalculerSurface();
    void CalculerPerimetre();

public:
    // Constructeurs
    TriangleQuelconque(double A = 1, double B = 1, double C = 1);
    TriangleQuelconque(double A, double B, double angleDegres, bool fromAngle);

    ~TriangleQuelconque();

    // Méthodes héritées de forme
    void SaisirDimension() override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;

    // Getters publics
    double getA() const;
    double getB() const;
    double getC() const;

    // Compteurs statiques
    static int getCompteurTriangle();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
