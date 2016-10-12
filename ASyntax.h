/*
 * Structures communes de la partie analyse syntaxique
 */

typedef struct {
    Jeton jeton;
    Noeud* jeton_g;
    Noeud* jeton_d;
    Noeud* parent;
} Noeud;
