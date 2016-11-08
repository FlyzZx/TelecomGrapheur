#include <iostream>
#include "StructDatas.h"
#include <cstdlib>
#include <math.h>
#include <vector>


using namespace std;
Erreur e;
vector<Erreur> listErreur;

float evaluation(Noeud* racine, float val);
void operation(Noeud* ope, float val);
void fonction (Noeud* fonc, float val);
void detectionErreur(CodeErreur code,char* message);

int main()
{
      //Arbre pour G3 (Sin(2 + x))
   Noeud* racine = (Noeud*)malloc(sizeof(Noeud));
   racine->jeton.lexeme = FUNCTION;
   racine->jeton.valeur.fonction = SIN;
   racine->jeton.priorite = 2;
   racine->parent = NULL;
   racine->jeton_d = NULL;

   Noeud* ope1 = (Noeud*)malloc(sizeof(Noeud));
   ope1->jeton.lexeme = OPERATEUR;
   ope1->jeton.valeur.operateur = DIV;
   ope1->jeton.priorite = 11;
   ope1->parent = racine;
   racine->jeton_g = ope1;

   Noeud* valeur1 = (Noeud*)malloc(sizeof(Noeud));
   valeur1->jeton.lexeme = REEL;
   valeur1->jeton.valeur.value = 1;
   valeur1->jeton.priorite = 10;
   valeur1->jeton_d = NULL;
   valeur1->jeton_g = NULL;
   valeur1->parent = ope1;
   ope1->jeton_g = valeur1;

 /*  Noeud* valeur2 = (Noeud*)malloc(sizeof(Noeud));
   valeur2->jeton.lexeme = VARIABLE;
   valeur2->jeton.priorite = 10;
   valeur2->parent = ope1;
   valeur2->jeton_d = NULL;
   valeur2->jeton_g = NULL;
   ope1->jeton_d = valeur2;*/

Noeud* valeur2 = (Noeud*)malloc(sizeof(Noeud));
   valeur2->jeton.lexeme = REEL;
   valeur2->jeton.valeur.value = 0;
   valeur2->jeton.priorite = 10;
   valeur2->jeton_d = NULL;
   valeur2->jeton_g = NULL;
   valeur2->parent = ope1;
   ope1->jeton_d = valeur2;



    float x = 2; // la valeur du x est donnée par la partie n°4
    cout<<"main ->"<< evaluation(racine, x) <<endl;
    cout<<"Code Erreur ->"<<e.codeErreur<<endl;
    cout<<"Message erreur ->"<<e.message<<endl;

   //Vider les pointeurs de la memoire a la fin du programme (IMPORTANT !!)
   delete racine;
   delete ope1;
   delete valeur1;
   delete valeur2;
    return 0;
}

float evaluation(Noeud* racine, float val){

    while (racine->jeton_g !=NULL){
        racine = racine->jeton_g;
    }

    while(racine->parent !=NULL)
    {
        if(racine->parent->jeton.lexeme==OPERATEUR)
        {
            operation(racine, val);
            if(racine->parent !=NULL){
                    racine=racine->parent;}
        }
        else if(racine->parent->jeton.lexeme==FUNCTION)
        {
            fonction (racine,val);
            if(racine->parent !=NULL){
                    racine=racine->parent;}
        }

    }
   // cout<<"fonction recu ->"<< racine->jeton.valeur.value<<endl;

return racine->jeton.valeur.value;
}


void operation(Noeud* ope, float val){
    float vg = 0,vd = 0;
    ope=ope->parent;

    if(ope->jeton_g->jeton.lexeme == VARIABLE ){
        ope->jeton_g->jeton.lexeme = REEL;
        ope->jeton_g->jeton.valeur.value = val;
    }
    else if( ope->jeton_d->jeton.lexeme == VARIABLE ){
        ope->jeton_d->jeton.lexeme = REEL;
        ope->jeton_d->jeton.valeur.value = val;
    }

    switch (ope->jeton.valeur.operateur){
    case PLUS:
       vg = ope->jeton_g->jeton.valeur.value;
       vd = ope->jeton_d->jeton.valeur.value;
       ope->jeton.valeur.value = vg + vd;
        break;

    case MOINS:
       vg = ope->jeton_g->jeton.valeur.value;
       vd = ope->jeton_d->jeton.valeur.value;
       ope->jeton.valeur.value = vg - vd;
        break;

    case MULT:
       vg = ope->jeton_g->jeton.valeur.value;
       vd = ope->jeton_d->jeton.valeur.value;
       ope->jeton.valeur.value = vg * vd;
        break;

    case DIV:
       vg = ope->jeton_g->jeton.valeur.value;
       vd = ope->jeton_d->jeton.valeur.value;
        if (vd == 0){
            detectionErreur(ERR301,"Division par 0");
            ope->jeton.valeur.value =0; //Je fixe la valeur à 0 pour la connaitre.
        }
        else{
             ope->jeton.valeur.value = vg / vd;
        }
        break;
        default:
              detectionErreur(ERR302,"Erreur je ne sais pas");// erreur de calcul
        break;
        ope->jeton.lexeme =REEL; //transformation ope en lexeme reel
            }
}

void fonction(Noeud* fonc, float val){
    fonc=fonc->parent;
    float vg=0;


    if(fonc->jeton_g->jeton.lexeme == VARIABLE ){
        fonc->jeton_g->jeton.lexeme = REEL;
        fonc->jeton_g->jeton.valeur.value = val;
    }
    switch (fonc->jeton.valeur.fonction){
    case SIN:
        vg = fonc->jeton_g->jeton.valeur.value;
        fonc->jeton.valeur.value = sin(vg);
       break;

    case COS:
        vg = fonc->jeton_g->jeton.valeur.value;
        fonc->jeton.valeur.value = cos(vg);
       break;

    case TAN:
        vg = fonc->jeton_g->jeton.valeur.value;
        fonc->jeton.valeur.value = tan(vg);
       break;

    case SQRT:
        vg = fonc->jeton_g->jeton.valeur.value;
        if (vg < 0.0){
        detectionErreur(ERR303,"La racine doit etre superieure a 0");
        fonc->jeton.valeur.value = sqrt(0);
        }
        else{
        fonc->jeton.valeur.value = sqrt(vg);
        }
       break;

    case LOG:
        vg = fonc->jeton_g->jeton.valeur.value;
        if (vg <= 0.0){
        detectionErreur(ERR304,"Le log doit etre superieur a 0");
        fonc->jeton.valeur.value = log10(1); //met 0 pour les prob a gerer en groupe
        }
        else{
        fonc->jeton.valeur.value = log10(vg);
        }
       break;

    case LN:
        vg = fonc->jeton_g->jeton.valeur.value;
        if (vg <= 0.0){
        detectionErreur(ERR305,"Le log neperien  doit etre superieur a 0");
        fonc->jeton.valeur.value = log(1);
        }
        else{
        fonc->jeton.valeur.value = log(vg);
        }
       break;
        default:
         detectionErreur(ERR302,"Erreur je ne sais pas");// erreur de calcul
        break;

    fonc->jeton.lexeme =REEL; //transformation ope en reel
    }
}

void detectionErreur(CodeErreur code,char* message){

        e.codeErreur = code;
        e.message =message;
        listErreur.push_back(e);
}




