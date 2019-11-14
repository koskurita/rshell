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
#include "UserInput.hpp"

using namespace std;

class Symbol: public UserInput {

    private:

        const char* symbol;

        int ID = 100;

        int passOrFail = -1;

    public:

        virtual bool PerformNext(UserInput* one, UserInput* two);

        Symbol(const char* s);

        virtual UserInput* ParseUserInput(std::string cheese);

        void doInput();

        void SetPassOrFail(int oneOrZero);

        int ReturnPassOrFail();

};

