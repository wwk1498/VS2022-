#include<iostream>
#include"parsedef.h"
#include "lex.h"
using namespace std;

int main() {

	vector<pair<string, string>> torm;

	Lexical lex;
	ifstream file;
	lex.getFilename(file);
	torm=lex.InputFile(file, torm);

	Parser parse(torm, 0, 0);
	
	parse.inputl();
	parse.printl();

	system("pause");
	return 0;
}

/*
{"INTTK" , "int"} ,
{"MAINTK"  ,"main"},
{"LPARENT","("},
{"RPARENT",")"},
{"LBRACE"  ,"{"},
{"INTTK"  ,"int"},
{"IDENFR" , "c"},
{"SEMICN",";"},
{"IDENFR"  ,"c"},
{"ASSIGN" ,"="},
{"GETINTTK" , "getint"},
{"LPARENT","("},
{"RPARENT",")"},
{"SEMICN",";"},
{"PRINTFTK", "printf"},
{"LPARENT","("},
{"STRCON", "\"%d\""},
{"COMMA",","},
{"IDENFR" , "c"},
{"RPARENT",")"},
{"SEMICN",";"},
{"RETURNTK", "return"},
{"IDENFR",  "c"},
{"SEMICN",";"},
{"RBRACE","}"}

*/