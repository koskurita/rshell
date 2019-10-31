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
	Line contains a vector of userinput which contains ExecutableCommand and Symbol, one after the other. It also contains a function which executes all of the ExecutableCommand that are within the vector andd are supposedd to run.
**Symbols**
	Symbols are userinputs that are either ";", "||", or "&&" which are used to mark the end of an executable command. Each symbols have a particular meaning which affects the operation of the next executable command.
**;**
	The semicolon represents the end of an executable command. It does not affect the next executable command.
**||**
	The "or" symbol checks if the previous command has successfully executed or not. If the previous command successfully executed, the the next command will not run. Otherwise, the next one will run normally.
**&&**
	The "and" symbol checks if the previous command has successfully executed or not. If the previous command successfully executed, the next command will run normally. Otherwise, the next command will not run.
**ExecutableCommands**
	Executable commands are vector of char arrays that store the commands which are going to be run on the terminal.


# Prototypes/Research
**fork()**

**waitpid()**

**execvp()**

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

