#ifndef FORME_H
#define FORME_H

#pragma once

class forme {
public:
    static int compteurFormes;

    // Gestion compteur global
    static void incrementerFormes() { compteurFormes++; }
    static void decrementerFormes() { compteurFormes--; }

    // Constructeur / destructeur
    forme() { incrementerFormes(); }
    virtual ~forme() { decrementerFormes(); }

    // Interface
    virtual double getSurface() const = 0;
    virtual double getPerimetre() const = 0;

    // Saisies (toutes déclarées pour forcer implémentation dans dérivées)
    virtual void SaisirDimension() = 0;
    virtual void SaisirDimension(double _dim1) = 0;
    virtual void SaisirDimension(double _dim1, double _dim2) = 0;
    virtual void SaisirDimension(double _dim1, double _dim2, double _dim3) = 0;
};

#endif // FORME_H
