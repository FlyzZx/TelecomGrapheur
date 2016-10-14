#include "ASyntaxique.h"

ASyntaxique::ASyntaxique() {
}

ASyntaxique::~ASyntaxique() {
}

Noeud* ASyntaxique::creerNoeud(Jeton *jeton, Noeud *fg, Noeud *fd, Noeud *parent) {
    Noeud *noeud = (Noeud*)malloc(sizeof(Noeud));
    if(fg != NULL) noeud->jeton_g = fg;
    if(fd != NULL) noeud->jeton_d = fd;
    if(parent != NULL) noeud->parent = parent;
    noeud->jeton = *jeton;
    return noeud;
}

Noeud* ASyntaxique::creerArbre(Jeton jeton[]) {
    
    return 0;
}
