#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h> 

using namespace std;

class UserInput{
    private:
/*        int ID = 0;*/
    	  int passOrFail = -1;
    public:
/*        int ReadID(){return ID;}
        virtual int ParseUserInput();
        virtual void doInput();
        virtual void SetPassOrFail(int oneOrZero);
        virtual int ReturnPassOrFail();
        virtual bool PerformNext(UserInput* one, UserInput* two);  */      
};

class Line: public UserInput {
    protected:
    private:
/*        int ID = 2;*/

    public:
        int ParseUserInput();
        vector<UserInput*> Inputs;
        void doInput()
	
	UserInput * ptr = Inputs[0];
	int currInput = 0;
	int iterInt = 0;
	char * tempCharContainer[50];
	while(ptr->ID < 100){
	
	if(currInput < Inputs.size())
	{currInput++;}
	else   //This is just incase we reach the end of our vector
	{return;}
	ptr = Inputs[currInput];
	}
	
	//here we have to get the const char* from executable command and put it into our tempcharContainer
	while(iterInt < 50){
	if(/*some condition that shows that we are at end of command array is != true*/)
	tempCharContainer[iterInt] = strdup(command[iterInt]);
	else{
	tempCharContainer[iterInt] = NULL;
	iterInt = 50;
	}
	iterInt++;
	
	}
	
	
	
	pid_t child;
	child = fork();
	if (child < 0){
	std::cout << "Massive error, fork failed." << endl;
	}
	//else if (InputVector[i]->PassOrFail == 0){ //This is all be to check if This executable has already "failed" due to a '&&' or '||'
	////   //does nothing if passorfial ==0
	//}
	else if (child == 0) {
	if(execvp(tempCharContainer[0], tempCharContainer) < 0){  //this will be (*InputVector[i-1]->words, InputVector[i-1]->words)
	cout << "failed to exe,delete this mssg later."; //delete this msg later
	PassOrFail = 0;      //signals that user input failed. Will be InputVector[i-1]->PassOrFail = 0;
	}
	}
	else{
	PassOrFail = 1;      //Will be InputVector[i-1]->PassOrFail = 1;
	cout<< PassOrFail;
	waitpid(-1,&child,0);
	
	}
	
	iterInt = 0;
	while(iterInt < 50){
        if(tempCharContainer[iterInt] != NULL)
        free(tempCharContainer[iterInt]);
        else{
        iterInt = 50;
        }
        iterInt++;

        }
	return 1;
	
};

class ExecutableCommand: public UserInput { // USE CONST CHAR
    private:
        const char** command;
/*        int passOrFail = -1;
        int ID = 1;*/
    public:
/*        void SetPassOrFail(int oneOrZero); // this function sets pass or fail to one or zero
        int ReturnPassOrFail(){return this->passOrFail}; //Returns pass or fail integer*/
        ExecutableCommand(const char* words[50]){ // constructor
            command = words;
        }
};

class Symbol: public UserInput {
    private:
        const char* symbol;
/*        int ID = 100;*/
	int passOrFail = -1;
    public:

        bool virtual PerformNext(UserInput* one, UserInput* two){
	two->passOrFail = 1;
	}
        Symbol(const char* s){
            symbol = s;
        }
	int ParseUserInput(){{//dont use this
        std::cout<< "Symbols dont call ParseUserInput"; return 0;}
}
        void doInput(){{//dont use this
        std::cout<< "Symbols dont call doInput";}
}
        void SetPassOrFail(int oneOrZero);{//dont use this
        std::cout<< "Symbols dont call oneOrZero";}

        int ReturnPassOrFail(){//dont use this
	std::cout<< "Symbols dont call ReturnPassOrFail"; return 0;}
        
};
class DoubleAnd:public Symbol{
bool PerformNext(UserInput * one, UserInput * two){
if (one->PassOrFail == 1){
//do nothing
}
else 
two->setPassOrFail(0);
}
};
class DoubleSlash:public Symbol{
bool PerformNext(UserInput * one, UserInput * two){
if (one->PassOrFail == 1){
two->setPassOrFail(0);
}
else
//do nothing
}



};
class SemiColon: public Symbol{
bool PerformNext(UserInput * one, UserInput * two){
if (one->PassOrFail == 1){
//do nothing
}
else
//do nothing
}


};


void ParseUserInput(string cheese){
    
    string s = "";
    vector<string> temp_vector;
    
    for(unsigned int i = 0; i < cheese.size(); i++){
        if(cheese[i] == ' '){
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
        }
        else if(cheese[i] == '&'){
            s = cheese[i];
            i++;
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(cheese[i] == '|'){
            s = cheese[i];
            i++;
            s += cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(cheese[i] == ';'){
            s = cheese[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else{
        s+= cheese[i];
        }
    }
    temp_vector.push_back(s);
    
    
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        std::cout << temp_vector[i] << std::endl;
    }
    

    vector<const char*> ggs;
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        const char* charArray = temp_vector[i].c_str();
        ggs.push_back(charArray);
    }
    
    for(unsigned int i = 0; i < ggs.size(); i++){
        cout << ggs[i] << endl;
    }
    
    const char* doubleAnd = "&&";
    const char* doubleOr = "||";
    const char* semicolon = ";";
    Line *new_line = new Line;
    
    for(unsigned int i = 0; i < ggs.size(); i++){
        const char* temp[50];
            while(ggs[i] != doubleAnd && ggs[i] != doubleOr && ggs[i] != semicolon && i < ggs.size()){
                int k = 0;
                temp[k] = ggs[i];
                i++;
                k++;
            }
            if(i == ggs.size()){
                UserInput* new_executable_command = new ExecutableCommand(temp);
                new_line->Inputs.push_back(new_executable_command);
                return;
            }
            else{
                UserInput* new_executable_command = new ExecutableCommand(temp);
                new_line->Inputs.push_back(new_executable_command);
                UserInput* new_symbol = new Symbol(ggs[i]);
                new_line->Inputs.push_back(new_symbol);
            }
    }
    
    return;
}








int main(){
    ParseUserInput("ls -a; cd -m|| vim READDME.hpp");
    return 0;
}


