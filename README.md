# CS 100 Programming Project

Fall Quarter 2019

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

# Prototypes/Research
**fork()**

**waitpid()**

**execvp()**

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
