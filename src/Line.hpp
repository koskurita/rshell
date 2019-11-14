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
#include <string.h>
#include <unistd.h>
#include "UserInput.hpp"
#include "ExecutableCommand.hpp"
#include "SemiColon.hpp"
#include "DoubleAnd.hpp"
#include "DoubleSlash.hpp"




using namespace std;

class Line: public UserInput {

    private:

        int ID = 2;

    vector<UserInput*> Inputs;

    int passOrFail = -1;

    public:
	Line();
	~Line();

    void SetPassOrFail(int oneOrZero);

    int ReturnPassOrFail();

    bool PerformNext(UserInput *one, UserInput*two);

    UserInput* ParseUserInput(std::string cheese);

    void doInput();

};




