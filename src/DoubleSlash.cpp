#pragma once
#include <iostream>
#include "DoubleSlash.hpp"

    DoubleSlash::DoubleSlash(const char * s):Symbol(s){//default constructor
        ID = 102;
    }

    bool DoubleSlash::PerformNext(UserInput * one, UserInput * two){
        if (one->returnPassOrFail() == 1){
            two->SetPassOrFail(0);
            return false;
        }
        else{
            //do nothing
            return true;
        }
    }
