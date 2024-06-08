#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include<iostream>
#include "1905066_scopeTable.h"


class SymbolTable{

    ScopeTable* current_scope;
    int bucketSize;
    int scope_id = 0;
    std::ostream &out;

public:

    // constructor
    SymbolTable(int bucketSize, std::ostream &out = std::cout): out(out){
        this->current_scope = nullptr;
        this->bucketSize = bucketSize;
        enterScope();
    }

    // create and enter a new scope
    void enterScope(){
        current_scope = new ScopeTable(bucketSize, ++scope_id, current_scope);
        // out<<"\tScopeTable# " << current_scope->getId() << " created"<<std::endl;
    }

    // delete the current scope
    void exitScope(){
        // root scope cannot be deleted
        if(current_scope == nullptr || current_scope->getParentScope() == nullptr){
            // out<<"\tScopeTable# " << current_scope->getId() << " cannot be removed"<<std::endl;
            return;
        }

        auto temp = current_scope;
        current_scope = current_scope->getParentScope();
        int id = temp->getId();
        delete temp;
        // out<<"\tScopeTable# " << id << " removed"<<std::endl;
    }

    // insert a symbol in the current scope
    bool insert(std::string name, std::string type){
        if(current_scope == nullptr) enterScope();

        bool success = current_scope->insert(name, type, out);
        //if(!success) out<< "\t"<<name<<" already exisits in the current ScopeTable"<<std::endl; 
        return success;
    }

    bool insert(SymbolInfo* symbol){
        if(current_scope == nullptr) enterScope();

        bool success = current_scope->insert(symbol, out);
        //if(!success) out<< "\t"<<symbol->getName()<<" already exisits in the current ScopeTable"<<std::endl; 
        return success;
    }

    // look up a symbol in the current scope and all the parent scopes
    SymbolInfo* lookup(std::string name){
        if(current_scope == nullptr) return nullptr;
        
        ScopeTable* curr = current_scope;
        SymbolInfo* symbol = nullptr;

        while(curr != nullptr){
            symbol = curr->lookup(name, true, out);
            if(symbol != nullptr)
                return symbol;
            curr = curr->getParentScope();
        }
        //out << "\t'" << name << "'" << " not found in any of the ScopeTables" << std::endl;
        return nullptr;
    }

    // delete a symbol from the current scope
    bool remove(std::string name){
        if(current_scope == nullptr) return false;

        bool deleted = current_scope->deleteSymbol(name, true, out);
        if(!deleted) out<<"\tNot found in the current ScopeTable"<<std::endl;
        return deleted;
    }

    // print the current scope
    void printCurrentScopeTable(){
        if(current_scope == nullptr) return;
        current_scope->print(out);
    }

    // print all the scopes
    void printAllScopeTable(){
        ScopeTable* curr = current_scope;
        while(curr != nullptr){
            curr->print(out);
            curr = curr->getParentScope();
        }
    }

    int getCurrentScopeId(){
        if(current_scope == nullptr) return -1;
        return current_scope->getId();
    }

    // destructor
    ~SymbolTable(){
        auto curr = current_scope;
        while(curr != nullptr){
            auto temp = curr;
            curr = curr->getParentScope();
            int id = temp->getId();
            delete temp;
            // out << "\tScopeTable# " << id << " removed" << std::endl;
        }
    }


};

#endif