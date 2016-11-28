#include "evaluation.h"

Evaluation::Evaluation()
{

}

float Evaluation::evaluation(Noeud* racine, float val){
    if(racine->jeton.lexeme != REEL || racine->parent !=0){
        if(racine->jeton_g != 0 && (racine->jeton_g->jeton.lexeme == OPERATEUR || racine->jeton_g->jeton.lexeme ==FUNCTION))
        {
            evaluation(racine->jeton_g,val);

        }
        else if(racine->jeton_d != 0 && (racine->jeton_d->jeton.lexeme ==OPERATEUR || racine->jeton_d->jeton.lexeme ==FUNCTION))
        {
            evaluation(racine->jeton_d,val);
        }
        else
        {
            if(racine->jeton.lexeme ==OPERATEUR )
            {
                operation(racine,val);
                if(racine->parent !=0) racine=racine->parent;
            }
            else if(racine->jeton.lexeme ==FUNCTION)
            {
                    fonction(racine,val);
                  if(racine->parent !=0) racine=racine->parent;
            }
            evaluation(racine,val);
        }
    }

    return racine->jeton.valeur.value;
}


void Evaluation::operation(Noeud* ope, float val){
    float vg = 0,vd = 0;

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
            ope->jeton.valeur.value =0; //Je fixe la valeur � 0 pour la connaitre.
        }
        else{
             ope->jeton.valeur.value = vg / vd;
        }
        break;
        default:
              detectionErreur(ERR302,"Erreur je ne sais pas");// erreur de calcul
            break;

            }
    ope->jeton.lexeme =REEL; //transformation ope en reel
}

void Evaluation::fonction(Noeud* fonc, float val){
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
        fonc->jeton.valeur.value = log10(1);
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


    }
      fonc->jeton.lexeme =REEL; //transformation ope en reel

    //cout<< fonc->jeton.valeur.value<<endl;
}

void Evaluation::detectionErreur(CodeErreur code,char* message){

        e.codeErreur = code;
        e.message =message;
        listErreur.push_back(e);
}

vector<Erreur> Evaluation::getErreurs() {
    return this->listErreur;
}

void Evaluation::clearErrors()
{
    this->listErreur.clear();
}




