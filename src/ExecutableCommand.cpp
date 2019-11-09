#include <iostream>
#include "ExecutableCommand.hpp"

    ExecutableCommand::ExecutableCommand(const char* words[50]){ // constructor
        ID = 1;
        int iterInt = 0;
        while(words[iterInt] != NULL){
            command[iterInt] = strdup(words[iterInt]);
            iterInt++;
        }
        command[iterInt + 1] = NULL;
    }

    ExecutableCommand::~ExecutableCommand(){
        int iterInt = 0;
        while(command[iterInt] != NULL){
            free(command[iterInt]);
            iterInt++;
        }
    }
  
   
    void ExecutableCommand::SetPassOrFail(int oneOrZero){
         this->passOrFail = oneOrZero;
     }
     
    int ReturnPassOrFail(){
        return this->passOrFail;
    } //Returns pass or fail integer*/

    
    ////DO NOT CALL THESE
    void ExecutableCommand::ParseUserInput(std::string cheese){//do not call
        std::cout << "Error, do not call parseUserINput in executablecommand";
    }


    bool ExecutableCommand::PerformNext(UserInput * one, UserInput * two){
        std::cout << "Error. do not call performNext in executablecommand.";
        return false;
    }
    ////

    void ExecutableCommand::doInput(){//this is now neccessary
        pid_t child;
        child = fork();
        if (child < 0){
            std::cout << "Massive error, fork failed." << endl;
        }
        else if (this->passOrFail == 0){ //This is all be to check if This executable has already "failed" due to a '&&' or '||'
       
        }
        else if (child == 0) {
            if(execvp(command[0], command) < 0){  //this will be (*InputVector[i-1]->words, InputVector[i-1]->words)
                cout << "failed to exe,delete this mssg later."; //delete this msg later
                this->passOrFail = 0;      //signals that user input failed. Will be InputVector[i-1]->PassOrFail = 0;
            }
        }
        else{
            this->passOrFail = 1;      //Will be InputVector[i-1]->PassOrFail = 1;
            waitpid(-1,&child,0);
        }

    }
    
