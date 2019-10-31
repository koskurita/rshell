#ifndef __FORKPROTOTYPE_CPP__
#define __FORKPROTOTYPE_CPP__

#include <iostream>
#include  <stdio.h>
#include  <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main(){

//Fork research
///////*a few things will be different in the actual program.
char * driver[] = {"ls", "-a"};//In our program this will be wrapped in a ExecutableCommand class
int PassOrFail; //In our program this will be wrapped in a ExecutableCommand Class
///////ExecutableCommands are going to be given in a Vector<UserInput*> from line

pid_t child;
child = fork();
if (child < 0){
std::cout << "Massive error, fork failed." << endl;
}
//else if (InputVector[i]->PassOrFail == 0){ //This is all be to check if This executable has already "failed" due to a '&&' or '||'
////
////
////
//}
else if (child == 0) {
if(execvp(*driver, driver) < 0){  //this will be (*InputVector[i-1]->words, InputVector[i-1]->words)
PassOrFail = 0;      //signals that user input failed. Will be InputVector[i-1]->PassOrFail = 0;
}
}	
else{
PassOrFail = 1;      //Will be InputVector[i-1]->PassOrFail = 1;
waitpid(child);

}

return 1;
}

//char * driver1[] = {'l','s'}
//char * driver2[] = {'-','a'}
//char ** driver3[] = {driver1,driver2}//this is a pointer to a array of char*
#endif
