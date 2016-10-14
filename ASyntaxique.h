#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"
#include <cstdlib>
#include <vector>

using namespace std;
class ASyntaxique {
public:
    ASyntaxique();
    void checkSyntax(vector<Jeton> jeton);
    vector<Erreur> creerArbre(Jeton jeton[], int tailleTableau, Noeud *parent = NULL);
    Noeud* creerNoeud(Jeton jeton, Noeud *fg = NULL, Noeud *fd = NULL, Noeud *parent = NULL);
    Noeud* getRacine(Noeud *n);
    virtual ~ASyntaxique();
private:
    Noeud *racine;
    vector<Erreur> erreurs;
};

#endif /* ASYNTAXIQUE_H */

