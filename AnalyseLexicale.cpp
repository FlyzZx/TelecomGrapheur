//============================================================================
// Name        : AnalyseLexicale.cpp
// Author      : Florian MARDON / Clement MARTIN
//============================================================================
#include "analyselexicale.h"

string AnalyseLexicale::LexemeToString(int nb) {
    static const char * EnumStrings[] = { "FUNCTION", "REEL", "VARIABLE", "OPERATEUR", "PARENT_OPEN", "PARENT_CLOSE" };
    return EnumStrings[nb];
}
string AnalyseLexicale::OperateurToString(int nb) {
    static const char * EnumStrings[] = { "PLUS", "MOINS", "MULT", "DIV" };
    return EnumStrings[nb];
}
string AnalyseLexicale::FonctionToString(int nb) {
    static const char * EnumStrings[] = { "SIN", "COS", "TAN", "SQRT", "LOG", "LN" };
    return EnumStrings[nb];
}


float AnalyseLexicale::string2float(string str) { //Methode pour convertir une chaine String en float (utilis?e pour traiter les d?cimaux)
    stringstream ss;
    float f;
    ss.str(str);
    ss >> f;
    return f;
}

string suprEspace(string str) {
    string tmp="";
    for(int i=0;i<str.length();i++){
        if(str[i]!=' ')
            tmp+=str[i];
    }
    return tmp;
}

string ajoutFois(string str){

    string tmp="";
    for(int i=0;i<str.length()-1;i++){
        if(str[i]>='0' && str[i]<='9' && str[i+1]=='x'){
            tmp+=str[i];
            tmp+='*';
        }
        else{
            tmp+=str[i];
        }

    }
    tmp+=str[str.length()-1];
    return tmp;

}



// /!\ Les m?thodes qui suivent servent ? effectuer une premi?re v?rification sur l'origine d'une partie de l'op?ration
// --------------------------------------------------------------------------------------------------------------------

bool AnalyseLexicale::isFunction(char cara) {
    if ((cara >= 'A' && cara <= 'Z' && cara != 'X') || (cara >= 'a' && cara <= 'z' && cara != 'x')) {
        return true;
    }
    return false;
}

bool AnalyseLexicale::isNumber(char cara) {
    if (cara >= '0' && cara <= '9' || cara == ',' || cara == '.') { //Pour donner plus de pr?cision aux erreurs, on inclut les ',' et '.'
        return true;									   //que nous traiterons dans la m?thode aToken
    }
    return false;
}

bool AnalyseLexicale::isVar(char cara) {
    if (cara == 'x' || cara == 'X') {
        return true;
    }
    return false;
}

bool AnalyseLexicale::isOperator(char cara) {
    if (cara == '+' || cara == '-' || cara == '*' || cara == '/') {
        return true;
    }
    return false;
}

bool AnalyseLexicale::isParenthesisOpens(char cara) {
    if (cara == '(') {
        return true;
    }
    return false;
}

bool AnalyseLexicale::isParenthesisClosing(char cara) {
    if (cara == ')') {
        return true;
    }
    return false;
}

// --------------------------------------------------------------------------------------------------------------------
// La m?thode qui suit repr?sente le code principal de la partie d'analyse lexicale
// --------------------------------------------------------------------------------------------------------------------

