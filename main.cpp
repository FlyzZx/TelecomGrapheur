#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main(int argc, char *argv[])
{
    std::vector<Jeton> entree;
    Jeton j;
    j.lexeme = FUNCTION;
    j.valeur.fonction = SIN;
    entree.push_back(j);
    j.lexeme = PARENT_OPEN;
    entree.push_back(j);
    j.lexeme = VARIABLE;
    entree.push_back(j);

    entree[3].lexeme = OPERATEUR;
    entree[3].valeur.operateur = PLUS;
    entree[4].lexeme = REEL;
    entree[4].valeur.value = 2;
    entree[5].lexeme = PARENT_CLOSE;

    ASyntaxique *aSyntax = new ASyntaxique();
    aSyntax->checkSyntax(entree);
    Noeud* n = aSyntax->creerNoeud(&entree[0]);
    Noeud* f = aSyntax->creerNoeud(&entree[1], n);
    n->parent = f;


    delete aSyntax;
    delete n;
    delete f;
    return 0;
}
