#include <iostream>
#include "StructDatas.h"
#include <cstdlib>
#include <math.h>

using namespace std;
Jeton J;
Noeud* N = (Noeud*)malloc(sizeof(Noeud));//allocation mémoire noeud
/*N->jeton_g=(Noeud*)malloc(sizeof(Noeud));
N->jeton_d=(Noeud*)malloc(sizeof(Noeud));
N->parent=(Noeud*)malloc(sizeof(Noeud));*/

void lexemeParent (Noeud *Lexeme){ //place "Noeud->parent->jeton.lexeme" et renvoie

}

float operation(float val1, float val2, Jeton *Operateur){//N->parent->jeton.valeur.operateur
     switch (N->parent->jeton.valeur.operateur){
         case PLUS:
             return val1+val2;
             break;
        case MOINS:
            return val1+val2;
            break;
        case MULT:
            return val1*val2;
            break;
        case DIV:
            return val1/val2;
            break;
        default:
            return 1;
            }

}



int main()
{
    float x1,x2;
   /* Noeud* N = (Noeud*)malloc(sizeof(Noeud));//allocation mémoire noeud
    N->jeton_g=(Noeud*)malloc(sizeof(Noeud));
    N->jeton_d=(Noeud*)malloc(sizeof(Noeud));
    N->parent=(Noeud*)malloc(sizeof(Noeud));*/

    N->jeton_g->jeton.lexeme = VARIABLE;
    //N->jeton.lexeme= OPERATEUR;
    N->jeton_d->jeton.valeur.value=5.0;
    N->parent->jeton.lexeme =FUNCTION;
    N->parent->jeton_d->jeton.lexeme= FUNCTION;


    operation(5.0, 4.0, PLUS);

   /* cout << "b1:"<<N->jeton_g->jeton.lexeme<<"\n"<<endl;
    cout << "b2: reel" << endl;
    //cout << "N->jeton.lexem:" <<N->jeton.lexeme << endl;

    while ((N->parent->jeton.lexeme == FUNCTION) || (N->parent->jeton.lexeme == OPERATEUR)){
        cout << "Parent lexeme : "<< N->parent->jeton.lexeme << endl;
        //N->parent->jeton.lexeme = N->jeton_g->jeton.lexeme;
        N->parent->jeton.lexeme=N->parent->jeton_d->jeton.lexeme;
        //N->jeton_g->jeton.lexeme = REEL;



  if (N->parent->jeton.lexeme == REEL || N->parent->jeton.lexeme == VARIABLE){
        x1= N->jeton_d->jeton.valeur.value;
        x2= N->jeton_g->jeton.valeur.value;
    }
   /* switch (N->parent->jeton.valeur.fonction){
    case SIN:
        return sin(x3);
        break;
    case COS:
        return cos(x3);
        break;} */
    /* gestion opérateur parent */







  /*  switch(N->parent->jeton.lexeme){

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
        }*/



    /*if (N.jeton.lexeme !=2){
        cout << "Valeur:" <<N.jeton.lexeme << endl;
    }
    else{
        cout << "Erreur:" <<N.jeton.lexeme << endl;
    }*/

    return 0;
}
