#include <iostream>
#include "Symbol.hpp"


  virtual Symbol::bool PerformNext(UserInput* one, UserInput* two){
    two->SetPassOrFail(1);
    return true;
    }

    Symbol::Symbol(const char* s){//default constructor
            symbol = s;
            ID = 100;
        }

    void Symbol::ParseUserInput(std::string cheese){//dont use this
        std::cout<< "Symbols dont call ParseUserInput"; return;
    }

    void Symbol::SetPassOrFail(int oneOrZero){//dont use this
    std::cout<< "Symbols dont call oneOrZero";
    }

    int Symbol::ReturnPassOrFail(){//dont use this
        std::cout<< "Symbols dont call ReturnPassOrFail"; return 0;
    }
