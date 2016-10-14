#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"
#include <cstdlib>
#include <vector>

class ASyntaxique {
public:
    ASyntaxique();
    void checkSyntax(std::vector<Jeton> jeton);
    Noeud* creerArbre(Jeton jeton[], int tailleTableau, Noeud *parent = NULL);
    Noeud* creerNoeud(Jeton *jeton, Noeud *fg = NULL, Noeud *fd = NULL, Noeud *parent = NULL);
    virtual ~ASyntaxique();
private:
    Noeud *racine;
    std::vector<Erreur> erreurs;
};

#endif /* ASYNTAXIQUE_H */

