#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <iostream>
#include <string>
#include <vector>



class SymbolInfo
{
    std::string name;
    std::string type;
    std::string dataType;
    SymbolInfo *next;
    std::string value;

    // for parse tree
    bool isTerminal = true;
    int startLine = 0;
    int endLine = 0;
    std::vector<SymbolInfo *> children;

    // array
    bool isSymbolArray = false;
    int arraySize = 0;

    // for function
    bool funcDeclared = false;
    bool funcDefined = false;
    int definedLine = 0;
    std::vector<SymbolInfo *> params;

    // ICG
    int stackOffset = 0;
    bool isGlobal = false;
    std::string asmName = "";
    std::string label = "";
    std::vector<int> trueList;
    std::vector<int> falseList;
    std::vector<int> nextList;

public:

    // ====================== Constructors ======================
    SymbolInfo() {}

    SymbolInfo(std::string name, std::string type, int startLine = 0, int endLine = 0, SymbolInfo *next = nullptr)
    {
        this->name = name;
        this->type = type;
        this->startLine = startLine;
        this->endLine = endLine;
        this->next = next;
    }

    SymbolInfo(std::string name, std::string type, std::string dataType, int startLine = 0, int endLine = 0, SymbolInfo *next = nullptr)
    {
        this->name = name;
        this->type = type;
        this->startLine = startLine;
        this->endLine = endLine;
        this->next = next;
        this->dataType = dataType;
    }

    SymbolInfo(SymbolInfo *symbolInfo){
        this->name = symbolInfo->name;
        this->type = symbolInfo->type;
        this->next = symbolInfo->next;
        this->dataType = symbolInfo->dataType;
        this->value = symbolInfo->value;

        this->startLine = symbolInfo->startLine;
        this->endLine = symbolInfo->endLine;
        this->isTerminal = symbolInfo->isTerminal;
        this->children = symbolInfo->children;

        this->funcDeclared = symbolInfo->funcDeclared;
        this->funcDefined = symbolInfo->funcDefined;
        this->params = symbolInfo->params;
        this->definedLine = symbolInfo->definedLine;

        this->isSymbolArray = symbolInfo->isSymbolArray;
        this->arraySize = symbolInfo->arraySize;

        this->stackOffset = symbolInfo->stackOffset;
        this->isGlobal = symbolInfo->isGlobal;
        this->asmName = symbolInfo->asmName;
        this->label = symbolInfo->label;
        this->trueList = symbolInfo->trueList;
        this->falseList = symbolInfo->falseList;
        this->nextList = symbolInfo->nextList;
    }

    void copyICGData(SymbolInfo *symbolInfo){
        this->stackOffset = symbolInfo->stackOffset;
        this->isGlobal = symbolInfo->isGlobal;
        this->asmName = symbolInfo->asmName;
        this->label = symbolInfo->label;
        this->trueList = symbolInfo->trueList;
        this->falseList = symbolInfo->falseList;
        this->nextList = symbolInfo->nextList;
    }

    // ====================== Setters and Getters ======================
    void setName(std::string name) { this->name = name; }
    void setType(std::string type) { this->type = type; }
    void setNext(SymbolInfo *next) { this->next = next; }
    void setStartLine(int startLine) { this->startLine = startLine; }
    void setEndLine(int endLine) { this->endLine = endLine; }
    void setDataType(std::string dataType) { this->dataType = dataType; }
    void setValue(std::string value) { this->value = value; }
    
    std::string getName() { return name; }
    std::string getType() { return type; }
    SymbolInfo *getNext() { return next; }
    int getStartLine() { return startLine; }
    int getEndLine() { return endLine; }
    std::string getDataType() { return dataType; }
    std::string getValue() { return value; }
    
    

    // ====================== For Array ======================
    void setArray(bool isSymbolArray = true, int arraySize = 0)
    {
        this->isSymbolArray = isSymbolArray;
        this->arraySize = arraySize;
    }
    void setArraySize(int arraySize) { this->arraySize = arraySize; }
    bool isArray() { return isSymbolArray; }
    int getArraySize() { return arraySize; }
    


