#ifndef DEF_LOSANGE
#define DEF_LOSANGE

#pragma once
#include "forme.h"

class Losange : public forme {
private:
    double d1;
    double d2;
    double cote;
    double angle; // radians
    double surface;
    double perimetre;

    void SaisirDiagonal1();
    void SaisirDiagonal2();
    void SaisirCote();
    void SaisirAngle();
protected:
    void setDiagonal1(double d);
    void setDiagonal2(double d);
    void setCote(double c);
    void setAngle(double a);

    void CalculerSurface();
    void CalculerPerimetre();
public:
    Losange();
    Losange(bool fromDiagonales);
    ~Losange();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;
};

#endif
