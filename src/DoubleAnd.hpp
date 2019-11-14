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


class DoubleAnd:public Symbol{

    private:

        const char* symbol;

        int ID;

        int passOrFail = -1;

    public:

        DoubleAnd(const char * s);

        bool PerformNext(UserInput * one, UserInput * two);

};



/*__DOUBLEAND_H__*/
