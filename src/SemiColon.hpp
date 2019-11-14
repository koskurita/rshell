fndef __SEMICOLON_H__

#define __SEMICOLON_H__



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



class SemiColon: public Symbol{

    private:

    const char* s;

    int ID;

    int passOrFail = -1;

    

    public:

        SemiColon(const char* s):Symbol(s);

        bool PerformNext(UserInput * one, UserInput * two);

};



#endif /*__SEMICOLON_H__*/
