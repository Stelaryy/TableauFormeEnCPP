#ifndef DEF_HEXAGONEIRREGULIER
#define DEF_HEXAGONEIRREGULIER

#pragma once
#include "forme.h"

class HexagoneIrregulier : public forme {
private:
    static int compteur;
    double sommets[6][2];
    double surface;
    double perimetre;
    void SaisirSommet(int index);
protected:
    void setSommet(int index, double x, double y);
    void CalculerPerimetre();
    void CalculerSurface();
public:
    HexagoneIrregulier(const double s[6][2]);
    HexagoneIrregulier();
    ~HexagoneIrregulier();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;

    static int getCompteurHexagone();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
