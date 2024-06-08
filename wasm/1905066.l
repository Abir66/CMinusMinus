%option noyywrap

%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT
%x CHARACTER_LITERAL
%x STRING_LITERAL

%{
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "symbol-table/1905066_symbolTable.h"
#include "y.tab.hpp"

//extern YYSTYPE yylval;
extern SymbolTable *symbolTable;

extern std::ofstream logout;
extern std::ofstream tokenout;
extern std::ofstream errorout;
extern int line_count=1;
extern int error_count = 0;

extern int temp_line_count=0;


std::string comment;
std::string string_type;
std::string string_token;
std::string string_log;



void printLog(std::string token, std::string lexeme){
	logout<<"Line# "<<line_count<<": Token <"<<token<<"> Lexeme "<<lexeme<<" found"<<std::endl;
}

void printToken(std::string token, std::string lexeme){
	//tokenout<<"<"<<token<<", "<<lexeme<<">"<<std::endl;	
}


void printFunc(std::string token, std::string lexeme){
	printLog(token,lexeme);
	//printToken(token,lexeme);
}

void generateError(std::string errorType, std::string errorLexem, int line_no = line_count){
	error_count++;
	logout<<"Error at line# "<<line_no<<": "<<errorType<<" "<<errorLexem<<std::endl;
}


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
ALPHANUMERIC [a-zA-Z0-9_]
NEWLINE (\r)?\n
IDENTIFIER [a-zA-Z_]{ALPHANUMERIC}*
INTEGER {DIGIT}+
FLOAT ({DIGIT}+(\.{DIGIT}+)?|(\.{DIGIT}+))([Ee][+-]?{DIGIT}+)?|{INTEGER}\.

/* cpp allows numbers like 123.  -.-*/

%%

{WHITESPACE} { /* do nothing */ }
{NEWLINE} {line_count++;}


 /* ===================== Keywords ===================== */

"if"		{ yylval.symbolInfo = new SymbolInfo(yytext, "IF", line_count, line_count); 				printFunc("IF",yytext);  		return IF;}
"else"		{ yylval.symbolInfo = new SymbolInfo(yytext, "ELSE", line_count, line_count); 				printFunc("ELSE",yytext);  		return ELSE;}
"for"		{ yylval.symbolInfo = new SymbolInfo(yytext, "FOR", line_count, line_count); 				printFunc("FOR",yytext);  		return FOR;}
"while"		{ yylval.symbolInfo = new SymbolInfo(yytext, "WHILE", line_count, line_count); 				printFunc("WHILE",yytext);  	return WHILE;}
"do"		{ yylval.symbolInfo = new SymbolInfo(yytext, "DO", line_count, line_count); 				printFunc("DO",yytext);  		return DO;}
"break"		{ yylval.symbolInfo = new SymbolInfo(yytext, "BREAK", line_count, line_count); 				printFunc("BREAK",yytext);  	return BREAK;}
"int"		{ yylval.symbolInfo = new SymbolInfo(yytext, "INT", "INT", line_count, line_count); 		printFunc("INT",yytext);  		return INT;}
"char"		{ yylval.symbolInfo = new SymbolInfo(yytext, "CHAR", "CHAR", line_count, line_count); 		printFunc("CHAR",yytext);  		return CHAR;}
"float"		{ yylval.symbolInfo = new SymbolInfo(yytext, "FLOAT", "FLOAT", line_count, line_count); 	printFunc("FLOAT",yytext);  	return FLOAT;}
"double"	{ yylval.symbolInfo = new SymbolInfo(yytext, "DOUBLE", "DOUBLE", line_count, line_count); 	printFunc("DOUBLE",yytext);  	return DOUBLE;}
"void"		{ yylval.symbolInfo = new SymbolInfo(yytext, "VOID", "VOID", line_count, line_count); 		printFunc("VOID",yytext);  		return VOID;}
"return"	{ yylval.symbolInfo = new SymbolInfo(yytext, "RETURN", line_count, line_count); 			printFunc("RETURN",yytext);  	return RETURN;}
"switch"	{ yylval.symbolInfo = new SymbolInfo(yytext, "SWITCH", line_count, line_count); 			printFunc("SWITCH",yytext);  	return SWITCH;}
"case"		{ yylval.symbolInfo = new SymbolInfo(yytext, "CASE", line_count, line_count); 				printFunc("CASE",yytext);  		return CASE;}
"default"	{ yylval.symbolInfo = new SymbolInfo(yytext, "DEFAULT", line_count, line_count); 			printFunc("DEFAULT",yytext);  	return DEFAULT;}
"continue"	{ yylval.symbolInfo = new SymbolInfo(yytext, "CONTINUE", line_count, line_count); 			printFunc("CONTINUE",yytext);  	return CONTINUE;}
"println"	{ yylval.symbolInfo = new SymbolInfo(yytext, "PRINTLN", line_count, line_count); 			printFunc("PRINTLN",yytext); 	return PRINTLN;}
"print"		{ yylval.symbolInfo = new SymbolInfo(yytext, "PRINT", line_count, line_count); 				printFunc("PRINT",yytext); 		return PRINT;}
"scan"		{ yylval.symbolInfo = new SymbolInfo(yytext, "scanInt", line_count, line_count); 				printFunc("scanInt",yytext); 		return SCANINT;}

 /* ===================== Identifiers ===================== */
{IDENTIFIER} {
	printFunc("ID",yytext); 
	yylval.symbolInfo = new SymbolInfo(yytext, "ID", line_count, line_count); 
	return ID;
}

 /* ===================== Numbers ===================== */
{INTEGER} {
	printFunc("CONST_INT",yytext);
	yylval.symbolInfo = new SymbolInfo(yytext, "CONST_INT", "INT", line_count, line_count);
	return CONST_INT;
}
{FLOAT}	{
	printFunc("CONST_FLOAT",yytext); 
	yylval.symbolInfo = new SymbolInfo(yytext, "CONST_FLOAT", "FLOAT", line_count, line_count);
	return CONST_FLOAT;
}




 /* ===================== TOO MANY DECIMAL POINTS ===================== */
(({DIGIT}+\.{DIGIT}*)|(\.{DIGIT}+))+(\.{DIGIT}*)+((([Ee][+-]?)?[\.0-9]+)?{IDENTIFIER}?)*	{generateError("TOO_MANY_DECIMAL_POINTS",yytext);}
 
 /* ===================== ILLFORMED_NUMBER ===================== */
({INTEGER}|{FLOAT})[Ee][+-]?[0-9]*\.((([Ee][+-]?)?[\.0-9]+)?{IDENTIFIER}?)* {generateError("ILLFORMED_NUMBER",yytext);}

 /* ===================== INVALID_ID_SUFFIX_NUM_PREFIX ===================== */
{INTEGER}{IDENTIFIER}|{FLOAT}{IDENTIFIER}	{generateError("INVALID_ID_SUFFIX_NUM_PREFIX",yytext);}


 /* ===================== operators ===================== */
"+"|"-"						printFunc("ADDOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "ADDOP", line_count, line_count); return ADDOP;
"*"|"/"|"%"					printFunc("MULOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "MULOP", line_count, line_count); return MULOP;
"++"						printFunc("INCOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "INCOP", line_count, line_count); return INCOP;
"--"						printFunc("DECOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "DECOP", line_count, line_count); return DECOP;
"<"|"<="|">"|">="|"=="|"!="	printFunc("RELOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "RELOP", line_count, line_count); return RELOP;
"="							printFunc("ASSIGNOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "ASSIGNOP", line_count, line_count); return ASSIGNOP;
"&&"|"||"					printFunc("LOGICOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "LOGICOP", line_count, line_count); return LOGICOP;
"&"|"|"|"^"|"<<"|">>"		printFunc("BITOP",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "BITOP", line_count, line_count); return BITOP;
"!"							printFunc("NOT",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "NOT", line_count, line_count); return NOT;


 /*===================== punctuatuion ===================== */

"("		printFunc("LPAREN",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "LPAREN", line_count, line_count); return LPAREN;
")"		printFunc("RPAREN",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "RPAREN", line_count, line_count); return RPAREN;
"{"		printFunc("LCURL",yytext);  yylval.symbolInfo = new SymbolInfo(yytext, "LCURL", line_count, line_count); return LCURL;
"}"		printFunc("RCURL",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "RCURL", line_count, line_count); return RCURL;
"["		printFunc("LSQUARE",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "LSQUARE", line_count, line_count); return LTHIRD;
"]"		printFunc("RSQUARE",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "RSQUARE", line_count, line_count); return RTHIRD;
","		printFunc("COMMA",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "COMMA", line_count, line_count); return COMMA;
";"		printFunc("SEMICOLON",yytext); yylval.symbolInfo = new SymbolInfo(yytext, "SEMICOLON", line_count, line_count); return SEMICOLON;



 /* ===================== character literal ===================== */

"'"		{	
			string_token = "";
			string_log = "\'";
			BEGIN CHARACTER_LITERAL;	
		}

<CHARACTER_LITERAL,STRING_LITERAL>\\\\		string_token += "\\"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\\'		string_token += "\'"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\\"		string_token += "\""; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\n		string_token += "\n"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\t      	string_token += "\t"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\a		string_token += "\a"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\b      	string_token += "\b"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\f      	string_token += "\f"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\r      	string_token += "\r"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\v      	string_token += "\v"; string_log += yytext;
<CHARACTER_LITERAL,STRING_LITERAL>\\0		string_token += "\0"; string_log += yytext;


<CHARACTER_LITERAL>{NEWLINE}	{
	//generateError("UNFINISHED_CONST_CHAR", string_log);
	line_count++;
	BEGIN INITIAL;
}

<CHARACTER_LITERAL><<EOF>>	{
	//generateError("UNFINISHED_CONST_CHAR", string_log);
	BEGIN INITIAL;
}

<CHARACTER_LITERAL>\'	{
	string_log += "'";

	if(string_token.length() == 1) {
		//printFunc("CONST_CHAR",string_token);
	}
	
	else if(string_token.length()>1) {
		//generateError("MULTICHAR_CONST_CHAR", string_log);
	}
	
	else if(string_token.length() == 0){
		if(string_log == "\\0") {
			//printFunc("CONST_CHAR",string_token);
		}
		else {
			//generateError("EMPTY_CONST_CHAR", string_log);
		}
	}

	BEGIN INITIAL;
}


 /*	This is not standard c/c++ syntax
	was not specified in the offline discription either
	Having to add this for a io provided (input3) -.-*/

<CHARACTER_LITERAL>;	{
	if(string_token.length()==0){
		string_token += yytext;
		string_log += yytext;
	}

	else {
		//generateError("UNFINISHED_CONST_CHAR", string_log);
		//printFunc("SEMICOLON",yytext);
		BEGIN INITIAL;
	}
}

<CHARACTER_LITERAL>.	string_token += yytext; string_log += yytext;



 /* ===================== string literal ===================== */

\"		{	
			string_log = "\"";
			string_token = "";
			string_type = "SINGLE LINE STRING";
			temp_line_count = 0;
			BEGIN STRING_LITERAL;	
		}


<STRING_LITERAL>\\{NEWLINE}	{
								temp_line_count++;
								string_log += "\\\n";
								string_type = "MULTI LINE STRING";
							}

<STRING_LITERAL><<EOF>>		{
								//generateError("UNFINISHED_STRING", string_log);
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>{NEWLINE}	{
								//generateError("UNFINISHED_STRING", string_log, line_count+temp_line_count);
								temp_line_count++;
								line_count += temp_line_count;
								BEGIN INITIAL;
							}

<STRING_LITERAL>\"	{
						string_log += "\"";
						//printLog(string_type, string_log);
						//printToken(string_type, string_token);
						yylval.symbolInfo = new SymbolInfo(string_token, "CONST_STRING", line_count, line_count+temp_line_count);
						line_count += temp_line_count;
						
						BEGIN INITIAL;
						return CONST_STRING;
					}


<STRING_LITERAL>. {string_log += yytext; string_token += yytext;}

 /* ===================== Single line comment ===================== */
"//"	{	
			comment = "//";
			temp_line_count = 1;
			BEGIN SINGLE_LINE_COMMENT;	
		}

<SINGLE_LINE_COMMENT>\\{NEWLINE}	{
										comment += "\\\n";
										temp_line_count++;
									}

<SINGLE_LINE_COMMENT>{NEWLINE}		{
										//printLog("SINGLE LINE COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}

<SINGLE_LINE_COMMENT><<EOF>>		{
										//printLog("SINGLE LINE COMMENT",comment);
										line_count += temp_line_count;
										BEGIN INITIAL;
									}


<SINGLE_LINE_COMMENT>.				{ comment += yytext; }



 /* ===================== Multi line comment ===================== */
"/*"	{	
			comment = "/*";
			temp_line_count = 0;
			BEGIN MULTI_LINE_COMMENT;	
		}

<MULTI_LINE_COMMENT>{NEWLINE}	{
									comment += "\n";
									temp_line_count++;
								}

<MULTI_LINE_COMMENT>"*/"		{
									comment += "*/";
									//printLog("MULTI LINE COMMENT",comment);
									line_count += temp_line_count;
									BEGIN INITIAL;
								}



<MULTI_LINE_COMMENT><<EOF>>		{	
									line_count += temp_line_count;
									//generateError("UNFINISHED_COMMENT", comment);
									BEGIN INITIAL;
								}

<MULTI_LINE_COMMENT>.	{ comment += yytext; }

"#"	{	
			comment = "//";
			temp_line_count = 1;
			BEGIN SINGLE_LINE_COMMENT;	
		}

<<EOF>>	return 0;


.	{ generateError("UNRECOGNIZED_CHAR",yytext); }

%%

