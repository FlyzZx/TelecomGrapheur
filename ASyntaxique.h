#ifndef ASYNTAXIQUE_H
#define ASYNTAXIQUE_H
#include "StructDatas.h"
#include <cstdlib>
#include <vector>

using namespace std;
class ASyntaxique {
public:
    ASyntaxique();
    void checkSyntax(vector<Jeton> jeton);
    vector<Erreur> creerArbre(vector<Jeton> jeton, Noeud *parent = 0);
    Noeud* creerNoeud(Jeton jeton, Noeud *fg = 0, Noeud *fd = 0, Noeud *parent = 0);
    Noeud* getRacine(Noeud *n);
    virtual ~ASyntaxique();
private:
    Noeud *racine;
    vector<Erreur> erreurs;
};

#endif /* ASYNTAXIQUE_H */

