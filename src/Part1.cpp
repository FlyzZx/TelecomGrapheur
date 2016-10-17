//============================================================================
// Name        : Part1.cpp
// Author      : Mardon Florian
// Version     :
// Copyright   : Copyright Mardon Florian & Co
//============================================================================
// TODO: Ajout du traitement des décimaux
//============================================================================
#include <iostream>
#include "StructDatas.h"
using namespace std;
string mainString="2+2";

int main() {
	//TODO
}

bool isFunction(char cara){
	if ((cara>'A' && cara<'Z' && cara!='X') || (cara>'a' && cara<'z' && cara!='x')){
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

string* toLexeme(string chaine){
	char cara;
	int i=0;
	while (i<chaine.length){
		cara=chaine[i];
		if (isFunction(cara)){
			string chainePro=cara+"";
			i++;
			cara=chaine[i];
			while (isFunction(cara)){
				chainePro=chainePro+cara;
				i++;
				cara=chaine[i];
			}
			//TODO Verifier que la fonction existe bien
			return "FUNCTION";
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
				return "REEL";
				i--;
			}
		}else if (isVar(cara)){
			return "VARIABLE";
		}else if (isOperator(cara)){
			return "OPERATEUR";
		}else if (isParenthesisOpens(cara)){
			return "PARENT_OPEN";
		}else if (isParenthesisClosing(cara)){
			return "PARENT_CLOSE";
		}else{
		// TODO retourner une erreur référent à un caractère inconnus dans l'operation
		}
		i++;
	}
}
