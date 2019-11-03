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
/*        void doInput(); // this executes using execvp*/
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
    public:
/*        bool PerformNext(UserInput* one, UserInput* two);*/
        Symbol(const char* s){
            symbol = s;
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


