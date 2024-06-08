#ifndef ICG_HELPER_H
#define ICG_HELPER_H

#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include<stack>
#include"1905066_parser_helper.h"
#include"symbol-table/1905066_symbolTable.h"
#include"symbol-table/1905066_symbolInfo.h"
#include "1905066_optimization_helper.h"

using namespace std;

#define temp_file_name "files/temp.txt"
#define code_file_name "files/code.asm"
#define optimized_code_file_name "files/optimized_code.asm"

std::ofstream codeOut;
std::ofstream tempOut;
std::ofstream optimzedCodeOut;

int label_count = 0;
int stack_offset = 0;
bool inGlobalScope = true;
extern int temp_asm_line_count = 1;
unordered_map<int, string> label_map;
vector<int> function_return_lines;


void init_count(){
    line_count = 1;
    temp_asm_line_count = 1;
    error_count = 0;
	temp_line_count=0;
}



inline string new_label()
{
    return "L" + to_string(label_count++);
}

inline void backpatch(vector<int> list, string label)
{
    for(auto line : list) label_map[line] = label;
}

std::vector<int> merge(const std::vector<int> &list1, const std::vector<int> &list2)
{
    std::set<int> s(list1.begin(), list1.end());
    s.insert(list2.begin(), list2.end());
    std::vector<int> mergedList(s.begin(), s.end());
    return mergedList;
}


void genCode(string code){
    tempOut << code << endl;
    temp_asm_line_count++;
}

void genComment(string comment){
    tempOut << "; " << comment << endl;
    temp_asm_line_count++;
}

void genVarDeclarationCode(){
    if(!inGlobalScope){
        for(auto var : vars){
            var->setStackOffset(stack_offset+2);
            string asmName = "[BP-" + to_string(stack_offset+2) + "]";
            var->setAsmName(asmName);
            int size = max(var->getArraySize(),1) * 2;
            stack_offset += size;
            genCode("\tSUB SP, " + to_string(size));

        }
    }

    else{
        for(auto var : vars){
            var->setAsmName(var->getName());
            codeOut <<"\t" << var->getName() << " DW " << max(1,var->getArraySize()) << " DUP (0000H)" << endl; 
        }
    }
}

void genINC_DEC(SymbolInfo* var, string op){
    op = op == "++" ? "INC" : "DEC";
    if(var->isArray() && !var->isGlobalVar()) genCode("\tPOP BX");
    genCode("\tMOV AX, " + var->getAsmName());
    genCode("\tPUSH AX");
    genCode("\t" + op + " AX");
    genCode("\tMOV " + var->getAsmName() + ", AX" );
}

void genFunctioninitCode(string func_name){
    
    genCode( func_name + " PROC");
    if(func_name == "main"){
        genCode("\tMOV AX, @DATA");
        genCode("\tMOV DS, AX");
    }
    genCode("\tPUSH BP");
    genCode("\tMOV BP, SP");
}

void genFunctionEndingCode(SymbolInfo* func){
    std::string label = new_label();
    genCode(label + ":");
    backpatch(function_return_lines, label);
    function_return_lines.clear();
    genCode("\tADD SP, " + to_string(stack_offset));
    genCode("\tPOP BP");

    if(func->getName() == "main"){
        genCode("\tMOV AX, 4CH");
        genCode("\tINT 21H");
    }

    else{
        
        if(func->getParamCount() != 0) genCode("\tRET " + to_string(func->getParamCount()*2));
        else genCode("\tRET");
    }
    genCode(func->getName() + " ENDP");

    inGlobalScope = true;
    stack_offset = 0;
}

void asmInit(){
    tempOut.open(temp_file_name);
    codeOut.open(code_file_name);

    codeOut << ";-------" << endl;
    codeOut << ";   " << endl;
    codeOut << ";-------" << endl;
    codeOut << ".MODEL SMALL" << endl;
    codeOut << ".STACK 1000H" << endl;
    codeOut << ".Data" << endl;
    codeOut << "\tCR EQU 0DH" << endl;
    codeOut << "\tLF EQU 0AH" << endl;
    codeOut << "\tnumber DB \"00000$\"" << endl;
    codeOut << "\tSTRING DB 100 DUP(?)" << endl;
    codeOut << "\tINT_ DW 0"<< endl;
}

void add_println_instructions(std::ostream &out = std::cout)
{
    ifstream file("println_instructions.txt");
    string line;
    while(getline(file, line)) out << line << endl;
    file.close();   
}

void closeAsmFiles(){
    if(tempOut.is_open()) tempOut.close();
    if(codeOut.is_open()) codeOut.close();
    if(optimzedCodeOut.is_open()) optimzedCodeOut.close();
}

void generate_asm_file(){
    codeOut<<".CODE"<<std::endl;
    tempOut.close();
    ifstream tempFile(temp_file_name);
    string line;
    int temp_asm_line_count = 1;
    while(getline(tempFile, line)) {
        codeOut << line << label_map[temp_asm_line_count] << endl;
        temp_asm_line_count++;
    }
    add_println_instructions(codeOut);
    codeOut<<"END main"<<std::endl;
    tempFile.close();
    codeOut.close();
}

void normal_expression_to_logic(SymbolInfo* B, bool pop_ax = true){
    if(B->getTrueList().empty()){
		if(pop_ax) genCode("\tPOP AX");
		genCode("\tCMP AX, 0");

		B->addToTrueList(temp_asm_line_count);
		B->addToFalseList(temp_asm_line_count + 1);
		genCode("\tJNE ");
		genCode("\tJMP ");
	}
}

 
void generate_Optimize_Code(){
    remove_unnecessary_push_pop(code_file_name, temp_file_name);
    remove_unnecessary_jumps(temp_file_name, optimized_code_file_name);
}

void printExpression(SymbolInfo* expression, bool newLine = false){
    if(!expression->getTrueList().empty()){
			std::string label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 1");
            bool next_dest = temp_asm_line_count;
			//$$->addToNextList(temp_asm_line_count);
			genCode("\tJMP ");
			backpatch(expression->getTrueList(), label);

			label = new_label();
			genCode(label + ":");
			genCode("\tPUSH 0");
			backpatch(expression->getFalseList(), label);

			label = new_label();
			genCode(label + ":");
			backpatch({next_dest}, label);
			//$$->setNextList({});		
		}

		genCode("\tPOP AX");
		genCode("\tCALL print_output");
		if(newLine) genCode("\tCALL new_line");
}


void printString(string str){
    if(str.length() == 0) return;
    genCode("\tLEA SI, STRING");
	for(int i = 0, j = i; i < str.length(); i++, j++) {
		genCode("\tMOV [SI+" + to_string(i) + "], '" + str[j] + "'");
	}
	genCode("\tMOV [SI+" + to_string(str.length()) + "], '$'");
	genCode("\tLEA DX, STRING");
	genCode("\tMOV AH, 09H");
	genCode("\tINT 21H");
}

void printString(SymbolInfo* symbol, bool newLine = false){
    string temp = "";
	std::string str = symbol->getName(); 
	for(int i = 0; i < str.length(); i++) {
        if(str[i] == '\n') {
            printString(temp);
            genCode("\tCALL new_line");
            temp = "";
        }
        else{
            temp += str[i];
        }
	}
    if(temp.length() != 0) printString(temp);
	if(newLine) genCode("\tCALL new_line");
}

#endif