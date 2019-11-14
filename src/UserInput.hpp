#ifndef __USERINPUT_HPP__

#define __USERINPUT_HPP__



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

using namespace std;


class UserInput{

    private:

        int ID = 0;

        int passOrFail = -1;

    public:


        virtual UserInput* ParseUserInput(string cheese) = 0;

        virtual void doInput() = 0;

        virtual void SetPassOrFail(int oneOrZero) = 0;

        virtual bool PerformNext(UserInput* one, UserInput* two) = 0;

        int returnID();

        int returnPassOrFail();

};



#endif /*__USERINPUT_H__*/
