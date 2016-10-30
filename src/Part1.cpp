//============================================================================
// Name        : Part1.cpp
// Author      : Mardon Florian
// Version     :
// Copyright   : Copyright Mardon Florian & Co
//============================================================================
// TODO: Ajout du traitement des décimaux
//============================================================================
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "../StructDatas.h"
#include <string>
#include <vector>
using namespace std;
string mainString="tan(23.5x/5)";

float string2float(string str)
{
	stringstream ss;
	float f;
	ss.str(str);
	ss >> f;
	return f;
}

bool isFunction(char cara){
	if ((cara>='A' && cara<='Z' && cara!='X') || (cara>='a' && cara<='z' && cara!='x')){
		return true;
	}
	return false;
}

bool isNumber(char cara){
	if (cara>='0' && cara<='9'){
		return true;
	}
	return false;
}

bool isVar(char cara){
	if (cara=='x' || cara=='X'){
		return true;
	}
	return false;
}

bool isOperator(char cara){
	if (cara=='+' || cara=='-' || cara=='*' || cara=='/'){
		return true;
	}
	return false;
}

bool isParenthesisOpens(char cara){
	if(cara=='('){
		return true;
	}
	return false;
}

bool isParenthesisClosing(char cara){
	if(cara==')'){
		return true;
	}
	return false;
}

vector<Jeton> aToken(string chaine){ // a prononcer "haDoken" pour la blague ;)
	vector<Jeton> res;
	char cara;

	Lexeme lex; // définis la correspondance de la valeur associé dans le token (jeton)
	Valeur val; // définis par fonction OU opérateur OU valeur

	int i=0;
	while (i<chaine.size()){
		cara=chaine[i];
		if (isFunction(cara)){
			lex=FUNCTION;
			string chainePro="";
			chainePro=chainePro+cara;
			i++;
			cara=chaine[i];
			while (isFunction(cara)){
				chainePro=chainePro+cara;
				i++;
				cara=chaine[i];
			}
			i--;
			if ( chainePro.compare("sin") == 0 || chainePro.compare("SIN") == 0){
				val.fonction=SIN;
			}else if(chainePro.compare("cos") == 0 || chainePro.compare("COS") == 0 ){
				val.fonction=COS;
			}else if(chainePro.compare("sqrt") == 0 || chainePro.compare("SQRT") == 0){
				val.fonction=SQRT;
			}else if(chainePro.compare("tan") == 0 || chainePro.compare("TAN") == 0){
				val.fonction=TAN;
			}else if(chainePro.compare("log") == 0 || chainePro.compare("LOG") == 0){
				val.fonction=LOG;
			}else if(chainePro.compare("ln") == 0 || chainePro.compare("LN") == 0){
				val.fonction=LN;
			}else{
				//TODO retourner code erreur référent à fonction non reconnus
			}
		}else if (isNumber(cara)){
			lex=REEL;
			bool verif=false;
			bool verif2=false;
			string nomb="";
			while (isNumber(cara) || cara==',' || cara=='.'){
				if (verif==false && (cara==',' || cara=='.')){
					verif=true;
					verif2=true;
					nomb=nomb+cara;
				}else if(verif==true && (cara==',' || cara=='.')){
					//TODO retourner code erreur référent à 2 virgules présentes
				}else{
					nomb=nomb+cara;
					verif2=false;
				}
				i++;
				cara=chaine[i];
			}
			if (verif2==true){
				//TODO retourner code erreur référent à virgule de fin
			}else{
				val.value=string2float(nomb);
				i--;
			}
		}else if (isVar(cara)){
			lex=VARIABLE;
		}else if (isOperator(cara)){
			lex=OPERATEUR;
			if (cara=='+'){
				val.operateur=PLUS;
			}else if(cara=='-'){
				val.operateur=MOINS;
			}else if(cara=='*'){
				val.operateur=MULT;
			}else if(cara=='/'){
				val.operateur=DIV;
			}else{
			// TODO fatal error impossible a atteindre normallement
			}
		}else if (isParenthesisOpens(cara)){
			lex=PARENT_OPEN;
		}else if (isParenthesisClosing(cara)){
			lex=PARENT_CLOSE;
		}else{
		// TODO retourner une erreur référent à un caractère inconnus dans l'operation
		}
		Jeton token;
		token.lexeme=lex;
		token.valeur=val;
		res.push_back(token);
		i++;
	}
	return res;
}

int main(){
	vector<Jeton> resultat=aToken(mainString);
	for (int i=0;i<(int)resultat.size();i++){
		cout << resultat.at(i).lexeme;
	}
	return 0;
}
