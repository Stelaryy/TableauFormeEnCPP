#ifndef ELLIPSE_H
#define ELLIPSE_H

#pragma once
#include "forme.h"

class Ellipse : public forme {
private:
    double GrandAxe;
    double PetitAxe;
    double surface;
    double perimetre;
public:
    Ellipse(double GrandAxe = 1.0, double PetitAxe = 1.0);
    virtual ~Ellipse();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;
protected:
    void CalculerSurface();
    void CalculerPerimetre();
};

#endif
