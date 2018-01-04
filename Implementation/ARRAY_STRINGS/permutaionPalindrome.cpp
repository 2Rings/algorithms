// Algo1:
//Count elements, count[i]%2 , flag = true;

//Algo2:
//use oddCount to check element is odd or not(0/1);

//Algo3:

include <iostream>

using namespace std;

int getCharIndex(char c){
  int idx = -1;
  if( c >= 'a' && c <= 'z')
    idx = c - 'a';
  else if( c >= 'A' && c <= 'Z')
    idx = c - 'A';
  return idx;
}
