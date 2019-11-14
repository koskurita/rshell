#pragma once
#include <iostream>
#include "Symbol.hpp"

using namespace std;

    Symbol::Symbol(const char* s){//default constructor
            symbol = s;
            ID = 100;
        }

    UserInput* Symbol::ParseUserInput(std::string cheese){//dont use this
        std::cout<< "Symbols dont call ParseUserInput"; return NULL;
    }

    void Symbol::SetPassOrFail(int oneOrZero){//dont use this
    std::cout<< "Symbols dont call oneOrZero";
    }

    int Symbol::ReturnPassOrFail(){//dont use this
        std::cout<< "Symbols dont call ReturnPassOrFail"; return 0;
    }
