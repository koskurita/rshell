#ifndef __DOUBLESLASH_HPP__

#define __DOUBLESLASH_HPP__



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
#include "Symbol.cpp"




class DoubleSlash:public Symbol{

    private:

    const char* s;

    int ID;

    int passOrFail = -1;

    public:

        DoubleSlash(const char * s);

        bool PerformNext(UserInput * one, UserInput * two);

};





#endif /*__DOUBLESLASH_H__*/
