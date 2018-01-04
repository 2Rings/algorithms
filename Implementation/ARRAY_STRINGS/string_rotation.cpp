/* Approach:
* example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
* lets say s1 = xy ==> wat + erbottle
* similarly s2 = yx ==> erbottle + wat
* Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
* So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
*/

#include <iostream>
#include <string>

using namespace std;

bool isRotation(string &s1, string &s2){
  size_t len1 = s1.length()
  size_t len2 = s2.length()
  if(len1 == 0 || len1 != len2)
    return false;

  string str = s1 + s1;
  if(str.find(s2) != str.end())
    return true;
  else
    return false;
}
