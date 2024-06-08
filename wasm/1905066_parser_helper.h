#ifndef PARSER_HELPER_H
#define PARSER_HELPER_H


#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"

using namespace std;

int yyparse(void); 
int yylex(void);
extern FILE *yyin;
extern int yylineno;
extern int line_count;
extern int error_count;
extern int temp_line_count;
int yylex_destroy(void);


//io
std::ofstream logout;
std::ofstream errorOut;
std::ofstream parseTreeOut;


void yyerror(char *s)
{
	logout<<"Error at line no "<<line_count<<": "<<s<<endl;
	errorOut<<"Error at line no "<<line_count<<": "<<s<<std::endl;
	error_count++;
}



void printLog(std::string str){
	logout<<str<<std::endl;
}

void semanticError(int lineno, std::string error_text){
	errorOut<<"Line# "<<lineno<<": "<<error_text<<std::endl;
	error_count++;
}


void printParseTree(SymbolInfo* symbol, int indent){
	// print indent number of spaces
	for(int i = 0; i < indent; i++) parseTreeOut<<" ";

	// print the symbol
	symbol->printParseGrammarRule(parseTreeOut);

	// print the children
	for(auto child : symbol->getChildren()) printParseTree(child, indent + 1);

	// delete the symbol
	if(symbol) delete symbol;
}



SymbolTable *symbolTable = new SymbolTable(11, logout);

std::vector<SymbolInfo*> vars, params;
SymbolInfo* currentFunction = NULL;



void setVarsDataType(std::string dataType){
	for(auto var : vars) var->setDataType(dataType);
}


void addFunction(SymbolInfo* function, std::string returnType, bool define = false){

	function->setDataType(returnType);
	function->addParams(params);
	function->setFuncDeclared();

	currentFunction = function;

	if(define){
		
		function->setFuncDefined(function->getStartLine());
		
		for(auto param : params){
			if(param->getName() == ""){
				// unnamed parameter error
				std::string error = "Unnamed parameter at line " + std::to_string(param->getStartLine());
				semanticError(param->getStartLine(), error);
			}
		}
	}
	
	params.clear();
	
	bool success = symbolTable->insert(function);
	//addParamsToScope();

	if(success) {
		currentFunction = function;
		return;
	} 
	

	SymbolInfo* existingFunction = symbolTable->lookup(function->getName());


	if(!existingFunction->isFunction()){
		// already a declared variable error
		std::string error = "'" + function->getName() + "' redeclared as different kind of symbol";
		semanticError(function->getStartLine(), error);
		return;
	}

	else if(existingFunction->isFuncDefined()){
		// function already defined error
		std::string error = "Function '" + function->getName() + "' already defined at line " + std::to_string(existingFunction->getDefinedLine());
		semanticError(function->getStartLine(), error);
	}

	else if(existingFunction->isFuncDeclared() && !define) {
		// multiple declaration error
		std::string error = "Function '" + function->getName() + "' already declared at line " + std::to_string(existingFunction->getStartLine());
		semanticError(function->getStartLine(), error);
	}

	else if(existingFunction->isFuncDeclared() && define){
		

		if(existingFunction->getDataType() != returnType){
			// return type mismatch error
			std::string error = "Return type mismatch with function declaration at line " + std::to_string(existingFunction->getStartLine());
			semanticError(function->getStartLine(), error);
		}

		else if(existingFunction->getParamCount() != function->getParamCount()){
			// parameter count mismatch error
			std::string error = "Parameter count mismatch with function declaration at line " + std::to_string(existingFunction->getStartLine());
			semanticError(function->getStartLine(), error);
		}

		else {

			auto existingParams = existingFunction->getParams();
			auto newParams = function->getParams();

			for(int i = 0; i < existingParams.size(); i++){
				if(existingParams[i]->getDataType() != newParams[i]->getDataType()){
					// parameter type mismatch error
					std::string error = "Parameter type mismatch (for parameter : " + existingParams[i]->getName() + ") with function declaration at line " + std::to_string(existingFunction->getStartLine());
					semanticError(function->getStartLine(), error);
				}
			}

			//existingFunction->setDefined();
			existingFunction->setParams(newParams);
			currentFunction = function;
		}
	}

	if(define && existingFunction->isFunction()) existingFunction->setFuncDefined(function->getStartLine());

}

bool checkParamRedeclaration(SymbolInfo* newParam){
	for(auto param : params){
		if(param->getName() == newParam->getName()){
			// parameter redeclaration error
			std::string error = "Redefinition of parameter '" + newParam->getName() + "'";
			semanticError(newParam->getStartLine(), error);
			return true;
		}
	}
	return false;
}

void addParamsToScope(){
	
	if(currentFunction == NULL) return;
	
	int offset = 4 + 2*(currentFunction->getParamCount() - 1);
	
	// std::cout<<"Adding params to scope "<<symbolTable->getCurrentScopeId()<<std::endl;
	// std::cout<<"currentFunction->getParamCount() = "<<currentFunction->getParamCount()<<std::endl;

	for(auto param : currentFunction->getParams()){
		// std::cout<<"param->getName() = "<<param->getName()<<std::endl; 
		if(param->getName() != ""){
			param->setAsmName("[BP+" + to_string(offset) + "]");
			offset -= 2;
			symbolTable->insert(param);
			// std::cout<<"Inserted "<<param->getName()<<" in scope "<<symbolTable->getCurrentScopeId() <<" with asmName "<<param->getAsmName()<<std::endl;
		}
	}

	currentFunction = NULL;
}

SymbolInfo* checkValidVar(SymbolInfo* id, bool isArray = false){
	
	auto var = symbolTable->lookup(id->getName());

	if(!var){
		// undeclared variable error
		std::string error = "Undeclared variable '" + id->getName() + "'";
		semanticError(id->getStartLine(), error);
	}

	else if(isArray && !var->isArray()){
		// array
		std::string error = "'" + id->getName() + "' is not an array";
		semanticError(id->getStartLine(), error);
	}

	else if(!isArray && var->isArray()){
		// array
		std::string error = "Array '" + id->getName() + "' used as a variable at line " + std::to_string(id->getStartLine());
		semanticError(id->getStartLine(), error); 
	}

	else if(var->isFunction()){
		// function call error
		std::string error = "Function '" + id->getName() + "' used as a variable at line " + std::to_string(id->getStartLine());
		semanticError(id->getStartLine(), error);
	}

	return var;
}

std::string typecast(SymbolInfo *left_symbol, SymbolInfo *right_symbol){
	if(left_symbol->getDataType() == "VOID" || right_symbol->getDataType() == "VOID") return "VOID"; // error
	else if(left_symbol->getDataType() == "DOUBLE" || right_symbol->getDataType() == "DOUBLE") return "DOUBLE";
	else if(left_symbol->getDataType() == "FLOAT" || right_symbol->getDataType() == "FLOAT") return "FLOAT";
	else return "INT";
}


void finishParsing(SymbolInfo* start){
	printLog("start : program");
	logout<<"Total Lines: "<<line_count<<std::endl;
	logout<<"Total Errors: "<<error_count<<std::endl;
	printParseTree(start, 0);
	delete symbolTable;
}



#endif