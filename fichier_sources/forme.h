#pragma once   // ou bien #ifndef FORME_H ... #define FORME_H ... #endif

class forme {
public:
    virtual ~forme() = default;
    forme();

    virtual double getSurface() const = 0;
    virtual double getPerimetre() const = 0;
    virtual void SaisirDimension();
    virtual void SaisirDimension(double _dim1);
    virtual void SaisirDimension(double _dim1, double _dim2);
    virtual void SaisirDimension(double _dim1, double _dim2, double _dim3);
};
