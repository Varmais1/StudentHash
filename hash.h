#include <iostream>
#include <cstring>
#include "node.h"

class Hash {
 public:
  Hash();
  Hash(int sizeN);
  ~Hash();
  bool add(Node* data);
  void deleter(Node* data);
  void print();
  void copy(Hash &hash);
  Node* *table;
  int size;
  unsigned int hashFunc(unsigned int id);
  void randAdd(int repeats);
};
