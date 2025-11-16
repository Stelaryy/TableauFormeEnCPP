// Auteur : Ahmed Boukra Bettayeb
// Version : 3.0
// Date : 08/11/2025
// Classe Cercle - Declaration
#ifndef DEF_CERCLE
#define DEF_CERCLE

#pragma once
#include <iostream>
#include "Ellipse.h"

class Cercle : public Ellipse {
private:
    double rayon;

public:
    // Constructeur
    Cercle();
    Cercle(double r);
    ~Cercle();

    // Getter
    double getRayon() const;

    // Methodes
    double getSurface() const;
    double getPerimetre() const;

    //compteur

};

#endif


