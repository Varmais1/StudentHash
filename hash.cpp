#include "hash.h"
using namespace std;

void printNodes(Node* head);
int listLen(Node* head);
void deleteNode(Node* &head, Node* current, Node* previous, int id);

//constructors
Hash::Hash() {
  table = new Node*[101];
  size = 101;
}

Hash::Hash(int sizeN) {
  table = new Node*[sizeN];
  size = sizeN;
}

int Hash::add(Node* data) {
  //get the index by passing the id through the hash function and modding by size
  unsigned int index = Hash::hashFunc((unsigned int)data->getStudent()->id) % size;
  //cout << "index: " << index << endl;
  //if there is a student with the same id, return 2 to signify that error
  for(Node* loop = table[index]; loop != NULL; loop = loop->getNext()) {
    if(loop->getStudent()->id == data->getStudent()->id) {
      return 2;
    }
  }
  //if there is no student with the same id, then set the next of the element to the current head of the chain
  data->setNext(table[index]);
  //make the current element the data point in the array
  table[index] = data;
  //if the chain has a length less than or equal to 3, exit normally
  if(listLen(data) <= 3) {
    return 0;
  }
  //return 1 otherwise
  return 1;
}

void Hash::deleter(int id) {
  //get the index of the element
  int index = Hash::hashFunc((unsigned int)id) % size;
  //delete the element from the chain
  deleteNode(table[index],table[index],NULL, id);
}

//for every single element in the array, print the entire chain
void Hash::print() {
  for(int i = 0; i < size; i++) {
    printNodes(table[i]);
  }
  return;
}

//take every element of all chains and add it to the new hash table by looping through the entire table
void Hash::copy(Hash* hash) {
  for(int i = 0; i < size; i++) {
    for(Node* loop = table[i]; loop != NULL; loop = loop->getNext()) {
      hash->add(loop);
    }
  }
  return;
}

/*
void Hash::randAdd(int repeats) {
  return;
  }*/

//using the function from: https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
unsigned int Hash::hashFunc(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

//destructor
Hash::~Hash() {
  delete[] table;
}
//prints nodes in a linked list with sstudents
void printNodes(Node* head) {
  //the the head pointer is null, exit the function
  if(head == NULL) {
    return;
  }
  //formatting code
  cout << fixed;
  cout << endl;
  //prints out the various aspects of the student
  Student* printer = head->getStudent();
  cout << "Name:\t" << printer->firstName << " " << printer->lastName << endl;
  cout << "id:  \t" << printer->id << endl;
  cout << "GPA: \t" << setprecision(2) << printer->GPA << endl;
  cout << endl;
  //if the next node exists, do this function to print it out using recursion
  if(head->getNext() != NULL) {
    printNodes(head->getNext());
  }
  return;
}

int listLen(Node* head) {
  int len = 0;
  while(head != NULL) {
    len++;
    head = head->getNext();
  }
  return len;
}

void deleteNode(Node* &head, Node* current, Node* previous, int id) {
  //checks for invalid input
  if(head == NULL || current == NULL) {
    cout << "Either there are no student records, or a valid id wasn't entered." << endl;
    return;
  }
  //checks if the node has the right id
  if(current->getStudent()->id == id) {
    //if the node isn't the first element in the array
    if(previous != NULL) {
      //set the previous nodes next to the node after the one being deleted
      previous->setNext(current->getNext());
      //cout << "Clause 1." << endl;
      //delete the current node and the object it was assigned to.
      delete head;
      
    }
    //if the element is the first node
    else {
      //set the head pointer to the second node
      head = head->getNext();
      //cout << "Clause 2." << endl;
      //delete the current node, but not the head pointer
      delete current;
      
    }
    return;
  }
  //if the element does not have the right id
  else {
    //do the function again for the next node
    Node* nhead = head->getNext();
    deleteNode(nhead, current->getNext(), current, id);
    //cout << "Clause 3." << endl;
    return;
  }
}