    // ====================== For Function ======================
    void setFuncDeclared() { this->funcDeclared = true; }
    void setFuncDefined(int definedLine = 0 ) {
        this->funcDefined = true; this->funcDeclared = true;
        if(definedLine != 0) this->definedLine = definedLine;
    }
    bool isFunction() { return funcDeclared; }
    bool isFuncDeclared() { return funcDeclared; }
    bool isFuncDefined() { return funcDefined; }
    void addParam(SymbolInfo *param) { params.push_back(param); }
    void addParams(const std::vector<SymbolInfo *> &params) { this->params.insert(this->params.end(), params.begin(), params.end()); }
    void setParams(const std::vector<SymbolInfo *> &params) { this->params = params; }
    std::vector<SymbolInfo *> getParams() { return params; }
    int getParamCount() { return params.size(); }
    void setDefinedLine(int definedLine) { this->definedLine = definedLine; }
    int getDefinedLine() { return definedLine; }
    

    // ====================== For Parse Tree ======================
    std::vector<SymbolInfo *> getChildren() { return children; }

    int getChildrenSize() { return children.size(); }

    void addChildren(SymbolInfo *child) { 
        children.push_back(child); 
        startLine = child->startLine;
        endLine = child->endLine;
        if (children.size() > 0) isTerminal = false;
    }
    
    void addChildren(const std::vector<SymbolInfo *> &children){
        this->children.insert(this->children.end(), children.begin(), children.end());
        startLine = children[0]->startLine;
        endLine = children[children.size() - 1]->endLine;
        if (children.size() > 0) isTerminal = false;
    }

    void printParseGrammarRule(std::ostream &out){

        if(isTerminal){
            out<<type<<" : "<<name<<"\t"<<"<Line: "<<startLine<<">"<<std::endl;
            return;
        }

        out<<name<<" : ";
        for(auto child : children) {
            if(child->isTerminal) out<<child->type<<" ";
            else out<<child->name<<" ";
        }
        out<<"\t"<<"<Line: "<<startLine<<"-"<<endLine<<">"<<std::endl;
    }

    // ====================== ICG ======================
    void setStackOffset(int stackOffset) { this->stackOffset = stackOffset; }
    int getStackOffset() { return stackOffset; }
    void setGlobal(bool isGlobal = true) { this->isGlobal = isGlobal; }
    bool isGlobalVar() { return isGlobal; }
    void setAsmName(std::string asmName) { this->asmName = asmName; }
    std::string getAsmName() { return asmName; }
    void setLabel(std::string label) { this->label = label; }
    std::string getLabel() { return label; }
    void setTrueList(std::vector<int> trueList) { this->trueList = trueList; }
    void setFalseList(std::vector<int> falseList) { this->falseList = falseList; }
    std::vector<int> getTrueList() { return trueList; }
    std::vector<int> getFalseList() { return falseList; }
    void addToTrueList(int index) { trueList.push_back(index); }
    void addToFalseList(int index) { falseList.push_back(index); }
    void setNextList(std::vector<int> nextList) { this->nextList = nextList; }
    std::vector<int> getNextList() { return nextList; }
    void addToNextList(int index) { nextList.push_back(index); }
    void clearNextList() { nextList.clear(); }



    // ====================== Overloaded Operators ======================
    friend std::ostream &operator<<(std::ostream &out, SymbolInfo &symbolInfo)
    {
        if (symbolInfo.isArray()) out << "<" << symbolInfo.name << ", ARRAY, " << symbolInfo.dataType << ">";
        else if(symbolInfo.isFunction()) out << "<" << symbolInfo.name << ", FUNCTION, " << symbolInfo.dataType << ">";
        else out << "<" << symbolInfo.name << ", " << symbolInfo.dataType << ">";
        return out;
    }
};

#endif