#include <iostream>
#include "StructDatas.h"
#include <cstdlib>

using namespace std;
Jeton J;

int main()
{
    J.lexeme=FUNCTION;
    J.valeur.fonction=COS;
    Noeud* N = (Noeud*)malloc(sizeof(Noeud));
   // N.jeton.lexeme = VARIABLE;
   N->jeton_g->jeton=J;


    N->jeton_g->jeton.lexeme = VARIABLE;



   std::cout <<"beuh"<<std::endl;

   /* while ((N.jeton_g->jeton.lexeme == 2)){
        cout << "fsef" << endl;
        N.jeton_g->jeton.lexeme = REEL;
    }*/

    /*switch(Noeud->jeton.lexeme){
    case REEL:VARIABLE:FUNCTION:
        return Noeud->jeton.valeur;
        break;
    case OPERATEUR:
        float x1= Noeud->jeton_g;
        float x2 = Noeud->jeton_d;
        break;


        }*/

    /*if (N.jeton.lexeme !=2){
        cout << "Valeur:" <<N.jeton.lexeme << endl;
    }
    else{
        cout << "Erreur:" <<N.jeton.lexeme << endl;
    }*/

    return 0;
}
