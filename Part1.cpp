//============================================================================
// Name        : Part1.cpp
// Author      : Mardon Florian
// Version     :
// Copyright   : Copyright Mardon Florian & Co
//============================================================================
// TODO: Ajout du traitement des décimaux
//============================================================================
#include <iostream>
#include <sstream>
#include "..\StructDatas.h"
#include <string>
#include <vector>
using namespace std;

string mainString="tan(23+4)";
bool error=false; // Cette variable va servir à verifier si le code tombe en erreur ou non
				  // Pour renvoyer uniquement le code erreur si c'est le cas
template <typename T>
string NumberToString(T Number){ //Methode pour convertir les nombres en String
	ostringstream ss;
	ss << Number;
	return ss.str();
}

float string2float(string str){ //Methode pour convertir une chaine String en float (utilisé pour traiter les décimaux => FDP)
	stringstream ss;			// *Vous avez compris la blague, les traiter genre insulter :D*
	float f;
	ss.str(str);
	ss >> f;
	return f;
}

// /!\ Les méthodes qui suivent servent à éfféctuer une première vérification sur l'origine d'une partie de l'opération
// --------------------------------------------------------------------------------------------------------------------

bool isFunction(char cara){
	if ((cara>='A' && cara<='Z' && cara!='X') || (cara>='a' && cara<='z' && cara!='x')){
		return true;
	}
	return false;
}

bool isNumber(char cara){
	if (cara>='0' && cara<='9' || cara==',' || cara=='.'){ //Pour donner plus de précision aux erreur, on inclus les ',' et '.'
		return true;									   //que nous traiterons dans la méthode aToken
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

// --------------------------------------------------------------------------------------------------------------------
// La méthode qui suis représente le code principale de la partie d'analyse lexicale
// --------------------------------------------------------------------------------------------------------------------

vector<Jeton> aToken(string chaine){ // a prononcer "haDoken" pour la blague ;)

	vector<Jeton> res;
	char cara;

	Lexeme lex; // définis la correspondance de la valeur associé dans le token (jeton)
	Valeur val; // définis par fonction OU opérateur OU valeur
	try{
	int i=0;
	while (i<(int)chaine.size()){
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
				throw string("ERREUR: Fonction utilisé non-reconnus...");
			}
		}else if (isNumber(cara)){
			lex=REEL;
			bool verif=false;  //Va servir à vérifier si le nombre contient 2 virgules ou plus (cas d'erreur)
			bool verif2=false; //Va servir à verifier si le nombre se termine par une virgule (cas d'erreur)
			string nomb="";
			if (cara==',' || cara=='.'){
				throw string("ERREUR: L'un des nombres commence par une virgule...");
			}
			while (isNumber(cara) || cara==',' || cara=='.'){
				if (verif==false && (cara==',' || cara=='.')){ //Au premier passage de virgule on va changer les verif en true
					verif=true;
					verif2=true;
					nomb=nomb+cara;
				}else if(verif==true && (cara==',' || cara=='.')){ //Ainsi on peut repérer le cas d'une seconde virgules
					throw string("ERREUR: 2 virgules pour l'un des nombres...");
				}else{ //Et verifier grace a verif2 que le nombre ne se termine pas par une virgule
					nomb=nomb+cara;
					verif2=false;
				}
				i++;
				cara=chaine[i];
			}
			if (verif2==true){
				throw string("ERREUR: L'un des nombre se termine par une virgule...");
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
				throw string("FATAL ERROR ! Cette erreur est impossible à atteindre...");
			}
		}else if (isParenthesisOpens(cara)){
			lex=PARENT_OPEN;
		}else if (isParenthesisClosing(cara)){
			lex=PARENT_CLOSE;
		}else{
			throw string("ERREUR: Un caractère inconnus a été entré...");
		}
		Jeton token;
		token.lexeme=lex;
		token.valeur=val;
		res.push_back(token);
		i++;
	}
	}catch(string const& chaine){
				cerr << chaine << endl;
				error=true;
	}
	return res;
}
