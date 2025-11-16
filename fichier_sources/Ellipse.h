// Auteur : Ahmed Boukra Bettayeb
// Version : 2.0
// Date : 14/10/2025
// Classe Ellipse - Déclaration

#ifndef ELLIPSE_H 
#define ELLIPSE_H

#pragma once
#include <iostream>
#include <cmath>
#include "forme.h"

class Ellipse : public forme {
private:
    double GrandAxe; 
    double PetitAxe; 
    double Surface;
    double Perimetre;

    void SaisirGrandAxe();
    void SaisirPetitAxe();

protected:
    void setGrandAxe(double GrandAxe);
    void setPetitAxe(double PetitAxe);
    void CalculerSurface();
    void CalculerPerimetre();
    
public:
    // Constructeur
    Ellipse(double GrandAxe = 0, double PetitAxe = 0);
    ~Ellipse();

    void SaisirDimension() override;
    void SaisirDimension(double GrandAxe, double PetitAxe) override;
    double getSurface() const override;
    double getPerimetre() const override;

};

#endif
