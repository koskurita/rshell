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

class UserInput{
    private:
        int ID = 0;
        int passOrFail = -1;
    public:
        int ReadID();
        virtual UserInput* ParseUserInput(string cheese);
        virtual void doInput();
        virtual void SetPassOrFail(int oneOrZero);
        virtual bool PerformNext(UserInput* one, UserInput* two);
        int returnID();
        int returnPassOrFail();
};

#endif /*__USERINPUT_H__*/
