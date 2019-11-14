#pragma once



#include <iostream>

#include <sstream>

#include <fstream>

#include <queue>

#include <string>

#include <vector>

#include <cstdlib>

#include <stdlib.h>

#include  <sys/types.h>

#include <stdio.h>

#include <sys/wait.h>

#include <unistd.h>
#include "Symbol.hpp" 


class SemiColon: public Symbol{

    private:

    const char* s;

    int ID;

    int passOrFail = -1;

    

    public:

        SemiColon(const char* s);

        bool PerformNext(UserInput * one, UserInput * two);

};




