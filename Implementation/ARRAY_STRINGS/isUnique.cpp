#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//ASCII code: 128
bool isUniqueChars(const string &str){
  if(str.length()>128)
    return false;
  vector<bool> char_set(128);
  for(int i = 0; i<str.length(); ++i){
    int val = str[i];
    if(char_set[val])
      return false;
    char_set[val] = true;
  }
  return true;
}

// bitset : 0 or 1, true or false;
bool isUniqueChars_Bitset(const string &str){
  bitset<256> bits(0);
  for(int i = 0; i < str.length(); ++i){
    int val = str[i];
    if(bits.test(val) > 0){
      return false;
    }
    bits.set(val);
  }
  return true;
}

bool isUniqueChars_noDS( string str){
  sort(str.begin(), str.end());
  bool noRepeat = true;
  for( int i = 0; i < str.size() - 1; ++i){
    if( str[i] == str[i+1]){
      noRepeat = false;
      break;
    }
  }
  return noRepeat;
}

int main(){
  //TODO
  //test
  return 0;
}
