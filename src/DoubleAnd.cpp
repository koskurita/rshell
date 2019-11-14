#pragma once
#include <iostream>
#include "DoubleAnd.hpp"

    DoubleAnd::DoubleAnd(const char * s):Symbol(s){//default constructor
        ID = 103;
    }

    bool DoubleAnd::PerformNext(UserInput * one, UserInput * two){
        if (one->returnPassOrFail() == 1){
            //do nothing
            return true;
        }
        else{
            two->SetPassOrFail(0);
            return false;
        }
    }



