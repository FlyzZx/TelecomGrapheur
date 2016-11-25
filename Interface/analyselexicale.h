#ifndef ANALYSELEXICALE_H
#define ANALYSELEXICALE_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "mainwindow.h"


using namespace std;
template <typename T>
class AnalyseLexicale {
public:
    AnalyseLexicale();
    string mainString = "ln(x+(-3--5x))-2";
    bool error = false;
    bool negatif = false;
    string NumberToString(T Number);
    string LexemeToString(int nb);
    string OperateurToString(int nb);
    string FonctionToString(int nb);
    float string2float(string str);
    bool isFunction(char cara);
    bool isNumber(char cara);
    bool isVar(char cara);
    bool isOperator(char cara);
    bool isParenthesisOpens(char cara);
    bool isParenthesisClosing(char cara);
    vector<Jeton> aToken(string chaine);
};


#endif // ANALYSELEXICALE_H
