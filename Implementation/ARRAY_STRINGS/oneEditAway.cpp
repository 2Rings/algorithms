#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool oneEditAway(const string &str1, const string &str2){
  if(abs(str1.length()-str2.length()) > 1)
    return false;

  int len1 = str1.length();
  int len2 = str2.length();
  if(len1 > len2)
    swap(str1,str2);
  bool mismatchDone = false;
  unsigned in i = 0, j=0;
  while( i< str1.length() && j < str2.length()){
    if(str1[i]!=str2[j]){
      if(mismatchDone)
        return false;
      mismatchDone = true;
      if(len1 == len2)
        ++i;
    }
    else
      ++i;
    ++j;
  }
  return true;
}
