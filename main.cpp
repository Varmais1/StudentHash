#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include <math.h>

void singlelowercase(char sentence[]);


int main() {
  char command[10];
  Node* *table = new Node*[100];
  while(true) {
    cout << "Type in add, delete, print, or quit." << endl;
    cin >> command;
    singlelowercase(command);
    if(strcmp(command, "quit") == 0) {
      break;
    }
  




  }

  return 0;
}



//makes all letters lowercase
void singlelowercase(char sentence[]) {
  //iterating variable
   int i = 0;
   //go through the char array
   while(true) {
     int charVal = (int) sentence[i];
     //if the letter is capital, make it lowercase using ASCII
     if(65<=charVal && charVal <= 90) {
       sentence[i] = (char)(charVal+32);
     }
     //if the character is the null character, 
     else if(sentence[i] == '\0') {
       break;
     }
     //increment the variable
     i++;
   }
}
