// Auteur : Ahmed Boukra Bettayeb
// class GestionFormes (Main)
// date : 2025-11-25

#include <iostream>
#include <iomanip>
#include "forme.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Ellipse.h"
#include "Cercle.h"
#include "Losange.h"
#include "TriangleQuelconque.h"
#include "HexagoneIrregulier.h"

using namespace std;
constexpr int TAILLE_MAX = 100;

int afficherMenu()
{
    cout << "\n========= MENU DES FORMES =========\n";
    cout << "1. Ajouter Rectangle\n";
    cout << "2. Ajouter Carre\n";
    cout << "3. Ajouter Ellipse\n";
    cout << "4. Ajouter Cercle\n";
    cout << "5. Ajouter Losange\n";
    cout << "6. Ajouter Triangle quelconque\n";
    cout << "7. Ajouter Hexagone irregulier\n";
    cout << "8. Supprimer une forme\n";
    cout << "9. Afficher tableau\n";
    cout << "0. Quitter\n";
    cout << "==================================\n";
    cout << "Votre choix : ";
    int choix; cin >> choix; return choix;
}

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
        double a,b;
        cout << "Grand axe : "; cin>>a;
        cout << "Petit axe : "; cin>>b;
        auto* f = new Ellipse(a,b);
        return f;
    }
    case 4: {
        double r; cout << "Rayon du cercle : "; cin >> r;
        return new Cercle(r);
    }
    case 5: {
        cout << "1: diagonales  2: cote+angle\nChoix: "; int c; cin>>c;
        if (c==1){ auto* f = new Losange(true); return f; }
        else { auto* f = new Losange(); return f; }
    }
    case 6: {
        auto* f = new TriangleQuelconque();
        f->SaisirDimension();
        return f;
    }
    case 7: {
        return new HexagoneIrregulier();
    }
    default:
        return nullptr;
    }
}

void afficherCompteurs(forme* formes[])
{
    int rect=0, carre=0, ell=0, cer=0, los=0, tri=0, hex=0;
    int total=0;
    for (int i=0;i<TAILLE_MAX;i++){
        if (formes[i]){
            ++total;
            if (dynamic_cast<Carre*>(formes[i])) ++carre;
            else if (dynamic_cast<Rectangle*>(formes[i])) ++rect;
            else if (dynamic_cast<Cercle*>(formes[i])) ++cer;
            else if (dynamic_cast<Ellipse*>(formes[i])) ++ell;
            else if (dynamic_cast<Losange*>(formes[i])) ++los;
            else if (dynamic_cast<TriangleQuelconque*>(formes[i])) ++tri;
            else if (dynamic_cast<HexagoneIrregulier*>(formes[i])) ++hex;
        }
    }

    cout << "\n========== COMPTEUR DES FORMES ==========\n";
    cout << "Rectangles : " << rect << "\nCarres : " << carre << "\nEllipses : " << ell
         << "\nCercles : " << cer << "\nLosanges : " << los << "\nTriangles : " << tri
         << "\nHexagones : " << hex << "\nTotal formes : " << total << "\n";
}

void afficherTableau(forme* formes[])
{
    cout << "\n--- Contenu du tableau ---\n";
    for (int i=0;i<TAILLE_MAX;i++){
        cout << setw(3) << i << " : ";
        if (!formes[i]) { cout << "Vide\n"; continue; }
        if (dynamic_cast<Carre*>(formes[i])) cout << "Carre";
        else if (dynamic_cast<Rectangle*>(formes[i])) cout << "Rectangle";
        else if (dynamic_cast<Cercle*>(formes[i])) cout << "Cercle";
        else if (dynamic_cast<Ellipse*>(formes[i])) cout << "Ellipse";
        else if (dynamic_cast<Losange*>(formes[i])) cout << "Losange";
        else if (dynamic_cast<TriangleQuelconque*>(formes[i])) cout << "Triangle";
        else if (dynamic_cast<HexagoneIrregulier*>(formes[i])) cout << "Hexagone";
        cout << " | Surface=" << formes[i]->getSurface()
             << ", Perimetre=" << formes[i]->getPerimetre() << "\n";
    }
}

int main()
{
    forme* formes[TAILLE_MAX] = { nullptr };
    int count = 0;
    int choix = -1;

    while (choix != 0){
        choix = afficherMenu();
        if (choix >=1 && choix <=7){
            if (count >= TAILLE_MAX) { cout << "Tableau plein.\n"; continue; }
            forme* f = creerForme(choix);
            if (f) {
                // placer dans première case libre
                int idx = -1;
                for (int i=0;i<TAILLE_MAX;i++) if (!formes[i]) { idx=i; break; }
                if (idx==-1) { cout << "Aucune case libre (unexpected).\n"; delete f; continue; }
                formes[idx] = f; ++count;
                cout << "Forme ajoutee en case " << idx << ". Surface=" << f->getSurface() << ", Perimetre=" << f->getPerimetre() << "\n";
            }
            afficherCompteurs(formes);
        }
        else if (choix == 8){
            int idx; cout << "Index a supprimer (0-" << TAILLE_MAX-1 << "): "; cin>> idx;
            if (idx>=0 && idx < TAILLE_MAX && formes[idx]) {
                delete formes[idx];
                formes[idx] = nullptr;
                --count;
                cout << "Forme supprimee.\n";
                afficherCompteurs(formes);
            } else cout << "Index invalide ou case vide.\n";
        }
        else if (choix == 9){
            afficherTableau(formes);
        }
        else if (choix == 0){
            cout << "Quitter...\n";
        }
        else {
            cout << "Choix invalide.\n";
        }
    }

    // cleanup
    for (int i=0;i<TAILLE_MAX;i++) if (formes[i]) { delete formes[i]; formes[i]=nullptr; }

    cout << "Fin programme. Total formes restantes (global compteur) = " << forme::compteurFormes << endl;
    return 0;
}
