#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"
#include <cstdlib>
#include <vector>

using namespace std;
class ASyntaxique {
public:
    ASyntaxique();
    vector<Erreur> checkSyntax(vector<Jeton> jeton);
    Noeud* creerArbre(vector<Jeton> jeton, unsigned int indexBase = 0, Noeud *parent = 0);
    Noeud* creerNoeud(Jeton jeton, Noeud *fg = 0, Noeud *fd = 0, Noeud *parent = 0);
    Noeud* getRacine(Noeud *n);
    int* getPriorite(vector<Jeton> jeton);
    virtual ~ASyntaxique();
private:
    vector<Erreur> erreurs;
};

#endif /* ASYNTAXIQUE_H */

