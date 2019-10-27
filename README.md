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

# Development and Testing Roadmap
1. Classes
	1. UserInput
	2. Symbols
	3. Line
	4. Semicolon
	5. DoubleSlash
	6. DoubleAnd
	7. ExecutableCommand 
2. Unit Testing
	1. UserInput
	2. Symbols
	3. Line
	4. Semicolon
	5. DoubleSlash
	6. DoubleAnd
	7. ExecutableCommand
3. Interation Testing
	1. Semicolon with DoubleSlash
	2. Semicolon with DoubleAnd
	3. DoubleAnd with DoubleSlash
	4. DoubleSlash with DoubleAnd
