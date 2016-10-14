#include "ASyntaxique.h"

ASyntaxique::ASyntaxique() {
}

void ASyntaxique::checkSyntax(Jeton jeton[], int tailleTableau) {
    int nbPO = 0, nbPC = 0; //Compteurs de parenthéses
    for(int i = 0; i < tailleTableau; i++) {
        switch(jeton[i].lexeme) {
        case PARENT_OPEN:
            nbPO++;
            break;
        case PARENT_CLOSE:
            nbPC++;
            break;
        case FUNCTION:
            if(jeton[i+1].lexeme != PARENT_OPEN) {
                //ERREUR 202 : Pas de parenthèse après la fonction
                Erreur err;
                err.codeErreur = ERR202;
                this->erreurs.push_back(err);
            }
            break;
        case OPERATEUR:
            if(jeton[i+1].lexeme == OPERATEUR) {
                //ERREUR 203 : Double opérateur
                Erreur err;
                err.codeErreur = ERR203;
                this->erreurs.push_back(err);
            }
            break;
        default:
            break;
        }
        if(nbPO != nbPC) {
            //ERREUR 201 : Erreur parenthèse en moins ou en plus ou non fermée
            Erreur err;
            err.codeErreur = ERR201;
            this->erreurs.push_back(err);
        }

        if((sizeof(this->erreurs) / sizeof(Erreur)) == 0) {
            //Appel de la construction de l'arbre
        } else {
            //Cas ou il y a des erreurs

        }
    }
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

Noeud* ASyntaxique::creerArbre(Jeton jeton[], int tailleTableau, Noeud *parent) {
    
    return 0;
}
