#ifndef DATA_H
#define DATA_H

typedef enum {
    FUNCTION, REEL, VARIABLE, OPERATEUR, PARENT_OPEN, PARENT_CLOSE
} Lexeme;

typedef enum {
    PLUS, MOINS, MULT, DIV
} Operateur;

typedef enum {
    SIN, COS, TAN, SQRT, LOG, LN
} Fonction;

typedef enum {
    ERR101 = 101,
    ERR102 = 102,
    ERR103 = 103,
    ERR201 = 201,
    ERR202 = 202,
    ERR203 = 203,
    ERR301 = 301,
    ERR302 = 302,
    ERR303 = 303,
    ERR304 = 304,
    ERR305 = 305,
    ERR401 = 401,
    ERR402 = 402,
    ERR403 = 403
} CodeErreur;

/* Gestion erreurs */
typedef struct {
    CodeErreur codeErreur;
    char *message;
} Erreur;

/* Partie 1 : Analyse Lexicale*/
typedef struct {
    Fonction fonction;
    Operateur operateur;
    float value;
} Valeur;

typedef struct {
    Lexeme lexeme;
    Valeur valeur;
    int priorite;
} Jeton;

/* Partie 2 : Analyse Syntaxique */
typedef struct Noeud {
    Jeton jeton;
    Noeud* jeton_g;
    Noeud* jeton_d;
    Noeud* parent;
} Noeud;

/* Partie 3 : Evaluation */

/* Partie 4 : Graphique */
#endif // DATA_H
