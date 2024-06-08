%{
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include"symbol-table/1905066_symbolTable.h"
#include"1905066_parser_helper.h"
#include"1905066_ICG_helper.h"

using namespace std;


%}


%union{
    SymbolInfo* symbolInfo; 
}

%token<symbolInfo>  IF ELSE FOR WHILE DO BREAK RETURN SWITCH CASE DEFAULT CONTINUE  LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON PRINTLN PRINT INCOP DECOP ASSIGNOP NOT
%token<symbolInfo> ID INT FLOAT DOUBLE CONST_INT CONST_FLOAT CHAR VOID ADDOP MULOP RELOP  LOGICOP BITOP CONST_STRING SCANINT

%type<symbolInfo> variable factor term unary_expression simple_expression rel_expression logic_expression expression M N P
%type<symbolInfo> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement argument_list arguments


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%


start : program {
		$$ = new SymbolInfo("start", "non-terminal");
		$$->addChildren($1);
		finishParsing($$);
	};

program : program unit {
		printLog("program : program unit");
		$$ = new SymbolInfo("program", "non-terminal");
		$$->addChildren({$1,$2});
	}
	| unit{
		printLog("program : unit");
		$$ = new SymbolInfo("program", "non-terminal");
		$$->addChildren($1);
	}
	;

