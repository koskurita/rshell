#include <iostream>
#include "Line.hpp"

    Line::Line(){//default constructor
        ID = 2;
    }

    Line::~Line(){//This destructor should call the destructor of every element in the vector and then pop it.
        int lastElement = Inputs.size() - 1;
        while (lastElement != -1){
            delete Inputs[lastElement];
            Inputs.pop_back(); // delete later 
            lastElement--;
        }
    }
    
    ////IF we ever put a line in a line then this becomes useful
    void Line::SetPassOrFail(int oneOrZero){
        this->passOrFail = oneOrZero;
    }
    
    int Line::ReturnPassOrFail(){
        return this->passOrFail;
    }
    /////
    
    
    ////DONT USE THESE
    bool Line::PerformNext(UserInput *one, UserInput*two){//do not use perform next on a line
        std::cout << "do not use perform next on a line.";
        exit(0);
    }
    ////

    void Line::doInput(){
        unsigned int IterInt = 0;
        while(IterInt < Inputs.size()){
            if (Inputs[IterInt]->returnID() < 100){
                Inputs[IterInt]->doInput();//call do input on executable/line
                IterInt++;
                Inputs[IterInt]->PerformNext(Inputs[IterInt - 1],Inputs[IterInt + 1]);//call perform next on the symbol
            }
            else
            {
            IterInt++;//do nothing and skip one because this is a symbol
            }
        }
    }
    
    

void Line::ParseUserInput(string cheese){
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
            if(cheese[i] == '#'){
                i = cheese.size();
            }
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
