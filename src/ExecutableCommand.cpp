#pragma once
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
         this->SetPassOrFail(oneOrZero);
     }
     
    int ReturnPassOrFail(){
        return ReturnPassOrFail();
    } //Returns pass or fail integer*/

    
    ////DO NOT CALL THESE
    UserInput* ExecutableCommand::ParseUserInput(std::string cheese){//do not call
        std::cout << "Error, do not call parseUserINput in executablecommand";
    }


    bool ExecutableCommand::PerformNext(UserInput * one, UserInput * two){
        std::cout << "Error. do not call performNext in executablecommand.";
        return false;
    }
    ////

    void ExecutableCommand::doInput(){//this is now neccessary
        pid_t child;
        child = fork();//create child fork       
        if (child < 0){//if child < 0 then there was a failure to fork
        std::cout << "Massive error, fork failed." << endl;
        }
        else if (this->passOrFail == 0){ //This is all be to check if This executable has already "failed" due to a '&&' or '||'
		if(child == 0) {
		exit(1);//this ends child
		}
        }
	else if (this->command[0] == "exit" || this ->command[0] == "Exit"){//this exits both child and parent if command[0] = exit
	std::cout << "\n now exiting program \n";
	exit(1);
	}
        else if (child == 0) {//aka we are in child
        	if(execvp(command[0], command) < 0){  //this will be (*InputVector[i-1]->words, InputVector[i-1]->words)
        	cout << endl << "failed to execute " << command[0] << endl; //we may want to delete this later
        	this->passOrFail = 0;      //signals that user input failed. 
		exit(1);
        	}
        	else{
        	this->passOrFail = 1;      
        	exit(1);
		}
        }
	else if(child > 0){ //aka we are in parent
	waitpid(-1,&child,0);
	}
    }
    
