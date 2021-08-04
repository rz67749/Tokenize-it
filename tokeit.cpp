#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

/**  
 * This program takes in a line from the user
 * this line should contain the name of a program
 * and any arguments the user wants to use with the program
 * this then breaks down the user's line into tokens, and attempts 
 * to launch the specified program with them
 */

using namespace std;

int main(){

  char *inputLine;
  string rawInput;

  getline(cin, rawInput);

  inputLine = &rawInput[0];

  char *argArray[10];
  
  int argCounter = 0;
  
  argArray[0] = strtok(inputLine, " ");

  if(argArray[0] != NULL){
    argCounter = 1;
  
  char *current;

    do{
      current = strtok(NULL, " ");
      argArray[argCounter] = current;
      if(current != NULL){
	argCounter ++;
      }
    }while(current != NULL);
  }//if
  
  cout << "Done Parsing" << endl;
  cout << "num args: " << argCounter << endl;

  if(argCounter > 0){
    for(int i = 0; i < argCounter; i ++){
      cout << argArray[i] << endl;
    }//for
    
    if(execvp(argArray[0], argArray) < 0){
      perror("error execvp");
    }
  }//if
  
}//main
