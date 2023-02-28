#include <iostream>
#include <cstring>
#include <iomanip>
#include "hash.h"
#include <math.h>
#include <fstream>

void singlelowercase(char sentence[]);


int main() {
  //sets random seed
  srand(time(NULL));
  int randid = 1;
  //takes in command, and creates the hash table pointer
  char command[10];
  Hash* table= new Hash();
  //runs the program
  while(true) {
    //gets input
    cout << "Type in add, randadd, delete, print, clear, or quit." << endl;
    cin >> command;
    singlelowercase(command);
    //if quit, get out of the while loop
    if(strcmp(command, "quit") == 0) {
      break;
    }
    //if print, call the hash table's print function
    else if(strcmp(command, "print") ==0) {
      table->print();
    }
    //if add, get the necessary information, and use the tables add function to insert the data, and if needed, do other things.
    //the implementation of the Hash class add function is in hash.cpp
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
      int sometimes_success = table->add(new Node(new Student(firstName,lastName,id,GPA)));
      //if more than 3 elements are in a chain, create a new hash table that is double the size, copy the old table over, and delete the old table
      if(sometimes_success == 1) {
	Hash* hash = new Hash(table->size * 2);
	Hash* deleted = table;
	table->copy(hash);
	table = hash;
	delete deleted;
      }
      //if a student with the same id is entered, tells the user that they need to enter a student with a unique id
      else if(sometimes_success == 2) {
	cout << "Please enter a student with a unique id." << endl;
      }
      //cout << "not success: " << !sometimes_success << endl;
    }
    else if(strcmp(command, "delete") == 0) {
      //gets the id of the student to be deleted, and deletes the student using the hashTable deleter function which can be found in hash.cpp
      cout << "What is the id of the student whose record you wish to delete?" << endl;
      int id;
      cin >> id;
      table->deleter(id);
    }
    //goes into this if randadd is given
    else if(strcmp(command, "randadd") == 0) {
      //the amount of students the user wants to add
      int reps = 0;
      //information storing variables
      char firstName[150];
      char lastName[150];
      float GPA;
      char fileContents[20][15];
      cout << "How many students would you like to add?" << endl;
      cin >> reps;
      //gets the data needed for random names
      ifstream finput("data.txt");
      int counter = 0;
      while(finput >> fileContents[counter++]);
      //adds the amount of students the user wants by getting a random name from the name file, a random GPA, and a sequential id that is defined at the top of main. This also deals with the error clauses that add returns
      for(int i = 0; i < reps; i++) {
	int index1 = rand() % 20;
	int index2 = rand() % 20;
	strcpy(firstName, fileContents[index1]);
	strcpy(lastName, fileContents[index2]);
	float GPA = (float)(rand() % 301)/100.f + 1.f;
	int sometimes_success = table->add(new Node(new Student(firstName,lastName,randid++,GPA)));
	if(sometimes_success == 1) {
	  Hash* hash = new Hash(table->size * 2);
	  Hash* deleted = table;
	  table->copy(hash);
	  table = hash;
	  delete deleted;
	}
	else if(sometimes_success == 2) {
	  reps++;
	}
      }
      
    }
    //if the user wants to clear the text, clear the text
    else if(strcmp(command, "clear") == 0) {
      system("clear");
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
