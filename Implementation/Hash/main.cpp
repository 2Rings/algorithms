#include<iostream>
#include<cstdlib>
#include<string>
#include"hash.h"

using namespace std;

//面试的题目：
//Given: void get_data(int key, int i, double d, string s)

//Write: void get_data2(int key, int i ,double d, string s)

Hash ht;

void get_data2(int key, int i, double d, string s){
  if(!ht.find(key))
    get_data(key, i, d, s);
  else{
    ht.setValue(key, i, d, s);
    get_data(key, i, d, s);
  }
  return;
}
int main(){
  Hash ht;
  //TODO
  //setValue()
  return 0;
}
