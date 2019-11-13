#include <iostream>

#include <sstream>

#include <fstream>

#include <queue>

#include <string>

#include <vector>

#include <cstdlib>

#include <cstring>

#include <stdlib.h>

#include  <sys/types.h>

#include <stdio.h>

#include <sys/wait.h>

#include <unistd.h>



using namespace std;

class UserInput{

    protected:

        int ID;
    private:

        int passOrFail = -1;

    public:
        UserInput(){
            ID = 0;
        }

        int ReadID(){return ID;}

        virtual UserInput* ParseUserInput(string cheese) = 0;

        virtual void doInput() = 0;

        virtual void SetPassOrFail(int oneOrZero) = 0;

        virtual bool PerformNext(UserInput* one, UserInput* two)=0;//returns true if the next command will execute, false if it will not

        virtual int returnID(){

            return ID;

        }

        int returnPassOrFail(){

            return passOrFail;

        }

    

};
class Line: public UserInput {

    private:

/*        int ID = 2;*/

    vector<UserInput*> Inputs;

    int passOrFail = -1;

    public:

    Line(){//default constructor

    ID = 2;

    }



    ~Line(){//This destructor should call the destructor of every element in the vector and then pop it.

    int lastElement = Inputs.size() - 1;

    while (lastElement != -1){

    delete Inputs[lastElement];

    Inputs.pop_back(); // delete later 

    lastElement--;

    }

    

    

    }

    /*IF we ever put a line in a line then this becomes useful*/
    
     void SetPassOrFail(int oneOrZero){
    
     this->passOrFail = oneOrZero;
    
     }
    
    int ReturnPassOrFail(){
    
     return this->passOrFail;
    
       }


 bool PerformNext(UserInput *one, UserInput*two){//do not use perform next on a line

        

        std::cout << "do not use perform next on a line.";

        exit(0);

    }

UserInput* ParseUserInput(std::string cheese);



    void doInput(){
        unsigned int IterInt = 0; 

        while(IterInt < Inputs.size()){//while iterInt < SizeOVec
            if (Inputs[IterInt]->returnID() > 100){ //if Inputs[IterInt] = Symbol
		if(IterInt != 0){
                	Inputs[IterInt - 1]->doInput();//call doInput on ExecutableCommand Which exists prior to symbol
                	Inputs[IterInt]->PerformNext(Inputs[IterInt-1],Inputs[IterInt + 1]);//call perform next on the symbol
                	IterInt++;
		  }//Example ls || -a ; ls
	    	else {
		cout << "Error, symbol(&&,||,;) is first element inputted." << endl;
		exit(0);
		}
            }
            else{
		if(IterInt == Inputs.size() - 1){
			if(Inputs[IterInt]->returnPassOrFail != 0)   //if the last executable command's passOrFail has not been set to fail...
				if(Inputs[IterInt]->returnID() < 100)//and the last thing in the vector IS an executableCommand...
					Inputs[IterInt]->doInput();  //run doInput.
		}

                IterInt++;//do nothing and skip one because this is a Executable command
            }

        }

}


};


class ExecutableCommand: public UserInput { // USE CONST CHAR

    private:

        char* command[50];  //remove const

        int passOrFail = -1;

/*        int ID = 1;*/

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

    command[iterInt + 1] = NULL;

    

        }





    ~ExecutableCommand(){

    int iterInt = 0;

    while(command[iterInt] != NULL){

        free(command[iterInt]);

        iterInt++;

        }

    }


 UserInput* ParseUserInput(std::string cheese){//do not call

    std::cout << "Error, do not call parseUserINput in executablecommand";}

    bool PerformNext(UserInput * one, UserInput * two){

    std::cout << "Error. do not call performNext in executablecommand.";

    return false;

    }

 void doInput(){
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
};



class Symbol: public UserInput {

    private:

        const char* symbol;

/*        int ID = 100;*/

        int passOrFail = -1;

    public:



    virtual bool PerformNext(UserInput* one, UserInput* two){

    two->SetPassOrFail(1);

    return true;

    }



    Symbol(const char* s){//default constructor

            symbol = s;

            ID = 100;

        }



    UserInput* ParseUserInput(std::string cheese){//dont use this

        std::cout<< "Symbols dont call ParseUserInput"; return NULL;}



        void doInput(){
/*do nothing*/
}
           void SetPassOrFail(int oneOrZero){//dont use this

        std::cout<< "Symbols dont call oneOrZero";}



        int ReturnPassOrFail(){//dont use this

    std::cout<< "Symbols dont call ReturnPassOrFail"; return 0;}

        

};

class DoubleAnd:public Symbol{

    private:

    const char* symbol;
/*
    int ID;*/

    int passOrFail = -1;