vector<Jeton> AnalyseLexicale::aToken(string chaineS) {
    string chaineTmp=suprEspace(chaineS);
    string chaine=ajoutFois(chaineTmp);
    vector<Jeton> res;
    char cara;
    bool negatif = false;
    Lexeme lex; // d?finit la correspondance de la valeur associ? dans le token (jeton)
    Valeur val; // d?fini par fonction OU op?rateur OU valeur
    try {
        int i = 0;
        while (i<(int)chaine.size()) {
            cara = chaine[i];
            if (isFunction(cara)) {
                lex = FUNCTION;
                string chainePro = "";
                chainePro = chainePro + cara;
                i++;
                cara = chaine[i];
                while (isFunction(cara)) {
                    chainePro = chainePro + cara;
                    i++;
                    cara = chaine[i];
                }
                i--;
                if (chainePro.compare("sin") == 0 || chainePro.compare("SIN") == 0) {
                    val.fonction = SIN;
                }
                else if (chainePro.compare("cos") == 0 || chainePro.compare("COS") == 0) {
                    val.fonction = COS;
                }
                else if (chainePro.compare("sqrt") == 0 || chainePro.compare("SQRT") == 0) {
                    val.fonction = SQRT;
                }
                else if (chainePro.compare("tan") == 0 || chainePro.compare("TAN") == 0) {
                    val.fonction = TAN;
                }
                else if (chainePro.compare("log") == 0 || chainePro.compare("LOG") == 0) {
                    val.fonction = LOG;
                }
                else if (chainePro.compare("ln") == 0 || chainePro.compare("LN") == 0) {
                    val.fonction = LN;
                }
                else {
                    Erreur e;
                    e.message = "ERREUR: fonction non reconnue";
                    e.codeErreur = ERR101;
                    listError.push_back(e);
                }
            }
            else if (isNumber(cara)) {

                lex = REEL;
                bool verif = false;  //Va servir ? v?rifier si le nombre contient 2 virgules ou plus (cas d'erreur)
                bool verif2 = false; //Va servir ? verifier si le nombre se termine par une virgule (cas d'erreur)
                string nomb = "";
                if (negatif) {
                    nomb = nomb + "-";
                    negatif = false;
                }
                if (cara == ',' || cara == '.') {
                    Erreur e;
                    e.message = "L'un des nombres commence par une virgule";
                    e.codeErreur = ERR102;
                    listError.push_back(e);
                }
                while (isNumber(cara) || cara == ',' || cara == '.') {
                    if (verif == false && (cara == ',' || cara == '.')) { //Au premier passage de virgule on va changer les verif en true
                        verif = true;
                        verif2 = true;
                        nomb = nomb + cara;
                    }
                    else if (verif == true && (cara == ',' || cara == '.')) { //Ainsi on peut rep?rer le cas d'une seconde virgules
                        Erreur e;
                        e.message = "2 virgules ou plus pour l'un des nombres";
                        e.codeErreur = ERR103;
                        listError.push_back(e);
                    }
                    else { //Et verifier grace a verif2 que le nombre ne se termine pas par une virgule
                        nomb = nomb + cara;
                        verif2 = false;
                    }
                    i++;
                    cara = chaine[i];
                }
                if (verif2 == true) {
                    Erreur e;
                    e.message = "L'un des nombre se termine par une virgule";
                    e.codeErreur = ERR104;
                    listError.push_back(e);
                }
                else {
                    val.value = string2float(nomb);
                    i--;
                }
            }
            else if (isVar(cara)) {
                lex = VARIABLE;
            }
            else if (isOperator(cara)) {
                if (negatif){
                    Erreur e;
                    e.message = "saturation d'operateurs";
                    e.codeErreur = ERR105;
                    listError.push_back(e);
                }
                if (cara == '+') {
                    lex = OPERATEUR;
                    val.operateur = PLUS;
                }
                else if (cara == '-') {
                    if (res.size() == 0)
                        negatif = true;
                    if (res.back().lexeme == PARENT_CLOSE || res.back().lexeme == VARIABLE || res.back().lexeme == REEL) {
                        lex = OPERATEUR;
                        val.operateur = MOINS;
                    }
                    else if (res.back().lexeme == PARENT_OPEN || res.back().lexeme == FUNCTION) {
                        negatif = true;
                    }
                    else if (res.back().lexeme == OPERATEUR) {
                        if (res.at(res.size() - 2).lexeme == OPERATEUR){ // Lorsque l'on tombe sur des cas comme "3---3"
                            Erreur e;
                            e.message = "saturation d'operateurs";
                            e.codeErreur = ERR105;
                            listError.push_back(e);
                        }
                        else
                            negatif = true;
                    }
                }
                else if (cara == '*') {
                    lex = OPERATEUR;
                    val.operateur = MULT;
                }
                else if (cara == '/') {
                    lex = OPERATEUR;
                    val.operateur = DIV;
                }
                else {
                    Erreur e;
                    e.message = "FATAL ERROR !";// Cette erreur est impossible ? atteindre...
                    e.codeErreur = ERR106;
                    listError.push_back(e);
                }
            }
            else if (isParenthesisOpens(cara)) {
                lex = PARENT_OPEN;
            }
            else if (isParenthesisClosing(cara)) {
                lex = PARENT_CLOSE;
            }
            else {
                Erreur e;
                e.message = "Un caractere inconnu a ete entre";
                e.codeErreur = ERR107;
                listError.push_back(e);
            }
            if (!negatif) {
                Jeton token;
                token.lexeme = lex;
                token.valeur = val;
                res.push_back(token);
            }
            i++;
        }
    }
    catch (string const& chaine) {
        cerr << chaine << endl;
        error = true;
    }
    return res;
}

vector<Erreur> AnalyseLexicale::getErrors()
{
    return this->listError;
}

void AnalyseLexicale::clearErrors()
{
    this->listError.clear();
}

AnalyseLexicale::AnalyseLexicale()
{

}

