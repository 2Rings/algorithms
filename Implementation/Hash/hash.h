#ifndef HASH_H
#define HASH_H

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct Value {
  int i;
  double d;
  string s;
  Value* next;
};

class Hash{
public:
  //basic:
  int hash_Function(int key);
  void setValue(int i, double d, string s);
  bool find(key);
  Hash();
  //addition operation

private:
  static const int SIZE = 10;// 10 buckets
  Value* HashTable[SIZE];
  //each bucket contains a pointer that has the ability to point to some item.
};

#endif //HASH_H
