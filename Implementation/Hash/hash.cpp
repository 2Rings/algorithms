#include<iostream>
#include<cstdlib>
#include<string>
#include "hash.h"
using namespace std;


//constructor
Hash::Hash(){
  for (int i=0; i<SIZE;++i){
    HashTable[i] = new Value;
    HashTable[i] -> i = INT_MIN;
    HashTable[i] -> d = 0.0;
    HashTable[i] -> s = "Empty";
    HashTable[i] -> next = NULL;
  }
}

int Hash::hash_Function(int key){
  //mod
  int idx=key%SIZE;
  return idx;
}

void Hash::setValue(int key, int i, double d, string s){
  int idx = hash_Function(key);

  if(HashTable[idx] -> s == "Empty"){
    HashTable[idx] -> i = i;
    HashTable[idx] -> d = d;
    HashTable[idx] -> s = s;
  }
  else{
    Value* ptr = HashTable[idx];
    Value* nxt = new Value;
    n -> i = i;
    n -> d = d;
    n -> s = s;
    n -> next = NULL;

    while(ptr -> next != NULL){
      ptr = ptr -> next;
    }

    ptr -> next = nxt;
  }
}

Value getValue(int key){
  int idx = hash_Function(int key);
  return HashTable[idx];
}

bool find(int key, int i, double d, string s){
  int idx = hash_Function(key);

  if(HashTable[idx] -> s ="")
    return false;

    return true;
}
