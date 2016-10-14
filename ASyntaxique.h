#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"
#include <cstdlib>

class ASyntaxique {
public:
    ASyntaxique();
    Noeud* creerArbre(Jeton jeton[]);
    Noeud* creerNoeud(Jeton *jeton, Noeud *fg = NULL, Noeud *fd = NULL, Noeud *parent = NULL);
    virtual ~ASyntaxique();
private:
    Noeud *racine;
    Erreur erreurs[];
};

#endif /* ASYNTAXIQUE_H */

