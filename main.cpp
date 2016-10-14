#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main(int argc, char *argv[])
{
    Jeton entree[6];
    entree[0].lexeme = FUNCTION;
    entree[0].valeur.fonction = SIN;
    entree[1].lexeme = PARENT_OPEN;
    entree[2].lexeme = VARIABLE;
    entree[3].lexeme = OPERATEUR;
    entree[3].valeur.operateur = PLUS;
    entree[4].lexeme = REEL;
    entree[4].valeur.value = 2;
    entree[5].lexeme = PARENT_CLOSE;

    ASyntaxique *aSyntax = new ASyntaxique();
    aSyntax->checkSyntax(entree, 6);
    Noeud* n = aSyntax->creerNoeud(&entree[0]);
    Noeud* f = aSyntax->creerNoeud(&entree[1], n);
    n->parent = f;


    delete aSyntax;
    delete n;
    delete f;
    return 0;
}
