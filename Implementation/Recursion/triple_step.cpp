#include <iostream>
#include <vector>
using namespace std;

int triple_step(int n){
  vector<int> step(n+1);
  step[0] = 0;
  step[1] = 1;
  step[2] = 2;
  step[3] = 4;
  for(int i = 4; i<n+1; ++i){
    step[i] = step[i-1] + 2*step[i-2] + 4* step[i-3];
  }
  return step[n];
}

int main(){
  int n=10;
  // cout<<"Please enter the input: "<<endl;
  // cin>>n;
  for(int i = 0; i<n; ++i){
    int res = triple_step(i);
    cout<<"It needs "<<res<<" steps"<<endl;
  }
  return 0;
}
