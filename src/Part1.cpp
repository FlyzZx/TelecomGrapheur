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
	//TODO chercher comment verifier la fonction sur plusieurs caractères (sin,cos,... => plusieurs caractères)
		return "FUNCTION";
	}else if (isNumber(cara)){
	//TODO chercher comment verifier la fonction sur plusieurs caractères (42,267,... => plusieurs caractères)
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
	// TODO retourner une erreur référent à un caractère inconnus dans l'operation
	}
}
