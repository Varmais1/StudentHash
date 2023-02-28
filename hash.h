#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"

class Hash {
 public:
  //constructors and destructor
  Hash();
  Hash(int sizeN);
  ~Hash();
  //adds an element into the table
  int add(Node* data);
  //deletes an element from the table
  void deleter(int);
  //prints all elements in the table
  void print();
  //copies the current hash table into another hash table
  void copy(Hash* hash);
  //the array which the table stores heads of chains in
  Node* *table;
  //size of table
  int size;
  //void randAdd(int repeats);
private:
  //hash function
  unsigned int hashFunc(unsigned int id);
};
