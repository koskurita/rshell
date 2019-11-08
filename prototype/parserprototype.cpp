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
    protected:
        int ID = 0;
    	int passOrFail = -1;
    public:
        int ReadID(){return ID;}
        virtual void ParseUserInput(string cheese);
        virtual void doInput();
        virtual void SetPassOrFail(int oneOrZero);
        virtual int ReturnPassOrFail();
        virtual bool PerformNext(UserInput* one, UserInput* two);//returns true if the next command will execute, false if it will not       
};

class Line: public UserInput {
    private:
        //int ID = 2;
	vector<UserInput*> Inputs;
	//int passOrFail = -1;
    public:
	Line(){//default constructor
	ID = 2;
	}

	~Line(){//This destructor should call the destructor of every element in the vector and then pop it. 
	int lastElement = Input.size() - 1;
	while (lastElement != -1){
	Inputs->~Inputs[lastElement];
	Inputs.pop_back();
	lastElement--;
	}
	
	
	}
	////IF we ever put a line in a line then this becomes useful
	void SetPassOrFail(int oneOrZero){
	this->passOrFail = oneOrZero;
	}
	int ReturnPassOrFail(){
	return this->passOrFail;
	}
	/////
	
	
	////DONT USE THESE
	bool PerformNext(UserInput *one, UserInput*two){//do not use perform next on a line
	std::cout << "do not use perform next on a line."
	}
	////

	
        void ParseUserInput(std::string cheese);

        void doInput(){
	int IterInt = 0;
	while(IterInt < Inputs.size())
	if (Inputs[IterInt]->ID < 100)
	{
	Inputs[IterInt]->doInput();//call do input on executable/line
	IterInt++;
	Inputs[InterInt]->PerformNext(Inputs[IterInt - 1],Inputs[IterInt + 1]);//call perform next on the symbol
	}
	else
	{
	IterInt++;//do nothing and skip one because this is a symbol
	}
}
};

class ExecutableCommand: public UserInput { // USE CONST CHAR
    private:
        char* command[50];  //remove const
 //       int passOrFail = -1;
   //     int ID = 1;
    public:
        void SetPassOrFail(int oneOrZero) // this function sets pass or fail to one or zero
	{this->passOrFail = oneOrZero;}
        int ReturnPassOrFail(){return this->passOrFail;} //Returns pass or fail integer*/

	
	
        ExecutableCommand(const char* words[50]){ // constructor
        ID = 1;
	
	int iterInt = 0;
	while(words[iterInt] != NULL){
	command[iterInt] = strdup(words[iterInt]);
	iterInt++;
	}    
	command[IterInt + 1] = NULL;
	
        }


	~ExecutableCommand(){
	int iterInt = 0;
	while(words[iterInt] != NULL){
        free(words[iterInt]);
        iterInt++;
        }
	}
	
	////DO NOT CALL THESE
	void ParseUserInput(std::string cheese){//do not call
	std::cout << "Error, do not call parseUserINput in executablecommand";}
	bool PerformNext(UserInput * one, UserInput * two){
	std::cout << "Error. do not call performNext in executablecommand.";
	}
	////

	void doInput(){//this is now neccessary
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
	
	
};

class Symbol: public UserInput {
    private:
        const char* symbol;
        //int ID = 100;
	//int passOrFail = -1;
    public:

        virtual bool PerformNext(UserInput* one, UserInput* two){
	two->passOrFail = 1;
	return true;
	}

        Symbol(const char* s){//default constructor
            symbol = s;
	ID = 100;
        }

	void ParseUserInput(std::string cheese){{//dont use this
        std::cout<< "Symbols dont call ParseUserInput"; return 0;}
}
        void doInput(){{
        //do nothing}
}
        void SetPassOrFail(int oneOrZero);{//dont use this
        std::cout<< "Symbols dont call oneOrZero";}

        int ReturnPassOrFail(){//dont use this
	std::cout<< "Symbols dont call ReturnPassOrFail"; return 0;}
        
};
class DoubleAnd:public Symbol{
DoubleAnd(){//default constructor
ID = 103;
}
bool PerformNext(UserInput * one, UserInput * two){
if (one->passOrFail == 1){
//do nothing
return true;
}
else 
two->setPassOrFail(0);
return false;
}
};

class DoubleSlash:public Symbol{
DoubleSlash(){//default constructor
ID = 102;
}
bool PerformNext(UserInput * one, UserInput * two){
if (one->passOrFail == 1){
two->setPassOrFail(0);
return false;
}
else
//do nothing
return true;
}
};

class SemiColon: public Symbol{
SemiColon(){//default constructor
ID = 101;
}
bool PerformNext(UserInput * one, UserInput * two){
if (one->passOrFail == 1){
//do nothing
return true;
}
else
//do nothing
return true;
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
    const char* charArray;
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        charArray = temp_vector[i].c_str();
        ggs.push_back(charArray);
    }

    for(unsigned int i = 0; i < ggs.size(); i++){
        cout << ggs[i] << endl;
    }

    const char* doubleAnd = "&&";
    const char* doubleOr = "||";
    const char* semicolon = ";";
    Line *new_line = new Line;
    int k;
    const char* temp[50];
    for(unsigned int i = 0; i < ggs.size(); i++){
	        for(int y =0; y < 50;y++){
                temp[y] = NULL;
            }
	    k = 0;
            while(ggs[i] != doubleAnd && ggs[i] != doubleOr && ggs[i] != semicolon && i < ggs.size()){
                temp[k] = ggs[i];
                i++;
                k++;
            }
            if(i == ggs.size()){
                UserInput* new_executable_command = new ExecutableCommand(temp);
                new_line->Inputs.push_back(new_executable_command);
                break;
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


