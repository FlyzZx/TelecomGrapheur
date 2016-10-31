#include <iostream>
#include "StructDatas.h"
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;
Jeton J;Erreur e;
vector<Erreur> listErreur;

void operation(float val1, float val2, Jeton Operateur); /* cas parent operateur */
void getErreur();
void fonction (float val1, Jeton Fonction);
void boucleLexeme(Noeud *N);


Noeud* N = (Noeud*)malloc(sizeof(Noeud));//allocation mémoire noeud
int main()
{

    N->jeton_g=(Noeud*)malloc(sizeof(Noeud));
    N->jeton_d=(Noeud*)malloc(sizeof(Noeud));
    N->parent=(Noeud*)malloc(sizeof(Noeud));
//    float x1,x2;
//    x1 = 5.0;x2= 4.0;
   /*N->jeton_g->jeton.lexeme = VARIABLE;
    //N->jeton.lexeme= OPERATEUR;
    N->jeton_d->jeton.valeur.value=5.0;
    N->parent->jeton.lexeme =FUNCTION;
   // N->parent->jeton_d->jeton.lexeme= FUNCTION;
    //N->parent->jeton.valeur.operateur = DIV;
    N->jeton_g->jeton.valeur.value = 5.0;
    N->jeton_d->jeton.valeur.value =1.0;
    N->parent->jeton.valeur.fonction=SIN;*/

    N->parent->jeton.lexeme=FUNCTION;
    N->parent->jeton.valeur.fonction=TAN;

    N->jeton_g->jeton.lexeme=OPERATEUR;
    N->jeton_g->jeton.valeur.operateur=PLUS;
    //N = N->jeton_g;
    N->jeton_g->jeton.lexeme=REEL;
    N->jeton_d->jeton.valeur.value=3;
    N->jeton_d->jeton.lexeme=REEL;
    N->jeton_g->jeton.valeur.value=5;


    //operation(N->jeton_d->jeton.valeur.value, N->jeton_g->jeton.valeur.value, N->parent->jeton);
    cout << cos(5.0)<< endl;
    getErreur();
   // fonction(N->jeton_g->jeton.valeur.value, N->parent->jeton);
    //boucleLexeme(N);


    return 0;
}
void operation(float val1, float val2, Jeton Operateur){//N->parent->jeton.valeur.operateur
     //vector<Erreur> listErreur;
     switch (N->parent->jeton.valeur.operateur){
         case PLUS:
             cout << "val plus:"<< val1+val2 << endl;
             N->parent->jeton.valeur.value = val1+val2;
             N->parent->jeton.lexeme = REEL;
             break;
        case MOINS:
            N->parent->jeton.valeur.value = val1-val2;
            N->parent->jeton.lexeme = REEL;
            break;
        case MULT:
            N->parent->jeton.valeur.value = val1*val2;
            N->parent->jeton.lexeme = REEL;
            break;
        case DIV:
            if (N->jeton_d->jeton.valeur.value!=0.0) {
                N->parent->jeton.valeur.value = val1/val2;
                N->parent->jeton.lexeme = REEL;
            }
            else{
                //Erreur e;
                    e.codeErreur = ERR301;
                    e.message = "Division par 0";
                    listErreur.push_back(e);
            }
            break;
        default:
            e.codeErreur = ERR305;
                e.message = "Erreur je sais pas";
                listErreur.push_back(e);// erreur de calcul
            }
    cout << N->parent->jeton.valeur.value<<endl;
}
void getErreur(){
    int n = listErreur.size();
    if(n !=0){
            for (int i; i<n; i++){
                cout << n<<"\n";
            }
    }

}
void fonction (float val, Jeton Fonction){
    cout << "val jeton: " <<N->parent->jeton.valeur.fonction<<endl;

    switch (N->parent->jeton.valeur.fonction){
        case SIN:
            N->parent->jeton.valeur.value= sin(val);
            N->parent->jeton.lexeme = REEL;
            break;
        case COS:
            N->parent->jeton.valeur.value= cos(val);
            N->parent->jeton.lexeme = REEL;
            break;
        case TAN:
            N->parent->jeton.valeur.value= tan(val);
            N->parent->jeton.lexeme = REEL;
            break;

        case SQRT:
            if (val>0.0){
                N->parent->jeton.valeur.value= sqrt(val);
                N->parent->jeton.lexeme = REEL;
            }
            else{
                    e.codeErreur = ERR302;
                    e.message = "la racine doit etre superieur a 0";
                    listErreur.push_back(e);
            }
            break;
        case LOG:
            if (val>0.0){
                N->parent->jeton.valeur.value= log10(val);
                N->parent->jeton.lexeme = REEL;
            }
            else{
                    e.codeErreur = ERR303;
                    e.message = "le log racine doit etre superieur a 0";
                    listErreur.push_back(e);
            }
            break;
        case LN:
            if (val>0.0){
                N->parent->jeton.valeur.value= log(val);
                N->parent->jeton.lexeme = REEL;
            }

            else{
                    e.codeErreur = ERR304;
                    e.message = "le ln doit etre superieur a 0";
                    listErreur.push_back(e);
            }
            break;
    }


    cout << "valeur val:"<<val << "\nval fonction: "<< N->parent->jeton.valeur.value  <<endl;
}
void boucleLexeme(Noeud *N){
    int i=0;
    cout << "valeur lexeme: "<<N->parent->jeton.lexeme<<endl;
    Lexeme tmp = N->parent->jeton.lexeme;
    /* boucle qui gere les fonctions et les operateurs*/
    while ((tmp == FUNCTION) || (tmp == OPERATEUR)){
        //N=N->jeton_g;
        if (tmp == OPERATEUR) {
            operation(N->jeton_d->jeton.valeur.value, N->jeton_g->jeton.valeur.value, N->parent->jeton);
        }
        else if (tmp == FUNCTION){
            if (N->jeton_g->jeton.lexeme == REEL || N->jeton_g->jeton.lexeme == VARIABLE){

                fonction(N->jeton_g->jeton.valeur.value, N->parent->jeton);
            }
            else {
                tmp = N->jeton_g->jeton.lexeme;
            }
        }
        else{
            fonction(N->jeton_g->jeton.valeur.value, N->parent->jeton);
        }

        cout <<i<<"\n"<< endl;
        i++;
        cout << "valeur lexeme: "<<N->parent->jeton.lexeme<<endl;

    }
}
