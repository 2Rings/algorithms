#include <iostream>
#include <vector>

using namespace std;

vector<int> binary_to_integer(string s){
    vector<int> A = {128,64,32,16,8,4,2,1};

    std::vector<int> ret(3);
    int j = 0;
    for(int i = 0; i<s.length(); ++i){
        if((i+1)%8 == 0){
            ++j;
        }
        ret[j] += s[i]* A[(i+1)%8];
    }
    return ret;
}

int main(){
  string s = "111111111111111111111111";
  std::vector<int> test = binary_to_integer(s);
  for(auto v:test){
    cout<<v<<endl;
  }
}
