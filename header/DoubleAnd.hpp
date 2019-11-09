#ifndef __DOUBLEAND_H__
#define __DOUBLEAND_H__

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

class DoubleAnd:public Symbol{
    private:
        const char* symbol;
        int ID;
        int passOrFail = -1;
    public:
        DoubleAnd(const char * s):Symbol(s);
        bool PerformNext(UserInput * one, UserInput * two);
};

#endif /*__DOUBLEAND_H__*/
