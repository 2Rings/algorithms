#include<iostream>
#include<vector>
using namespace std;

int main(){
  std::vector<int> v={0,1,2,3,5,7,8};
  int j=0;
  for(int i=0;i<v.size();i=i+2){
    if(v[i]%2==0&&i+1<v.size())
      v[j++]=v[i+1];
    else
      v[j++]=v[i];
  }
  v.resize(j);
  for(auto s:v)
    cout<<s<<endl;

  return 0;

}
