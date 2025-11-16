#ifndef DEF_CERCLE
#define DEF_CERCLE

#pragma once
#include "Ellipse.h"

class Cercle : public Ellipse {
private:
    double rayon;
public:
    Cercle();
    Cercle(double r);
    ~Cercle();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;

    double getRayon() const { return rayon; }
};

#endif
