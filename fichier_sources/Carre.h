// Auteur : Ahmed Boukra Bettayeb
// Version : 2.0
// Date : 14/10/2025
// Classe Carre - Declaration
#ifndef DEF_CARRE
#define DEF_CARRE

#pragma once
#include <iostream>
#include "Rectangle.h"


class Carre : public Rectangle  {
private:
    //variable
    double cote;

public:
    // Constructeur
    Carre();
    Carre(double cote);
    ~Carre();
    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    
};
#endif


