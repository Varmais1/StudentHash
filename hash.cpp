#include "hash.h"
using namespace std;

Hash::Hash() {
  table = new Node*[101];
  size = 101;
}

Hash::Hash(int sizeN) {
  table = new Node*[sizeN];
  size = sizeN;
}

bool Hash::add(Node* data) {
  return false;
}

void Hash::deleter(Node* data) {
  return;
}

void Hash::print() {
  return;
}

void Hash::copy(Hash &hash) {
  return;
}

void Hash::randAdd(int repeats) {
  return;
}

//using the function from: https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
unsigned int hash(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

Hash::~Hash() {
  delete[] table;
}