unit : var_declaration {
		printLog("unit : var_declaration");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	| func_declaration
	{
		printLog("unit : func_declaration");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	| func_definition
	{
		printLog("unit : func_definition");
		$$ = new SymbolInfo("unit", "non-terminal");
		$$->addChildren($1);
	}
	;

func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
		printLog("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		$$ = new SymbolInfo("func_declaration", "non-terminal");
		$$->setDataType($1->getDataType());

		addFunction($2, $1->getDataType());

		$$->addChildren({$1, $2, $3, $4, $5, $6});
	}
	| type_specifier ID LPAREN RPAREN SEMICOLON {
		printLog("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		$$ = new SymbolInfo("func_declaration", $1->getType());
		$$->setDataType($1->getDataType());

		addFunction($2, $1->getDataType());
		$$->addChildren({$1, $2, $3, $4, $5});
	}
	;

func_definition : type_specifier ID LPAREN parameter_list RPAREN { 
		addFunction($2, $1->getDataType(), true);
		inGlobalScope = false;
		genFunctioninitCode($2->getName());
	} compound_statement {
		printLog("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");

		$$->addChildren({$1, $2, $3, $4, $5, $7});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup($2->getName());
		if($7->getNextList().size() > 0){
			for(auto line : $7->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);
	
	}
	| type_specifier ID LPAREN RPAREN { 
		addFunction($2, $1->getDataType(), true); 
		inGlobalScope = false;
		genFunctioninitCode($2->getName());
	} compound_statement {
		printLog("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		$$ = new SymbolInfo("func_definition", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $6});
		
		//------------------code generation------------------
		auto func = symbolTable->lookup($2->getName());
		if($6->getNextList().size() > 0){
			for(auto line : $6->getNextList()) function_return_lines.push_back(line);
		}
		genFunctionEndingCode(func);

	}
	;

parameter_list : parameter_list COMMA type_specifier ID {
		printLog("parameter_list : parameter_list COMMA type_specifier ID");
		$$ = new SymbolInfo("parameter_list", $1->getType());

		$4->setDataType($3->getDataType());

		if(!checkParamRedeclaration($4)) params.push_back($4);
		
		
		$$->addChildren({$1, $2, $3, $4});

	}
	| parameter_list COMMA type_specifier {
		printLog("parameter_list : parameter_list COMMA type_specifier");
		$$ = new SymbolInfo("parameter_list", $1->getType());

		SymbolInfo* id = new SymbolInfo("", "ID", $3->getDataType());
		params.push_back(id);

		$$->addChildren({$1, $2, $3});
	}
	| type_specifier ID {
		printLog("parameter_list : type_specifier ID");
		$$ = new SymbolInfo("parameter_list", "non-terminal");

		$2->setDataType($1->getDataType());
		if(!checkParamRedeclaration($2)) params.push_back($2);
		
		$$->addChildren({$1, $2});
	}
	| type_specifier {
		printLog("parameter_list : type_specifier");
		$$ = new SymbolInfo("parameter_list", "non-terminal");

		SymbolInfo* id = new SymbolInfo("", "ID", $1->getDataType());
		params.push_back(id);

		$$->addChildren($1);
	}
	;

compound_statement : LCURL {symbolTable->enterScope(); addParamsToScope();} statements RCURL {
		printLog("compound_statement : LCURL statements RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $3, $4});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();

		// ------------------code generation------------------
		// if($3->getNextList().size() > 0){
		// 	for(auto line : $3->getNextList()) function_return_lines.push_back(line);
		// }

		$$->setNextList($3->getNextList());
		
	}
	| LCURL {symbolTable->enterScope(); addParamsToScope();} RCURL {
		printLog("compound_statement : LCURL RCURL");
		$$ = new SymbolInfo("compound_statement", "non-terminal");
		$$->addChildren({$1, $3});
		symbolTable->printAllScopeTable();
		symbolTable->exitScope();
	}
	;

var_declaration : type_specifier declaration_list SEMICOLON {
		printLog("var_declaration : type_specifier declaration_list SEMICOLON");
		$$ = new SymbolInfo("var_declaration", "non-terminal");
		setVarsDataType($1->getDataType());
		$$->addChildren({$1, $2, $3});

		genVarDeclarationCode();

		// insert in symbol table
		for(auto var : vars){
			bool success = symbolTable->insert(var);
			if(!success){
				std::string error_message = "Redeclaration of variable '" + var->getName() + "'";
				semanticError(var->getStartLine(), error_message);
			}

			if($1->getDataType() == "VOID"){
				std::string error_message = "Variable or field '" + var->getName() + "' declared void";
				semanticError(var->getStartLine(), error_message);
			}
		}

	}
	;

type_specifier : INT {
		printLog("type_specifier : INT");
		$$ = new SymbolInfo("type_specifier", "INT", $1->getDataType());
		$$->addChildren($1);
		
	}
	| FLOAT {
		printLog("type_specifier : FLOAT");
		$$ = new SymbolInfo("type_specifier", "FLOAT", $1->getDataType());
		$$->addChildren($1);
		
	}
	| VOID {
		printLog("type_specifier : VOID");
		$$ = new SymbolInfo("type_specifier", "VOID", $1->getDataType());
		$$->addChildren($1);
		
	}
	;

declaration_list : declaration_list COMMA ID {
		printLog("declaration_list : declaration_list COMMA ID");
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back($3);

		$$->addChildren({$1,$2,$3});
	}
	| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
		printLog("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		$3->setArray(true, std::stoi($5->getName()));
		vars.push_back($3);

		$$->addChildren({$1,$2,$3,$4,$5,$6});
	}
	| ID {
		printLog("declaration_list : ID");
		vars.clear();
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		vars.push_back($1);
		$$->addChildren($1);
		
	}
	| ID LTHIRD CONST_INT RTHIRD {
		printLog("declaration_list : ID LTHIRD CONST_INT RTHIRD");
		vars.clear();
		$$ = new SymbolInfo("declaration_list", "non-terminal");
		$1->setArray(true, std::stoi($3->getName()));
		vars.push_back($1);

		$$->addChildren({$1,$2,$3,$4});
	}
	;

statements : {genComment("------------------ Line " + to_string(line_count) + " ------------------");} statement {
		printLog("statements : statement");
		$$ = new SymbolInfo("statements", "non-terminal");
		$$->addChildren($2);

		// ------------------ code generation ------------------
		$$->setNextList($2->getNextList());
		
		// std::cout<<"here - "<<$2->getLabel()<<std::endl;
		// backpatch($1->getNextList(), $2->getLabel());
	}
	| statements M {genComment("------------------ Line " + to_string(line_count) + " ------------------");} statement {
		printLog("statements : statements statement");
		$$ = new SymbolInfo("statements", "non-terminal");
		$$->addChildren({$1, $4});

		// ------------------ code generation ------------------
		backpatch($1->getNextList(), $2->getLabel());
		$$->setNextList($4->getNextList());
	}
	;

statement : var_declaration {
		printLog("statement : var_declaration");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);
	}
	| expression_statement {
		printLog("statement : expression statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);
		$$->copyICGData($1);

		if(!$1->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			$$->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch($1->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch($1->getFalseList(), label);

			// label = new_label();
			// genCode(label + ":");
			// backpatch($$->getNextList(), label);			
		}

		
	}
	| compound_statement {
		printLog("statement : compound_statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren($1);

		// ------------------ code generation ------------------
		$$->setNextList($1->getNextList());
	}
	| FOR LPAREN expression_statement M expression_statement { normal_expression_to_logic($5, false); } M expression {genCode("\tPOP AX"); genCode("\tJMP " + $4->getLabel());} RPAREN M statement {
		printLog("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $5, $8, $10, $12});

		//------------------code generation------------------
		auto S1 = $3;
		auto B = $5;
		auto S2 = $8;
		auto S3 = $12;
		auto M1 = $4;
		auto M2 = $7;
		auto M3 = $11;

		normal_expression_to_logic(B);

		backpatch(B->getTrueList(), M3->getLabel());
		backpatch(S3->getNextList(), M2->getLabel());
		// $$->setNextList(merge(B->getFalseList(), S3->getNextList()));
		$$->setNextList(B->getFalseList());
		genCode("\tJMP " + M2->getLabel());

	}
	| IF LPAREN expression P RPAREN M statement %prec LOWER_THAN_ELSE {
		printLog("statement : IF LPAREN expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $5, $7});

		//------------------code generation------------------
		backpatch($3->getTrueList(), $6->getLabel());
		$$->setNextList(merge($3->getFalseList(), $7->getNextList()));

	}
	| IF LPAREN expression P RPAREN M statement ELSE N M statement {
		printLog("statement : IF LPAREN expression RPAREN statement ELSE statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $5, $7, $8, $11});

		//------------------code generation------------------
		auto B = $3;
		auto M1 = $6;
		auto M2 = $10;
		auto N = $9;
		auto S1 = $7;
		auto S2 = $11;

		backpatch(B->getTrueList(), M1->getLabel());
		backpatch(B->getFalseList(), M2->getLabel());
		auto temp = merge(S1->getNextList(), N->getNextList());
		$$->setNextList(merge(temp, S2->getNextList()));

	}
	| WHILE M LPAREN expression { normal_expression_to_logic($4); } RPAREN M statement {
		printLog("statement : WHILE LPAREN expression RPAREN statement");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $3, $4, $6, $7});

		//------------------code generation------------------
		auto M1 = $2;
		auto B = $4;
		auto M2 = $7;
		auto S1 = $6;

		backpatch(S1->getNextList(), M1->getLabel());
		backpatch(B->getTrueList(), M2->getLabel());
		$$->setNextList(B->getFalseList());
		genCode("\tJMP " + M1->getLabel());
	}
	/* | PRINTLN LPAREN ID RPAREN SEMICOLON {
		printLog("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");

		// check if ID declared
		SymbolInfo *symbol = symbolTable->lookup($3->getName());
		if(!symbol) {
			std::string error_message = "Undeclared variable " + $3->getName() + " in line " + std::to_string($3->getStartLine());
			semanticError($3->getStartLine(), error_message);
		}
		else{
			genCode("\tMOV AX, " + symbol->getAsmName());
			genCode("\tCALL print_output");
			genCode("\tCALL new_line");
		}

		$$->addChildren({$1, $2, $3, $4, $5});
	} */
	| PRINTLN  LPAREN expression RPAREN SEMICOLON {
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});
		printExpression($3, true);
	}
	| PRINT LPAREN expression RPAREN SEMICOLON {
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});
		printExpression($3, false);
	}
	| RETURN expression SEMICOLON {
		printLog("statement : RETURN expression SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3});

		//------------------code generation------------------
		genCode("\tPOP AX");
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
	| RETURN SEMICOLON{
		printLog("statement : RETURN SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2});
		function_return_lines.push_back(temp_asm_line_count);
		genCode("\tJMP ");
	}
	| PRINTLN LPAREN CONST_STRING RPAREN SEMICOLON {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});

		//------------------code generation------------------
		printString($3, true);
	}
	| PRINT LPAREN CONST_STRING RPAREN SEMICOLON {
		printLog("statement : PRINTLN LPAREN RPAREN SEMICOLON");
		$$ = new SymbolInfo("statement", "non-terminal");
		$$->addChildren({$1, $2, $3, $4, $5});

		//------------------code generation------------------
		printString($3, false);
	}
	| SCANINT LPAREN variable RPAREN SEMICOLON{
		genCode("\tCALL int_intput");
		genCode("\tMOV AX, INT_");
		if($1->isArray() && !$1->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + $3->getAsmName() + ", AX");
	}
	;

P : {	
		normal_expression_to_logic($<symbolInfo>0); 
	};

expression_statement : SEMICOLON {
		printLog("expression_statement : SEMICOLON");
		$$ = new SymbolInfo("expression_statement", "non-terminal");
		$$->addChildren($1);
	}
	| expression SEMICOLON {
		printLog("expression_statement : expression SEMICOLON");
		$$ = new SymbolInfo("expression_statement", "non-terminal");
		$$->copyICGData($1);
		$$->addChildren({$1, $2});
		//------------------code generation------------------
		genCode("\tPOP AX");
	}
	;

variable : ID {
		printLog("variable : ID");
		
		auto symbol = checkValidVar($1);
		
		if(symbol) $$ = new SymbolInfo(symbol);
		else $$ = new SymbolInfo($1);
		
		$$->setName("variable");
		$$->setType("non-terminal");

		
		if(symbol) $$->setDataType(symbol->getDataType());
		else $$->setDataType("ERROR");
		$$->addChildren($1);

		// ------------------code generation------------------
		// asmName is set in copy constructor
	}
	| ID LTHIRD expression RTHIRD {
		printLog("variable : ID LTHIRD expression RTHIRD");

		$1->setArray();

		auto symbol = checkValidVar($1, true);
		if(symbol) $$ = new SymbolInfo(symbol);
		else $$ = new SymbolInfo($1);
		
		$$->setName("variable");
		$$->setType("non-terminal");

		
		if(symbol) $$->setDataType(symbol->getDataType());
		else $$->setDataType("ERROR");
		
		if($3->getDataType() != "INT"){
			// index must be integer
			std::string error_message = "Array subscript is not an integer";
			semanticError($3->getStartLine(), error_message);
		}
		
		$$->addChildren({$1, $2, $3, $4});

		// ------------------code generation------------------
		genCode("\tPOP AX");							// get the value of index from expression(stack)
		genCode("\tSHL AX, 1"); 						// multiply by 2
		genCode("\tLEA BX, " + symbol->getAsmName()); 	// get the address of array[0]
		genCode("\tSUB BX, AX"); 						// get the address of array[index]
		genCode("\tPUSH BX"); 							// push the address of array[index] to stack
		$$->setAsmName("[BX]"); 
	}
	;

N : {
		$$ = new SymbolInfo();
		$$->addToNextList(temp_asm_line_count);
		genCode("\tJMP ");
	}
	; 

M : {
		std::string label = new_label();
		$$ = new SymbolInfo();
		$$->setLabel(label);

		//------------------code generation------------------
		genCode(label + ":");
	}
	;




expression : logic_expression {
		printLog("expression : logic_expression");
		$$ = new SymbolInfo("expression", "non-terminal");
		$$->copyICGData($1);
		$$->addChildren($1);
	}
	| variable ASSIGNOP logic_expression {
		printLog("expression : variable ASSIGNOP logic_expression");
		$$ = new SymbolInfo("expression", "non-terminal");
		$$->setDataType($1->getDataType());
		if($3->getDataType() == "VOID"){
			// can't assign  void
			$$->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError($3->getStartLine(), error_message);
		}

		else if($1->getDataType() == "VOID"){
			// can't assign to  void
			$$->setDataType("VOID");
			std::string error_message = "Void cannot be used in expression ";
			semanticError($1->getStartLine(), error_message);
		}

		if($1->getDataType() == "INT" && $3->getDataType() == "FLOAT"){
			std::string error_message = "Warning: possible loss of data in assignment of FLOAT to INT";
			semanticError($1->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});

		// ------------------code generation------------------

		$$->clearNextList();
		if(!$3->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
			$$->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch($3->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch($3->getFalseList(), label);

			label = new_label();
			genCode(label + ":");
			backpatch($$->getNextList(), label);			
		}
		genCode("\tPOP AX");
		if($1->isArray() && !$1->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV " + $1->getAsmName() + ", AX");
		genCode("\tPUSH AX");
		$$->clearNextList();
	}
	;

logic_expression : rel_expression {
		printLog("logic_expression : rel_expression");
		$$ = new SymbolInfo("logic_expression", "non-terminal");
		$$->copyICGData($1);
		$$->addChildren($1);
	}
	| rel_expression LOGICOP M rel_expression {
		printLog("logic_expression : rel_expression LOGICOP rel_expression");
		$$ = new SymbolInfo("logic_expression", "non-terminal");
		$$->setDataType("INT");

		if($1->getDataType() == "VOID" || $3->getDataType() == "VOID"){
			$$->setDataType("VOID");
			// std::string error_message = "Can't do logic operations void";
			// semanticError($3->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});

		// ------------------code generation------------------
		// short circuit code and backpatching
		SymbolInfo* B = $$;
		SymbolInfo* B1 = $1;
		SymbolInfo* B2 = $4;

		// careful with the order
		normal_expression_to_logic(B2);
		normal_expression_to_logic(B1);

		if($2->getName() == "&&"){
			backpatch(B1->getTrueList(), $3->getLabel());
			B->setTrueList(B2->getTrueList());
			B->setFalseList(merge(B1->getFalseList(), B2->getFalseList()));
		}
		else if($2->getName() == "||"){
			backpatch(B1->getFalseList(), $3->getLabel());
			B->setFalseList(B2->getFalseList());
			B->setTrueList(merge(B1->getTrueList(), B2->getTrueList()));
		}
		genCode("\tPUSH AX");
	}
	;

rel_expression : simple_expression {
		printLog("rel_expression : simple_expression");
		$$ = new SymbolInfo("rel_expression", "non-terminal");
		$$->copyICGData($1);
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| simple_expression RELOP simple_expression {
		printLog("rel_expression : simple_expression RELOP simple_expression");
		$$ = new SymbolInfo("rel_expression", "non-terminal");
		$$->setDataType("INT");

		if($1->getDataType() == "VOID" || $3->getDataType() == "VOID"){
			// can't compare void
			$$->setDataType("VOID");
			// std::string error_message = "Can't compare void";
			// semanticError($3->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});

		// ------------------code generation------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		genCode("\tCMP AX, BX");

		$$->addToTrueList(temp_asm_line_count);
		$$->addToFalseList(temp_asm_line_count + 1);

		string op = $2->getName();
		if(op == "<") genCode("\tJL ");
		else if(op == ">") genCode("\tJG ");
		else if(op == "<=") genCode("\tJLE ");
		else if(op == ">=") genCode("\tJGE ");
		else if(op == "==") genCode("\tJE ");
		else if(op == "!=") genCode("\tJNE ");
		
		genCode("\tJMP ");
	}
	;

simple_expression : term {
		printLog("simple_expression : term");
		$$ = new SymbolInfo("simple_expression", "non-terminal");
		$$->copyICGData($1);
		$$->setDataType($1->getDataType());
		$$->addChildren($1);
	}
	| simple_expression ADDOP term {
		printLog("simple_expression : simple_expression ADDOP term");
		$$ = new SymbolInfo("simple_expression", "non-terminal");
		$$->setDataType(typecast($1, $3));

		if($3->getDataType() == "VOID"){
			std::string error_message = "Can't add void";
			semanticError($3->getStartLine(), error_message);
			$$->setDataType("VOID");
		}

		$$->addChildren({$1, $2, $3});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		if($2->getName() == "+") genCode("\tADD AX, BX");
		else genCode("\tSUB AX, BX");
		genCode("\tPUSH AX");
	}
	;

term : unary_expression {
		printLog("term : unary_expression");
		$$ = new SymbolInfo("term", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->addChildren($1);

		$$->copyICGData($1);
	}
	| term MULOP unary_expression {
		printLog("term : term MULOP unary_expression");
		$$ = new SymbolInfo("term", "non-terminal");
		$$->setDataType(typecast($1, $3));

		if($3->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($3->getStartLine(), error_message);
		}

		if($2->getName() == "%" && ($1->getDataType() != "INT" || $3->getDataType() != "INT")){
			// not int in modulus
			$$->setDataType("INT");
			std::string error_message = "Operands of modulus must be integers ";
			semanticError($3->getStartLine(), error_message);
		}

		else if(($2->getName() == "/" || $2->getName() == "%") && $3->getValue() == "0"){
			// division by zero
			std::string error_message = "Warning: division by zero";
			semanticError($3->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2, $3});

		// ---------------------Code generation---------------------
		genCode("\tPOP BX");
		genCode("\tPOP AX");
		//genCode("\tXOR DX, DX");
		genCode("\tCWD");
		if($2->getName() == "*") genCode("\tIMUL BX");
		else genCode("\tIDIV BX");

		if($2->getName() != "%") genCode("\tPUSH AX");
		else genCode("\tPUSH DX");

		/*	multiply A x B
			code : IMUL source
				A: source
				B: ax
				Product (ms 16 bits): dx 
				Product (ls 16 bits): ax

			division
			code : IDIV source
				Divisor: source; Dividend: dx:ax 
				Quotient: ax; Remainder: dx
		*/
		
	}
	;

unary_expression : ADDOP unary_expression {
		printLog("unary_expression : ADDOP unary_expression");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType($2->getDataType());

		if($2->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}

		$$->addChildren({$1, $2});

		// ---------------------Code generation---------------------
		if($1->getName() == "-"){
			genCode("\tPOP AX");
			genCode("\tNEG AX");
			genCode("\tPUSH AX");
		}
	}
	| NOT unary_expression {
		printLog("unary_expression : NOT unary_expression");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType("INT");

		if($2->getDataType() == "VOID"){
			// unary expression can't be void
			$$->setDataType("VOID");
			// std::string error_message = "unary expression can't be void";
			// semanticError($2->getStartLine(), error_message);
		}
		$$->addChildren({$1, $2});

		// ---------------------Code generation---------------------
		// genCode("\tPOP AX");
		// genCode("\tCMP AX, 0");

		// string label1 = "LL0";
		// string label2 = "LL1";

		// genCode("\tJNE " + label1);
		// genCode("\tPUSH 1");
		// genCode("\tJMP " + label2);
		// genCode(label1 + ":");
		// genCode("\tPUSH 0");
		// genCode(label2 + ":");

		$$->setTrueList($2->getFalseList());
		$$->setFalseList($2->getTrueList());

	}
	| factor {
		printLog("unary_expression : factor");
		$$ = new SymbolInfo("unary_expression", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->setValue($1->getValue());
		$$->addChildren($1);

		$$->copyICGData($1);
	}
	;

factor : variable {
		printLog("factor : variable");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($1->getDataType());
		$$->setArray($1->isArray());
		$$->addChildren($1);

		// ---------------------Code generation---------------------
		if($1->isArray() && !$1->isGlobalVar()) genCode("\tPOP BX");
		genCode("\tMOV AX, " + $1->getAsmName());
		genCode("\tPUSH AX");

	}
	| ID LPAREN argument_list RPAREN {
		printLog("factor : ID LPAREN argument_list RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("");

		SymbolInfo *symbol= symbolTable->lookup($1->getName());

		if(!symbol){
			std::string error_message = "Undeclared function '" + $1->getName() + "'";
			semanticError($1->getStartLine(), error_message);
			$$->setDataType("ERROR");
		}
		
		else{
			
			$$->setDataType(symbol->getDataType());
			// if not function
			if(!symbol->isFunction()){
				std::string error_message = $1->getName() + " is not a function";
				semanticError($1->getStartLine(), error_message);
			}

			// else if paramater size not equal
			else if(symbol->getParamCount() > $3->getParamCount()){
				std::string error_message = "Too few arguments to function '" + $1->getName() + "'";
				semanticError($1->getStartLine(), error_message);
			}

			else if(symbol->getParamCount() < $3->getParamCount()){
				std::string error_message = "Too many arguments to function '" + $1->getName() + "'";
				semanticError($1->getStartLine(), error_message);
			}

			// else if parameter type mismatch
			else{
				vector<SymbolInfo*> params = symbol->getParams();
				vector<SymbolInfo*> args = $3->getParams();

				for(int i=0; i<params.size(); i++){

					if(params[i]->getDataType() != args[i]->getDataType()){
						
						// typecast?
						if(!(params[i]->getDataType() == "INT" || params[i]->getDataType() == "FLOAT") && (args[i]->getDataType() == "INT" || args[i]->getDataType() == "FLOAT"))
						{
							std::string error_message = "Parameter type mismatch ( For " + std::to_string(i+1) +"th parameter ) in function " + symbol->getName() + " at line " + std::to_string(symbol->getStartLine());
							semanticError($1->getStartLine(), error_message);
						}
					}
				}
			} 
		}

		if($3->getChildrenSize() == 0) $$->addChildren({$1, $2, $4});
		else $$->addChildren({$1, $2, $3, $4});


		// ---------------------Code generation---------------------
		genCode("\tCALL " + $1->getName());
		if($$->getDataType() != "VOID") genCode("\tPUSH AX");
		else genCode("\tPUSH 0");
	}
	| LPAREN expression RPAREN {
		printLog("factor : LPAREN expression RPAREN");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType($2->getDataType());
		$$->addChildren({$1, $2, $3});

		// ---------------------Code generation---------------------
		$$->setTrueList($2->getTrueList());
		$$->setFalseList($2->getFalseList());
	}
	| CONST_INT {
		printLog("factor : CONST_INT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("INT");
		$$->setValue($1->getName());
		$$->addChildren($1);

		// ---------------------Code generation---------------------
		// genCode("\tMOV AX, " + $1->getName());
		// genCode("\tPUSH AX");
		genCode("\tPUSH " + $1->getName());
	}
	| CONST_FLOAT {
		printLog("factor : CONST_FLOAT");
		$$ = new SymbolInfo("factor", "non-terminal");
		$$->setDataType("FLOAT");
		$$->setValue($1->getName());
		$$->addChildren($1);
	}
	| variable INCOP {
		printLog("factor: variable INCOP");
		$$ = new SymbolInfo("factor", "non-terminal");

		if($1->isArray()){
			// array can't be incremented
			std::string error_message = "Array can't be incremented";
			semanticError($1->getStartLine(), error_message);
		}

		$$->setDataType($1->getDataType());
		$$->addChildren({$1, $2});

		// ---------------------Code generation---------------------
		genINC_DEC($1, "++");
	}
	| variable DECOP {
		printLog("factor: variable DECOP");
		
		$$ = new SymbolInfo("factor", "non-terminal");

		if($1->isArray()){
			// array can't be decremented
			std::string error_message = "Array can't be decremented";
			semanticError($1->getStartLine(), error_message);
		}

		$$->setDataType($1->getDataType());
		$$->addChildren({$1,$2});

		// ---------------------Code generation---------------------
		genINC_DEC($1, "--");
	}
	;

argument_list : arguments {
		printLog("argument_list : arguments");
		$$ = new SymbolInfo("argument_list", "non-terminal");
		$$->setParams($1->getParams());
		$$->addChildren($1);
	}
	| {
		printLog("argument_list : ");
		$$ = new SymbolInfo("argument_list", "non-terminal");
	}
	;

arguments : arguments COMMA logic_expression {
		printLog("arguments : arguments COMMA logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
		$$->setParams($1->getParams());
		$$->addParam($3);					 
		$$->addChildren({$1, $2, $3});
	}
	| logic_expression {
		printLog("arguments : logic_expression");
		$$ = new SymbolInfo("arguments", "non-terminal");
		$$->addParam($1);
		$$->addChildren($1);
	}
	;

%%
extern "C" {
int main()
{
	printf("starting compilation\n");


	init_count();

	
	FILE* fp;
	fp=fopen("files/input.c","r");

	yyin=fp;
	errorOut.open("files/error.txt");
	logout.open("files/log.txt");
	parseTreeOut.open("files/parseTree.txt");
	
	
	asmInit();
	
	yyparse();
	yylex_destroy();

	generate_asm_file();
	generate_Optimize_Code();
	closeAsmFiles();
	
	errorOut.close();
	logout.close();
	parseTreeOut.close();

	fclose(fp);
	

	return 0;
}
}

