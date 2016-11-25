#ifndef EVALUATION_H
#define EVALUATION_H
#include <vector>
#include "mainwindow.h"

using namespace std;

class Evaluation{

public:
    Evaluation();
    Erreur e;
    vector<Erreur> listErreur;
    float evaluation(Noeud* racine, float val);
    void operation(Noeud* ope, float val);
    void fonction(Noeud* fonc, float val);
    void detectionErreur(CodeErreur code,char* message);

};


#endif // EVALUATION_H
