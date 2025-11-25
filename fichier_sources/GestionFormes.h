// GestionFormes.h - Declarations uniquement
#ifndef GESTIONFORMES_H
#define GESTIONFORMES_H

#include <iostream>
#include "forme.h"

using namespace std;
constexpr int TAILLE_MAX = 100;

// Declarations
int afficherMenu();
forme* creerForme(int choix);
void afficherCompteurs(forme* formes[]);
void afficherTableau(forme* formes[]);

#endif // GESTIONFORMES_H2