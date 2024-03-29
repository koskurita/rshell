#pragma once
#include <iostream>
#include "Line.hpp"


using namespace std;
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
			if(Inputs[IterInt]->returnPassOrFail() != 0)   //if the last executable command's passOrFail has not been set to fail...
				if(Inputs[IterInt]->returnID() < 100)//and the last thing in the vector IS an executableCommand...
					Inputs[IterInt]->doInput();  //run doInput.
		}

                IterInt++;//do nothing and skip one because this is a Executable command
            }

        }

    }
  

UserInput* Line::ParseUserInput(string cheese){

    int end_w_q = 0;
    string s = "";

    vector<string> temp_vector;

    for(unsigned int i = 0; i < cheese.size(); i++){

        if(cheese[i] == ' '){
            if(cheese[i-1] == '&' || cheese[i-1] == '|' || cheese[i-1] == ';'){
                 s = "";
                end_w_q = 0;
            }
            else{
                temp_vector.push_back(s);
                s = "";
                end_w_q = 0;
            }

        }
        else if(cheese[i] == '"'){
            i++;
            while(cheese[i] != '"'){
                s += cheese[i];
                i++;
            }
            temp_vector.push_back(s);
            s = "";
            i++;
            end_w_q = 1;
        }
        
        else if(cheese[i] == '#'){
            end_w_q = 1;
            break;
        }

        else if(cheese[i] == '&'){
            if(cheese[i-1] != ' '){
                temp_vector.push_back(s);
                s = "";
            }
            
            s = cheese[i];
            i++;
            s += cheese[i];
            temp_vector.push_back(s);

            s = "";


        }

        else if(cheese[i] == '|'){
            if(cheese[i-1] != ' '){
                temp_vector.push_back(s);
                s = "";
            }

            s = cheese[i];

            i++;

            s += cheese[i];

            temp_vector.push_back(s);

            s = "";

        }

        else if(cheese[i] == ';'){
            if(cheese[i-1] != ' '){
                temp_vector.push_back(s);
                s = "";
            }

            s = cheese[i];

            temp_vector.push_back(s);

            s = "";

        }

        else{

        s+= cheese[i];
        end_w_q = 0;
        }

    }
    
    if(end_w_q == 0){
        temp_vector.push_back(s);
    }

    


/*
 *     for(unsigned int i = 0; i < temp_vector.size(); i++){
 *
 *             std::cout << temp_vector[i] << std::endl;
 *
 *                 }*/





    vector<const char*> ggs;

    const char* charArray;

    for(unsigned int i = 0; i < temp_vector.size(); i++){

        charArray = temp_vector[i].c_str();
        

        ggs.push_back(charArray);

    }



/*    for(unsigned int i = 0; i < ggs.size(); i++){
 *
 *            cout << ggs[i] << endl;
 *
 *                }
 *                */


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

            UserInput* new_symbol = new DoubleSlash(ggs[i]);

            this->Inputs.push_back(new_symbol);
            
            for(int y =0; y < 50;y++){

                temp[y] = NULL;
            }
            k = 0;
        }
        
        else if((strcmp(doubleOr,ggs[i]) == 0)){
            

            UserInput* new_executable_command = new ExecutableCommand(temp);

            this->Inputs.push_back(new_executable_command);

            UserInput* new_symbol = new DoubleAnd(ggs[i]);

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

        
        
        

    cout << new_line->Inputs.size();

    return new_line;

}


