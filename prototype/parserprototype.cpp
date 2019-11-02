#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h> 
#include <queue>
#include <string>
#include <vector>
#include <cstdlib>



class UserInput{

};

class Line: public UserInput {
    protected:
    private:
    public:
        int ParseUserInput();
        std::vector<UserInput*> Inputs;
};

class ExecutableCommand: public UserInput {
    private:
        const char** command = new const char*[50];
    public:
        ExecutableCommand(const char* word){
            command = word;
        }

};


class Symbol: public UserInput {
    private:
        const char* symbol;
    public:
        Symbol(const char* s){
            symbol = s;
        }
};


int main(){
    std::cout << "Type command\n";
    std::string line;
    std::getline (std::cin, line);
    
    int n = line.length();
    char* charArray[n+1];
    
    strcpy(charArray, line.c_str());
    
    Line *temp_2 = new Line;
    int count = 0;
    const char* s[] = new const char*;
    std::vector<const char*> temp_vector;
    
    for(unsigned int i = 0; i < line.size(); i++){
        if(line[i] == ' '){ 
            temp_vector.push_back(s);
            s[0] = "\n";
        }
        else if(line[i] == '&'){
            s = line[i];
            i++;
            s += line[i];
            temp_vector.push_back(s);
            s[0] = "\n";
            i++;
        }
        else if(line[i] == '|'){
            s = line[i];
            i++;
            s += line[i];
            temp_vector.push_back(s);
            s[0] = "\n";
            i++;
        }
        else if(line[i] == ';'){
            s = line[i];
            temp_vector.push_back(s);
            s[0] = "\n";
            i++;
        }
        else{
        s+= line[i];
        }
    }
    temp_vector.push_back(s);
    
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        std::cout << temp_vector[i] << std::endl;
    }

    

    
    const char* executable_command;
    const char* doubleAnd = "&&";
    const char* ddoubleOr = "||";
    const char* semicolon = ";";
    
    
    
    
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        std::cout << i << std::endl;
        while(temp_vector[i] != doubleAnd && temp_vector[i] != ddoubleOr && temp_vector[i] != semicolon){
            executable_command += temp_vector[i];
            i++;
            std::cout << "crashprogram" << std::endl;
            if(i == temp_vector.size()){
                 std::cout << "crashprogram1" << std::endl;
                UserInput* new_executable_command = new ExecutableCommand(executable_command);
                temp_2->Inputs.push_back(new_executable_command);
                exit(1);
            }
        }
        UserInput* new_executable_command = new ExecutableCommand(executable_command);
        UserInput* new_symbol = new Symbol(temp_vector[i]);
        temp_2->Inputs.push_back(new_executable_command);
        temp_2->Inputs.push_back(new_symbol);
        executable_command = "";
        count++;
    }
    return 0;
}
