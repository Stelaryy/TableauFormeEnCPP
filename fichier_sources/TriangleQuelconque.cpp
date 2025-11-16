// Auteur : Ahmed Boukra Bettayeb
// Version : 2.1
// Date : 14/10/2025
// Classe TriangleQuelconque - Implémentation

#include "TriangleQuelconque.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

constexpr double PI = 3.14159265358979323846;

// -----------------------------
// Déclaration du compteur
// -----------------------------
int TriangleQuelconque::compteur = 0;
int TriangleQuelconque::decrementer = 0;

// -----------------------------
// Constructeurs
// -----------------------------

// Constructeur via 3 côtés
TriangleQuelconque::TriangleQuelconque(double A, double B, double C)
{
    incrementerCompteur();

    if (!estValide(A, B, C))
        throw invalid_argument("Les valeurs saisies ne forment pas un triangle valide !");

    setA(A);
    setB(B);
    setC(C);

    CalculerPerimetre();
    CalculerSurface();

    cout << "Creation d'un triangle quelconque (3 cotes)." << endl;
}

// Constructeur via 2 côtés + angle
TriangleQuelconque::TriangleQuelconque(double A, double B, double angleDegres, bool fromAngle)
{
    incrementerCompteur();

    if (!fromAngle)
        throw invalid_argument("Le parametre fromAngle doit etre vrai pour ce constructeur.");

    if (A <= 0 || B <= 0 || angleDegres <= 0 || angleDegres >= 180)
        throw invalid_argument("Parametres invalides pour construire un triangle (angle mauvais).");

    double angleRad = angleDegres * PI / 180.0;
    double C = sqrt(A*A + B*B - 2*A*B*cos(angleRad)); // Loi des cosinus

    if (!estValide(A, B, C))
        throw invalid_argument("Impossible de former un triangle avec les valeurs fournies.");

    setA(A);
    setB(B);
    setC(C);

    CalculerPerimetre();
    CalculerSurface();

    cout << "Creation d'un triangle quelconque (2 cotes + angle)." << endl;
}

// -----------------------------
// Destructeur
// -----------------------------
TriangleQuelconque::~TriangleQuelconque()
{
    decrementerCompteur();
    cout << "Destruction d'un triangle quelconque." << endl;
}

// -----------------------------
// Setters protégés
// -----------------------------
void TriangleQuelconque::setA(double A)
{
    if (A <= 0)
        throw invalid_argument("Le cote A doit etre positif.");
    a = A;
}

void TriangleQuelconque::setB(double B)
{
    if (B <= 0)
        throw invalid_argument("Le cote B doit etre positif.");
    b = B;
}

void TriangleQuelconque::setC(double C)
{
    if (C <= 0)
        throw invalid_argument("Le cote C doit etre positif.");
    c = C;
}

// -----------------------------
// Vérification validité
// -----------------------------
bool TriangleQuelconque::estValide(double A, double B, double C) const
{
    return (
        A > 0 && B > 0 && C > 0 &&
        A + B > C &&
        A + C > B &&
        B + C > A
    );
}

// -----------------------------
// Méthodes privées de saisie
// -----------------------------
void TriangleQuelconque::SaisirCoteA()
{
    do {
        cout << "Entrez le cote A (A > 0) : ";
        cin >> a;
    } while (a <= 0);
}

void TriangleQuelconque::SaisirCoteB()
{
    do {
        cout << "Entrez le cote B (B > 0) : ";
        cin >> b;
    } while (b <= 0);
}

void TriangleQuelconque::SaisirCoteC()
{
    do {
        cout << "Entrez le cote C (C > 0) : ";
        cin >> c;
    } while (c <= 0);
}

// -----------------------------
// Méthodes protégées de calcul
// -----------------------------
void TriangleQuelconque::CalculerPerimetre()
{
    Perimetre = a + b + c;
}

void TriangleQuelconque::CalculerSurface()
{
    double p = Perimetre / 2.0;
    surface = sqrt(p * (p - a) * (p - b) * (p - c)); // Formule de Héron
}

// -----------------------------
// Méthodes publiques héritées
// -----------------------------
void TriangleQuelconque::SaisirDimension()
{
    SaisirCoteA();
    SaisirCoteB();
    SaisirCoteC();

    if (!estValide(a, b, c))
        throw invalid_argument("Les valeurs saisies ne forment pas un triangle valide !");

    CalculerPerimetre();
    CalculerSurface();
}

void TriangleQuelconque::SaisirDimension(double _dim1, double _dim2, double _dim3)
{
    if (!estValide(_dim1, _dim2, _dim3))
        throw invalid_argument("Dimensions invalides fournies au triangle !");

    setA(_dim1);
    setB(_dim2);
    setC(_dim3);

    CalculerPerimetre();
    CalculerSurface();
}

// -----------------------------
// Getters hérités
// -----------------------------
double TriangleQuelconque::getSurface() const
{
    return surface;
}

double TriangleQuelconque::getPerimetre() const
{
    return Perimetre;
}

// -----------------------------
// Getters des côtés
// -----------------------------
double TriangleQuelconque::getA() const { return a; }
double TriangleQuelconque::getB() const { return b; }
double TriangleQuelconque::getC() const { return c; }

// -----------------------------
// Gestion du compteur
// -----------------------------
int TriangleQuelconque::getCompteurTriangle()
{
    return compteur;
}

void TriangleQuelconque::incrementerCompteur()
{
    compteur++;
}

void TriangleQuelconque::decrementerCompteur()
{
    compteur--;
}
