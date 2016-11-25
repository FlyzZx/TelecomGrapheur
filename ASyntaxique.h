#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H

#include <cstdlib>
#include <vector>
#include "data.h"

using namespace std;
class ASyntaxique {
public:
    ASyntaxique();
    vector<Erreur> checkSyntax(vector<Jeton> jeton);
    Noeud* creerArbre(vector<Jeton> jeton, unsigned int indexBase = 0, Noeud *parent = 0);
    vector<Jeton> setPriorite(vector<Jeton> jeton);
private:
    Noeud* creerNoeud(Jeton jeton, Noeud *fg = 0, Noeud *fd = 0, Noeud *parent = 0);
    Noeud* getRacine(Noeud *n);
    Noeud* getNoeudWithLowerPriority(Noeud *n, int priority);
    vector<Erreur> erreurs;
};

#endif /* ASYNTAXIQUE_H */

