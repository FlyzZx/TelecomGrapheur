/*
 * Structures communes de la partie analyse syntaxique
 */

typedef enum {
    FUNCTION, REEL, VARIABLE, OPERATEUR, PARENT_OPEN, PARENT_CLOSE;
} Lexeme;

typedef enum {
    PLUS, MOINS, MULT, DIV;
} Operateur;

typedef enum {
    SIN, COS, TAN;
} Fonction;

typedef enum {
    101, 102, 103, 201, 202, 203, 301, 302, 303, 401, 402, 403;
} CodeErreur;

typedef struct {
    CodeErreur codeErreur;
} Erreur;

typedef union {
    Fonction fonction;
    Operateur operateur;
    float value;
} Valeur;

typedef struct {
    Lexeme lexeme;
    Valeur valeur;
} Jeton;

typedef struct {
    Jeton jeton;
    Noeud* jeton_g;
    Noeud* jeton_d;
    Noeud* parent;
} Noeud;
