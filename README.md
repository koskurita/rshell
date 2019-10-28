# CS 100 Programming Project Fall Quarter 2019

Robert Wyatt 862134626

Kosuke Kurita 862011998

# Introduction
**stuff**

# Diagram
![inheritanceTree](https://github.com/cs100/assignment-team_robert_kosuke/blob/master/images/inheritancetree.png)

# Classes
**Userinput**

	Userinput is the base class and  it takes the input from the user and assigns an ID for each line. The ID is use to determine whether the userinput is asymbol or an executable command.

**Line**

	Line is a vector of userinput which contains either symbols or executable_commands.

**Symbols**

	Symbols are userinputs that are either ";", "||", or "&&" which all symbolize the endd of an executable command.

**SemiColon**

	The semicolon represents the end of an executable command.

**DoubleSlash**

	The "or" symbol runs the executable command which comes after it only if the command prior to the symbol fails to run successfully.

**DoubleAnd**

	The "and" symbol runs the executable command which comes after it only if the command prior to the symbol runs successfully.

**ExecutableCommands**

	Executable commands are vector of strings that store the commands that are going to be run on the terminal.


# Prototypes/Research
**fork()**

**waitpid()**

**execvp()**

#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>

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
        std::string command;
    public:
        ExecutableCommand(std::string s){
            command = s;
        }
};


class Symbol: public UserInput {
    private:
        std::string symbol;
    public:
        Symbol(std::string s){
            symbol = s;
        }
};



void Line:: doInputs(){
    Userinput* blank_semicolon = new Semicolon;                     // since perform next does not run the final executable command, we set a dummy executable command at the end
    UserInput* blank_executable_command = new ExecutableCommand("");
    Inputs.push_back(blank_semicolon);
    Inputs.push_back(blank_executable_command);
    
    
    for (i = 0; i < Inputs.size();i++){
        if(Inputs[i]->ID >= 100){
            Inputs[i]->PerformNext(Inputs[i-1], Inputs[i+1]);
        }
    }
}


void Semicolon:: PerformNext(UserInput* first, UserInput* next){
    if(first->pass_or_fail != -1){
        return 0;
    }
    else{
        if (Run(first)){
            return 0;
            //nothing
        }
        else{
            return 0;
            //nothing
        }
    }
}

void DoubleAnd:: PerformNext(UserInput* first, UserInput* next){
    if(first->pass_or_fail != -1){
        next->pass_or_fail = 0;
        return 0;
    }
    else{
        if (Run(first)){
            next->pass_or_fail = -1; // technically you dont change anything
            return 0;
        }
        else{
            next->pass_or_fail = 0; // since the first one failed, you odnt run the next command
            return 0;
        }
    }
}

void DoubleSlash:: PerformNext(UserInput* first, UserInput* next){
    if(first->pass_or_fail != -1){
        return 0;
    }
    else{
        if (Run(first)){
            next->pass_or_fail = 0;
            return 0;
        }
        else{
            return 0;
        }
    }
}


bool ExecutableCommand:: Run(UserInput* s){
    // run the command on console;
    
}


int Line::ParseUserInput(){
    std::cout << "Type command\n";
    std::string line;
    std::getline (std::cin, line);
    
    Line *temp_2 = new Line;
    int count = 0;
    std::string s = "";
    std::vector<std::string> temp_vector;
    
    for(unsigned int i = 0; i < line.size(); i++){
        if(line[i] == ' '){
            s += line[i];
            temp_vector.push_back(s);
            s = "";
        }
        else if(line[i] == '&'){
            s = line[i];
            i++;
            s += line[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(line[i] == '|'){
            s = line[i];
            i++;
            s += line[i];
            temp_vector.push_back(s);
            s = "";
            i++;
        }
        else if(line[i] == ';'){
            s = line[i];
            temp_vector.push_back(s);
            s = "";
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

    
    std::string executable_command;
    
    for(unsigned int i = 0; i < temp_vector.size(); i++){
        std::cout << i << std::endl;
        while(temp_vector[i] != "&&" && temp_vector[i] != "||" && temp_vector[i] != ";"){
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



# Development and Testing Roadmap
1. Classes
	1. UserInput
	2. Symbols
	3. Line
	4. Semicolon
	5. DoubleSlash
	6. DoubleAnd
	7. s 
2. Testing

