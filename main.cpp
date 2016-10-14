#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main()
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
    j.lexeme = OPERATEUR;
    j.valeur.operateur = PLUS;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 2;
    entree.push_back(j);
    j.lexeme = PARENT_CLOSE;
    entree.push_back(j);

    ASyntaxique *aSyntax = new ASyntaxique();
    aSyntax->checkSyntax(entree);
    Noeud* n = aSyntax->creerNoeud(entree[0]);
    Noeud* f = aSyntax->creerNoeud(entree[1], n);
    n->parent = f;


    delete aSyntax;
    delete n;
    delete f;
    return 0;
}