 public:   

DoubleAnd(const char * s):Symbol(s){//default constructor

ID = 103;

}

bool PerformNext(UserInput * one, UserInput * two){

if (one->returnPassOrFail() == 1){
/*do nothing*/

return true;

}

else

two->SetPassOrFail(0);

return false;

}

};



class DoubleSlash:public Symbol{

    private:

    const char* s;

/*    int ID;*/

    int passOrFail = -1;

public:

DoubleSlash(const char * s):Symbol(s){//default constructor

ID = 102;

}

bool PerformNext(UserInput * one, UserInput * two){

if (one->returnPassOrFail() == 1){

two->SetPassOrFail(0);

return false;

}

    else{
/*do nothing*/
    return true;

    }
}

};



class SemiColon: public Symbol{

    private:

    const char* s;

/*    int ID;*/

    int passOrFail = -1;

public:

SemiColon(const char* s):Symbol(s){//default constructor

ID = 101;

}

bool PerformNext(UserInput * one, UserInput * two){

if (one->returnPassOrFail() == 1){ 
/*do nothing*/
return true;

}

else
/*do nothing*/
return true;

}



};

UserInput* Line::ParseUserInput(string cheese){

    string s = "";

    vector<string> temp_vector;

    for(unsigned int i = 0; i < cheese.size(); i++){

        if(cheese[i] == ' '){

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

    


/*
    for(unsigned int i = 0; i < temp_vector.size(); i++){

        std::cout << temp_vector[i] << std::endl;

    }*/





    vector<const char*> ggs;

    const char* charArray;

    for(unsigned int i = 0; i < temp_vector.size(); i++){

        charArray = temp_vector[i].c_str();
        

        ggs.push_back(charArray);

    }



/*    for(unsigned int i = 0; i < ggs.size(); i++){

        cout << ggs[i] << endl;

    }
*/


    const char* doubleAnd = "&&";

    const char* doubleOr = "||";

    const char* semicolon = ";";

    Line *new_line = new Line;

    int k = 0;

    const char* temp[50];
    

    for(unsigned int i = 0; i < ggs.size(); i++){
        if((strcmp(doubleAnd,ggs[i]) == 0)){
            
            
            
            UserInput* new_executable_command = new ExecutableCommand(temp);

            this->Inputs.push_back(new_executable_command);

            UserInput* new_symbol = new DoubleAnd(ggs[i]);

            this->Inputs.push_back(new_symbol);
            
            for(int y =0; y < 50;y++){

                temp[y] = NULL;
            }
            k = 0;
        }
        
        else if((strcmp(doubleOr,ggs[i]) == 0)){
            

            UserInput* new_executable_command = new ExecutableCommand(temp);

            this->Inputs.push_back(new_executable_command);

            UserInput* new_symbol = new DoubleSlash(ggs[i]);

            this->Inputs.push_back(new_symbol);
            for(int y =0; y < 50;y++){

                temp[y] = NULL;
            }
            k = 0;
         }
        
        else if((strcmp(semicolon,ggs[i]) == 0)){
            UserInput* new_executable_command = new ExecutableCommand(temp);

            this->Inputs.push_back(new_executable_command);

            UserInput* new_symbol = new SemiColon(ggs[i]);

            this->Inputs.push_back(new_symbol);
            
            for(int y =0; y < 50;y++){

                temp[y] = NULL;
            }
            k = 0;
        }
        else {

            temp[k] = ggs[i];
            k++;
        }
    }
    
    const char* empty[50];

           
    UserInput* new_executable_command = new ExecutableCommand(temp);
    this->Inputs.push_back(new_executable_command);
    UserInput* new_symbol = new SemiColon(ggs[0]);
    this->Inputs.push_back(new_symbol);
/*    this->Inputs.push_back(new ExecutableCommand(empty));*/
    

        
        
        

          /*  while(!(ggs[i] == doubleAnd || ggs[i] == doubleOr || ggs[i] == semicolon) && i < ggs.size()){
                cout << ggs[i];
                cout << "test1" << endl;
                temp[k] = ggs[i];

                i++;

                k++;

            }

            if(i == ggs.size()){
                UserInput* new_executable_command = new ExecutableCommand(temp);

                this->Inputs.push_back(new_executable_command);
                cout << "test2" << endl;

                break;

            }

            else{
                cout << "test3" << endl;

                UserInput* new_executable_command = new ExecutableCommand(temp);

                this->Inputs.push_back(new_executable_command);

                UserInput* new_symbol = new Symbol(ggs[i]);

                this->Inputs.push_back(new_symbol);

            }

    }*/
    cout << new_line->Inputs.size();

    return new_line;

}

int main(){
UserInput * mainLine = new Line();
mainLine->ParseUserInput("ls -a && ls -a || ls -a");

//further tests as the first is acomplished:
mainLine->doInput();
  delete mainLine;
  return 0;

}
