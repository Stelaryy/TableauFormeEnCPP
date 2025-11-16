#ifndef DEF_CARRE
#define DEF_CARRE

#pragma once
#include "Rectangle.h"

class Carre : public Rectangle {
private:
    static int compteurCarre;

public:
    // Constructeurs
    Carre();             // Constructeur par défaut OBLIGATOIRE
    Carre(double cote);  // Constructeur avec un côté unique

    // Destructeur
    ~Carre();

    // Méthodes de saisie
    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    // Gestion compteur
    static int getCompteurCarre();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
