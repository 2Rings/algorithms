#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

int main(){
  vector<string> vec1 = {"a", "123", "b", "234", "c", "345"};
  vector<string> vec2 = {"a", "c"};
  vector<string> res;
  map<string, string> mp;
  unordered_set<string> se;
  for(int i=0;i<vec1.size()-1;i=i+2){
    mp[vec1[i]]=vec1[i+1];
  }
  for(auto v:vec2){
    se.insert(v);
  }

  for(auto m:mp){
    if(se.find(m.first)!=se.end())
      res.push_back(m.first+" "+m.second+" "+"Y");
    else
      res.push_back(m.first+" "+m.second+" "+"N");

  }
  for(auto v:res)
    cout<<v<<endl;
  return 0;
}
