#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"

class Hash {
 public:
  Hash();
  Hash(int sizeN);
  ~Hash();
  bool add(Node* data);
  void deleter(int);
  void print();
  void copy(Hash* hash);
  Node* *table;
  int size;
  void randAdd(int repeats);
private:
  unsigned int hashFunc(unsigned int id);
};
