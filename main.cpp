#include <iostream>
#include "ASyntaxique.h"

using namespace std;

int main()
{
    std::vector<Jeton> entree;
    Jeton j;
    // (9 / Sin(x + 14)) / 10
    j.lexeme = PARENT_OPEN;
    //entree.push_back(j);
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
    //entree.push_back(j);
    j.lexeme = OPERATEUR;
    j.valeur.operateur = DIV;
    entree.push_back(j);
    j.lexeme = REEL;
    j.valeur.value = 10;
    entree.push_back(j);


    //Arbre pour G3 (Sin(2 + x))
    Noeud* racine = (Noeud*)malloc(sizeof(Noeud));
    racine->jeton.lexeme = FUNCTION;
    racine->jeton.valeur.fonction = SIN;
    racine->jeton.priorite = 2;
    racine->parent = NULL;
    racine->jeton_d = NULL;

    Noeud* ope1 = (Noeud*)malloc(sizeof(Noeud));
    ope1->jeton.lexeme = OPERATEUR;
    ope1->jeton.valeur.operateur = PLUS;
    ope1->jeton.priorite = 11;
    ope1->parent = racine;
    racine->jeton_g = ope1;

    Noeud* valeur1 = (Noeud*)malloc(sizeof(Noeud));
    valeur1->jeton.lexeme = REEL;
    valeur1->jeton.valeur.value = 2;
    valeur1->jeton.priorite = 10;
    valeur1->jeton_d = NULL;
    valeur1->jeton_g = NULL;
    valeur1->parent = ope1;
    ope1->jeton_g = valeur1;

    Noeud* valeur2 = (Noeud*)malloc(sizeof(Noeud));
    valeur2->jeton.lexeme = VARIABLE;
    valeur2->jeton.priorite = 10;
    valeur2->parent = ope1;
    valeur2->jeton_d = NULL;
    valeur2->jeton_g = NULL;
    ope1->jeton_d = valeur2;


    //Vider les pointeurs de la memoire a la fin du programme (IMPORTANT !!)
    delete racine;
    delete ope1;
    delete valeur1;
    delete valeur2;




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
