#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE

#pragma once
#include "forme.h"

class TriangleQuelconque : public forme {
private:
    static int compteur;
    double a,b,c;
    double surface;
    double perimetre;

    bool estValide(double A,double B,double C) const;
    void SaisirCoteA();
    void SaisirCoteB();
    void SaisirCoteC();

protected:
    void setA(double A);
    void setB(double B);
    void setC(double C);
    void CalculerPerimetre();
    void CalculerSurface();

public:
    TriangleQuelconque(double A=1,double B=1,double C=1);
    TriangleQuelconque(double A,double B,double angleDegres,bool fromAngle);
    ~TriangleQuelconque();

    void SaisirDimension() override;
    void SaisirDimension(double _dim1) override;
    void SaisirDimension(double _dim1, double _dim2) override;
    void SaisirDimension(double _dim1, double _dim2, double _dim3) override;

    double getSurface() const override;
    double getPerimetre() const override;
    double getA() const; double getB() const; double getC() const;
    static int getCompteurTriangle();
    static void incrementerCompteur();
    static void decrementerCompteur();
};

#endif
