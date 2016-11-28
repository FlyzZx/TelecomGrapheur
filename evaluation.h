#ifndef EVALUATION_H
#define EVALUATION_H
#include <vector>
#include "data.h"
#include <math.h>

using namespace std;

class Evaluation{

public:
    Evaluation();
    Erreur e;
    vector<Erreur> getErreurs();
    void clearErrors();
    float evaluation(Noeud* racine, float val);
    void operation(Noeud* ope, float val);
    void fonction(Noeud* fonc, float val);
    void detectionErreur(CodeErreur code,char* message);

private:
     vector<Erreur> listErreur;

};


#endif // EVALUATION_H
