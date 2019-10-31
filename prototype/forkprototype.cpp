#ifndef __FORKPROTOTYPE_CPP__
#define __FORKPROTOTYPE_CPP__

#include <stdlib.h> //for free
#include <iostream>
#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(){

//Fork research
///////*a few things will be different in the actual program.
char * driver[3];//In our program this will be wrapped in a ExecutableCommand class
const char * ls = "ls";
const char * minusA = "-l";


driver[0] = strdup(ls);
driver[1] = strdup(minusA);
driver[2] = NULL;
int PassOrFail; //In our program this will be wrapped in a ExecutableCommand Class
///////ExecutableCommands are going to be given in a Vector<UserInput*> from line

pid_t child;
child = fork();
if (child < 0){
std::cout << "Massive error, fork failed." << endl;
}
//else if (InputVector[i]->PassOrFail == 0){ //This is all be to check if This executable has already "failed" due to a '&&' or '||'
////   //does nothing if passorfial ==0
//}
else if (child == 0) {
if(execvp(driver[0], driver) < 0){  //this will be (*InputVector[i-1]->words, InputVector[i-1]->words)
cout << "failed to exe,delete this mssg later."; //delete this msg later
PassOrFail = 0;      //signals that user input failed. Will be InputVector[i-1]->PassOrFail = 0;
}
}	
else{
PassOrFail = 1;      //Will be InputVector[i-1]->PassOrFail = 1;
cout<< PassOrFail;
waitpid(-1,&child,0);

}
free(driver[0]);
free(driver[1]);
return 1;
}

#endif
