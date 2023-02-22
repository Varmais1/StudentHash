#include <iostream>
#include <cstring>
#include <iomanip>
#include "hash.h"
#include <math.h>

void singlelowercase(char sentence[]);


int main() {
  char command[10];
  Hash* table= new Hash();
  while(true) {
    cout << "Type in add, delete, print, or quit." << endl;
    cin >> command;
    singlelowercase(command);
    if(strcmp(command, "quit") == 0) {
      break;
    }
    else if(strcmp(command, "print") ==0) {
      table->print();
    }
    else if(strcmp(command, "add") == 0) {
      char firstName[150];
      char lastName[150];
      int id;
      float GPA;
      cout << "Enter the first name." << endl;
      cin >> firstName;
      cout << "Enter the last name." << endl;
      cin >> lastName;
      cout << "Enter the id number. Please enter a number." << endl;
      cin >> id;
      cout << "Enter the GPA of the student. Please enter a number." << endl;
      cin >> GPA;
      bool sometimes_success = table->add(new Node(new Student(firstName,lastName,id,GPA)));
      if(success == true) {
	Hash* hash = new Hash(table->size * 2);
	Hash* deleted = table;
	table->copy(hash);
	table = hash;
	delete deleted;
      }
      //cout << "not success: " << !sometimes_success << endl;
    }
    else if(strcmp(command, "delete") == 0) {
      cout << "What is the id of the student whose record you wish to delete?" << endl;
      int id;
      cin >> id;
      table->deleter(id);
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
