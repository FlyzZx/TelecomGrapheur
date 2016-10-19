//============================================================================
// Name        : Part1.cpp
// Author      : Mardon Florian
// Version     :
// Copyright   : Copyright Mardon Florian & Co
//============================================================================
// TODO: Ajout du traitement des décimaux
//============================================================================
#include <iostream>
#include "../StructDatas.h"
#include <string>
#include <vector>
using namespace std;
string mainString="tan(2x+2)";

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

vector<string> toLexeme(string chaine){
	vector<string> res;
	char cara;
	int i=0;
	while (i<=(int)sizeof(chaine)){
		cara=chaine[i];
		if (isFunction(cara)){
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
			if ( chainePro.compare("sin") == 0 || chainePro.compare("SIN") == 0 || chainePro.compare("cos") == 0 || chainePro.compare("COS") == 0 || chainePro.compare("sqrt") == 0 || chainePro.compare("SQRT") == 0 || chainePro.compare("tan") == 0 || chainePro.compare("TAN") == 0 || chainePro.compare("log") == 0 || chainePro.compare("LOG") == 0 || chainePro.compare("ln") == 0 || chainePro.compare("LN") == 0) {
					res.push_back("FUNCTION");
			}else{
				//TODO retourner code erreur référent à fonction non reconnus
			}
		}else if (isNumber(cara)){
			bool verif=false;
			bool verif2=false;
			while (isNumber(cara) || cara==',' || cara=='.'){
				if (verif==false && (cara==',' || cara=='.')){
					verif=true;
					verif2=true;
				}else if(verif==true && (cara==',' || cara=='.')){
					//TODO retourner code erreur référent à 2 virgules présentes
				}else{
					verif2=false;
				}
				i++;
				cara=chaine[i];
			}
			if (verif2==true){
				//TODO retourner code erreur référent à virgule de fin
			}else{
				res.push_back("REEL");
				i--;
			}
		}else if (isVar(cara)){
			res.push_back("VARIABLE");
		}else if (isOperator(cara)){
			res.push_back("OPERATEUR");
		}else if (isParenthesisOpens(cara)){
			res.push_back("PARENT_OPEN");
		}else if (isParenthesisClosing(cara)){
			res.push_back("PARENT_CLOSE");
		}else{
		// TODO retourner une erreur référent à un caractère inconnus dans l'operation
		}
		i++;
	}
	return res;
}

int main(){
	vector<string> resultat=toLexeme(mainString);
	for (int i=0;i<resultat.size();i++){
		cout << (resultat.at(i));
	}
	return 0;
}
