//============================================================================
// Name        : Part1.cpp
// Author      : Mardon Florian
// Version     :
// Copyright   : Copyright Mardon Florian & Co
//============================================================================
// TODO: Ajout du traitement des d�cimaux
//============================================================================
#include <iostream>
#include "StructDatas.h"
using namespace std;
string mainString="2+2";

int main() {
	//TODO
}

bool isFunction(char cara){
	//TODO
}

bool isNumber(char cara){
	//TODO
}

bool isVar(char cara){
	//TODO
}

bool isOperator(char cara){
	//TODO
}

bool isParenthesisOpens(char cara){
	//TODO
}

bool isParenthesisClosing(char cara){
	//TODO
}

string toLexeme(char cara){
	if (isFunction(cara)){
	//TODO chercher comment verifier la fonction sur plusieurs caract�res (sin,cos,... => plusieurs caract�res)
		return "FUNCTION";
	}else if (isNumber(cara)){
	//TODO chercher comment verifier la fonction sur plusieurs caract�res (42,267,... => plusieurs caract�res)
		return "REEL";
	}else if (isVar(cara)){
		return "VARIABLE";
	}else if (isOperator(cara)){
		return "OPERATEUR";
	}else if (isParenthesisOpens(cara)){
		return "PARENT_OPEN";
	}else if (isParenthesisClosing(cara)){
		return "PARENT_CLOSE";
	}else{
	// TODO retourner une erreur r�f�rent � un caract�re inconnus dans l'operation
	}
}
