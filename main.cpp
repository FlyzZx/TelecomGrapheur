#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main()
{
    //ARBRE 1 POUR TEST
    std::vector<Jeton> entree;
    Jeton j;
    // (9 / Sin(x + 14)) / 10
    j.lexeme = PARENT_OPEN;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 9;
    entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = DIV;
    entree.push_back(j);
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
    j.valeur.value = 14;
    entree.push_back(j);
    j.lexeme = PARENT_CLOSE;
    entree.push_back(j);
    entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = DIV;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 10;
    entree.push_back(j);

    //ARBRE 2 POUR TEST
    std::vector<Jeton> entree2;
    // sin(x+2)
    j.lexeme = FUNCTION;
    j.valeur.fonction = SIN;
    entree2.push_back(j);
    j.lexeme = PARENT_OPEN;
    entree2.push_back(j);
    j.lexeme = VARIABLE;
    entree2.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = PLUS;
    entree2.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 2;
    entree2.push_back(j);
    j.lexeme = PARENT_CLOSE;
    entree2.push_back(j);

    //ARBRE 3 POUR TEST
    std::vector<Jeton> entree3;
    // 2*x + 7*x
    j.lexeme = REEL;
    j.valeur.value = 2;
    entree3.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = MULT;
    entree3.push_back(j);
    j.lexeme = VARIABLE;
    entree3.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = PLUS;
    entree3.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 7;
    entree3.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = MULT;
    entree3.push_back(j);
    j.lexeme = VARIABLE;
    entree3.push_back(j);

    //Arbre 1
    Noeud *arbre;
    ASyntaxique *aSyntax = new ASyntaxique();
    if(aSyntax->checkSyntax(entree).size() == 0) {
        entree = aSyntax->setPriorite(entree);
        arbre = aSyntax->creerArbre(entree);
    }

    //Arbre 2
    Noeud *arbre2;
    ASyntaxique *aSyntax2 = new ASyntaxique();
    if(aSyntax2->checkSyntax(entree2).size() == 0) {
        entree2 = aSyntax->setPriorite(entree2);
        arbre2 = aSyntax->creerArbre(entree2);
    }

    //Arbre 3
    Noeud *arbre3;
    ASyntaxique *aSyntax3 = new ASyntaxique();
    if(aSyntax3->checkSyntax(entree3).size() == 0) {
        entree3 = aSyntax3->setPriorite(entree3);
        arbre3 = aSyntax3->creerArbre(entree3);
    }

    delete aSyntax;
    delete arbre;
    delete arbre2;
    delete arbre3;
    delete aSyntax2;
    delete aSyntax3;
    return 0;
}
