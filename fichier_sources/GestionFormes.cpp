#include <iostream>
#include <vector>
#include <memory> // pour smart pointers
#include "forme.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Ellipse.h"
#include "Cercle.h"
#include "Losange.h"
#include "TriangleQuelconque.h"
#include "HexagoneIrregulier.h"

using namespace std;

// ------------------------------------------------------
// FONCTION QUI AFFICHE LE MENU
// ------------------------------------------------------
int afficherMenu()
{
    cout << "\n================ MENU DES FORMES ================\n";
    cout << "1. Rectangle\n";
    cout << "2. Carre\n";
    cout << "3. Ellipse\n";
    cout << "4. Cercle\n";
    cout << "5. Losange\n";
    cout << "6. Triangle quelconque\n";
    cout << "7. Hexagone irregulier\n";
    cout << "0. Quitter\n";
    cout << "=================================================\n";
    cout << "Votre choix : ";
    int choix;
    cin >> choix;
    return choix;
}

// ------------------------------------------------------
// FONCTION QUI CRÉE UNE FORME SELON LE MENU
// ------------------------------------------------------
forme* creerForme(int choix)
{
    switch (choix)
    {
    case 1: {
        auto* f = new Rectangle();
        f->SaisirDimension();
        return f;
    }
    case 2: {
        auto* f = new Carre();
        f->SaisirDimension();
        return f;
    }
    case 3: {
        auto* f = new Ellipse();
        double a, b;
        cout << "Grand axe : "; cin >> a;
        cout << "Petit axe : "; cin >> b;
        f->SaisirDimension(a, b);
        return f;
    }
    case 4: {
        double r;
        cout << "Rayon du cercle : ";
        cin >> r;
        return new Cercle(r);
    }
    case 5: {
        cout << "Creer Losange via:\n1. Diagonales\n2. Cote + angle\n";
        int c; cin >> c;
        auto* f = new Losange();
        if (c == 1) {
            double d1, d2;
            cout << "d1 = "; cin >> d1;
            cout << "d2 = "; cin >> d2;
            f->SaisirDimension(d1, d2);
        }
        else {
            double cote;
            cout << "Cote = "; cin >> cote;
            f->SaisirDimension(cote);
        }
        return f;
    }
    case 6: {
        auto* f = new TriangleQuelconque();
        f->SaisirDimension();
        return f;
    }
    case 7: {
        auto* f = new HexagoneIrregulier();
        f->SaisirDimension();
        return f;
    }
    default:
        return nullptr;
    }
}

// ------------------------------------------------------
// COMPTE LES FORMES PAR TYPE (dynamic_cast)
// ------------------------------------------------------
void afficherCompteurs(const vector<forme*>& formes)
{
    int rect=0, carre=0, ell=0, cer=0, los=0, tri=0, hex=0;

    for (auto f : formes)
    {
        if (dynamic_cast<Rectangle*>(f)) rect++;
        else if (dynamic_cast<Carre*>(f)) carre++;
        else if (dynamic_cast<Ellipse*>(f)) ell++;
        else if (dynamic_cast<Cercle*>(f)) cer++;
        else if (dynamic_cast<Losange*>(f)) los++;
        else if (dynamic_cast<TriangleQuelconque*>(f)) tri++;
        else if (dynamic_cast<HexagoneIrregulier*>(f)) hex++;
    }

    cout << "\n========== COMPTEUR DES FORMES ==========\n";
    cout << "Rectangles : " << rect << endl;
    cout << "Carres : " << carre << endl;
    cout << "Ellipses : " << ell << endl;
    cout << "Cercles : " << cer << endl;
    cout << "Losanges : " << los << endl;
    cout << "Triangles : " << tri << endl;
    cout << "Hexagones : " << hex << endl;
    cout << "Total : " << formes.size() << endl;
    cout << "=========================================\n";
}

// ------------------------------------------------------
// PROGRAMME PRINCIPAL
// ------------------------------------------------------
int main()
{
    vector<forme*> formes;
    int choix = -1;

    while (choix != 0)
    {
        choix = afficherMenu();
        if (choix == 0) break;

        forme* f = creerForme(choix);

        if (f != nullptr)
        {
            cout << "\n--- Forme creee ---\n";
            cout << "Surface : " << f->getSurface() << endl;
            cout << "Perimetre : " << f->getPerimetre() << endl;
            cout << "--------------------\n";

            formes.push_back(f);
        }

        afficherCompteurs(formes);
    }

    // Libération mémoire (très important)
    for (auto f : formes)
        delete f;

    cout << "Programme termine.\n";
    return 0;
}
