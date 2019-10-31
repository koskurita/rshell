# CS 100 Programming Project Fall Quarter 2019

Robert Wyatt 862134626

Kosuke Kurita 862011998

# Introduction

This program will be able to get an input from the user and split that input into
classes that will determine which commands should and shouldn't be run. We use a composite
pattern that has UserInputs at the top and a Line class that has a vector of UserInputs.
The Line class is in charge of taking in the inputs and putting it into it's vector and it 
is in charge of actually running the inputs. Line stores values in two different types
of classes called ExecutableCommand and Symbols, where Symbols are ";", "&&", and "||" and 
ExecutableCommands are everything else.

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

**fork(),waitpid(),execvp research**

By researching and testing we figured out that execvp will automatically return after used. To prevent this from bringing the program to a
hault, fork is used to create a copy thread that will be closed. Waitpid is used to force the parrent to wait for the child to close. This
is useful in the case of using execvp because we just created a thread for the purpose of closing it. 

An important note is that execvp takes in char * * and char * parameters. Because of that we are forced to create new char * that must
be deleted or create memory leaks. 

Another important not is that the pid_t needed for waitpid and returned by all 3 functions is, for all intents and purposes, an int.

Finally, there is the possibility that fork can become useful in the future if more intense functions are implemented in the future.
fork is an easy way to create new threads so long as you are careful to close them. 





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
	1. UserInput https://github.com/cs100/assignment-team_robert_kosuke/issues/5
	2. Symbols https://github.com/cs100/assignment-team_robert_kosuke/issues/6
	3. Line https://github.com/cs100/assignment-team_robert_kosuke/issues/7
	4. Semicolon https://github.com/cs100/assignment-team_robert_kosuke/issues/8
	5. DoubleSlash https://github.com/cs100/assignment-team_robert_kosuke/issues/9
	6. DoubleAnd https://github.com/cs100/assignment-team_robert_kosuke/issues/10
	7. ExecutableCommand https://github.com/cs100/assignment-team_robert_kosuke/issues/11
2. Unit Testing
	1. UserInput https://github.com/cs100/assignment-team_robert_kosuke/issues/12
	2. Symbols https://github.com/cs100/assignment-team_robert_kosuke/issues/13
	3. Line https://github.com/cs100/assignment-team_robert_kosuke/issues/14
	4. Semicolon https://github.com/cs100/assignment-team_robert_kosuke/issues/15
	5. DoubleSlash https://github.com/cs100/assignment-team_robert_kosuke/issues/16
	6. DoubleAnd https://github.com/cs100/assignment-team_robert_kosuke/issues/17
	7. ExecutableCommand https://github.com/cs100/assignment-team_robert_kosuke/issues/18
3. Integration Testing
	1. Semicolon with DoubleSlash https://github.com/cs100/assignment-team_robert_kosuke/issues/19
	2. Semicolon with DoubleAnd https://github.com/cs100/assignment-team_robert_kosuke/issues/20
	3. DoubleAnd with DoubleSlash https://github.com/cs100/assignment-team_robert_kosuke/issues/21
	4. DoubleSlash with DoubleAnd https://github.com/cs100/assignment-team_robert_kosuke/issues/22

