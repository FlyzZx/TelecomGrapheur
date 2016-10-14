#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"

class ASyntaxique {
public:
    ASyntaxique();
    Noeud* creerArbre(Jeton jeton[]);
    Noeud* creerNoeud(Jeton *jeton, Noeud *fg, Noeud *fd);
    virtual ~ASyntaxique();
private:
    Noeud *racine;
    Erreur erreurs[];
};

#endif /* ASYNTAXIQUE_H */

