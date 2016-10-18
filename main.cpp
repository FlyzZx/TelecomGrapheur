#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main()
{
    std::vector<Jeton> entree;
    Jeton j;
    // 3 * (3+x) * 2
    j.lexeme = REEL;
    j.valeur.value = 3;
    entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = MULT;
    entree.push_back(j);
    j.lexeme = PARENT_OPEN;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 3;
    entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = PLUS;
    entree.push_back(j);
    j.lexeme = VARIABLE;
    entree.push_back(j);
    j.lexeme = PARENT_CLOSE;
    entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = MULT;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 2;
    entree.push_back(j);

    Noeud *arbre;
    ASyntaxique *aSyntax = new ASyntaxique();
    if(aSyntax->checkSyntax(entree).size() == 0) {
        entree = aSyntax->setPriorite(entree);
        arbre = aSyntax->creerArbre(entree);
    }

    delete aSyntax;
    delete arbre;
    return 0;
}
