#include "ASyntaxique.h"

ASyntaxique::ASyntaxique() {
}

vector<Erreur> ASyntaxique::checkSyntax(std::vector<Jeton> jeton) {
    int nbPO = 0, nbPC = 0; //Compteurs de parenthéses
    for(unsigned int i = 0; i < jeton.size(); i++) {
        switch(jeton[i].lexeme) {
        case PARENT_OPEN:
            nbPO++;
            break;
        case PARENT_CLOSE:
            nbPC++;
            break;
        case FUNCTION:
            if(jeton[i+1].lexeme != PARENT_OPEN) {
                //ERREUR 202 : Pas de parenthèse après la fonction
                Erreur err;
                char msg[] = "Pas de parenthèse après la fonction";
                err.codeErreur = ERR202;
                err.message = msg;
                this->erreurs.push_back(err);
            }
            break;
        case OPERATEUR:
            if(jeton[i+1].lexeme == OPERATEUR) {
                //ERREUR 203 : Double opérateur
                char msg[] = "Double opérateur";
                Erreur err;
                err.codeErreur = ERR203;
                err.message = msg;
                this->erreurs.push_back(err);
            }
            break;
        default:
            break;
        }
    }
    if(nbPO != nbPC) {
        //ERREUR 201 : Erreur parenthèse en moins ou en plus ou non fermée
        char msg[] = "Parenthèse en moins ou en plus ou non fermée";
        Erreur err;
        err.codeErreur = ERR201;
        err.message = msg;
        this->erreurs.push_back(err);
    }
    return this->erreurs;
}

Noeud *ASyntaxique::creerArbre(vector<Jeton> jeton, unsigned int indexBase, Noeud *parent) {
    Noeud* noeud = creerNoeud(jeton[indexBase]);
    if(indexBase < jeton.size()) { //Condition de sortie de récursivité
        switch(jeton[indexBase].lexeme) {
        case REEL : case VARIABLE: //Reel ou variable
            if(parent != 0) { //Si le parent est défini
                noeud->parent = parent;
                if(parent->jeton_g == 0) parent->jeton_g = noeud;
                else parent->jeton_d = noeud;
            }
            creerArbre(jeton, indexBase + 1, noeud);
            break;

        case OPERATEUR:
            if(parent != 0 && (parent->jeton.lexeme == REEL || parent->jeton.lexeme == VARIABLE)) {
                Noeud* temp = parent; //Inversion OPERATEUR et (REEL OU VARIABLE)
                parent = noeud;
                parent->parent = temp->parent;
                if(temp->parent != 0) parent->parent->jeton_g = parent;
                noeud = temp;
                parent->jeton_g = noeud;
                noeud->parent = parent;
            }
            creerArbre(jeton,indexBase + 1, parent);
            break;

        case FUNCTION:
            if(parent!=0){
                noeud->parent = parent;
                if(parent->jeton_g == 0) parent->jeton_g = noeud;
                else parent->jeton_d = noeud;
            }
            creerArbre(jeton,indexBase +1 , noeud);
            break;

        default:
            creerArbre(jeton,indexBase +1, parent);
            break;
        }
    }
    return this->getRacine(noeud);
}

Noeud* ASyntaxique::creerNoeud(Jeton jeton, Noeud *fg, Noeud *fd, Noeud *parent) {
    Noeud *noeud = (Noeud*)malloc(sizeof(Noeud));
    if(fg != 0) noeud->jeton_g = fg;
    else noeud->jeton_g = 0;
    if(fd != 0) noeud->jeton_d = fd;
    else noeud->jeton_d = 0;
    if(parent != 0) noeud->parent = parent;
    else noeud->parent = 0;
    noeud->jeton = jeton;
    return noeud;
}

Noeud* ASyntaxique::getRacine(Noeud *n) {
    while(n->parent != 0) {
        n = n->parent;
        getRacine(n);
    }
    return n;
}

vector<Jeton> ASyntaxique::setPriorite(vector<Jeton> jeton) {
    unsigned int prio =0;
    for(int i =0;i<jeton.size();i++){
        switch(jeton[i].lexeme){
        case PARENT_OPEN :
            prio = prio + 10;
            break;
         case PARENT_CLOSE :
            prio = prio - 10;
            break;
         case OPERATEUR :
            switch(jeton[i].valeur.operateur){
            case MULT : case DIV :
                 jeton[i].priorite = prio + 1 ;
            break;
            default :
            break;
            }
         default :
         break;
        }
         jeton[i].priorite = prio;
    }

    return jeton;
}

ASyntaxique::~ASyntaxique()
{

}
