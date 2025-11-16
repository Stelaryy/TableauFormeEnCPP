// Auteur : Ahmed Boukra Bettayeb
// Version : 2.1
// Date : 14/10/2025
// Classe Losange - Déclaration

#pragma once
#include "forme.h"
#include <stdexcept>

class Losange : public forme {
private:
    double d1 = 0.0;
    double d2 = 0.0;
    double cote = 0.0;
    double angle = 0.0;
    double surface = 0.0;
    double perimetre = 0.0;

    void SaisirDiagonal1();
    void SaisirDiagonal2();
    void SaisirCote();
    void SaisirAngle();

protected:
    void setDiagonal1(double d);
    void setDiagonal2(double d);
    void setCote(double c);
    void setAngle(double a);

public:
    // Constructeurs
    Losange();                                // par défaut
    Losange(bool fromDiagonales);      // true → diagonales, false → côté + angle
    ~Losange();

    // Méthodes
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    double getSurface() const override;
    double getPerimetre() const override;
};
