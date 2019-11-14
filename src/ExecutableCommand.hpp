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
#include <string.h>
#include "UserInput.hpp"


class ExecutableCommand: public UserInput { // USE CONST CHAR

    private:

        char* command[50];  //remove const

        int passOrFail = -1;

        int ID = 1;

    public:

        void SetPassOrFail(int oneOrZero);

        int ReturnPassOrFail(); //Returns pass or fail integer*/

        ExecutableCommand(const char* words[50]);

        ~ExecutableCommand();

        UserInput* ParseUserInput(std::string cheese);

        bool PerformNext(UserInput * one, UserInput * two);

        void doInput();

};



