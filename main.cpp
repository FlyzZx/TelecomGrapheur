#include <iostream>
#include "StructDatas.h"
#include <cstdlib>

using namespace std;
Jeton J;

int main()
{
    float x1,x2;
    Noeud* N = (Noeud*)malloc(sizeof(Noeud));//allocation m�moire noeud
    N->jeton_g=(Noeud*)malloc(sizeof(Noeud));
    N->jeton_d=(Noeud*)malloc(sizeof(Noeud));
    N->parent=(Noeud*)malloc(sizeof(Noeud));

    N->jeton_g->jeton.lexeme = VARIABLE;
    //N->jeton.lexeme= OPERATEUR;
    N->jeton_d->jeton.valeur.value=5.0;
    N->parent->jeton.lexeme =FUNCTION;

    cout << "b1:"<<N->jeton_g->jeton.lexeme<<"\n"<<endl;
    cout << "b2: reel" << endl;
    //cout << "N->jeton.lexem:" <<N->jeton.lexeme << endl;

    while ((N->parent->jeton.lexeme == FUNCTION) || (N->parent->jeton.lexeme == OPERATEUR)){
        cout << "Parent lexeme : "<<N->parent->jeton.lexeme << endl;
        //N->parent->jeton.lexeme = N->jeton_g->jeton.lexeme;
        N->N->parent->jeton_d->jeton.lexeme
        //N->jeton_g->jeton.lexeme = REEL;
    }



    switch(N->parent->jeton.lexeme){

    case REEL: VARIABLE:
        cout << "b3" << endl;
        return N->jeton.valeur.value;
        break;

    case FUNCTION:
        cout << "b4" << endl;
        return N->jeton.valeur.fonction;
        break;


    case OPERATEUR:
        cout << "b5" << endl;
         x1 = N->jeton_g->jeton.valeur.value;
         x2 = N->jeton_d->jeton.valeur.value;
         cout << "valeurX1:" <<x1 <<"\n"<< endl;
         cout << "valeurX2:" <<x2 << endl;
        break;
        }



    /*if (N.jeton.lexeme !=2){
        cout << "Valeur:" <<N.jeton.lexeme << endl;
    }
    else{
        cout << "Erreur:" <<N.jeton.lexeme << endl;
    }*/

    return 0;
}
