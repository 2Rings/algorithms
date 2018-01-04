#include<iostream>
#include<vector>
#include<string>
using namespace std;

void helper(vector<vector<int>> &res, vector<int>& co, vector<int>& coin, int n, int pt){
  if(pt == 4){
    co.push_back(n);
    res.push_back(co);
    co.pop_back();
    return;
  }

  if(n == 0){
    res.push_back(co);
    return;
  }


  for(int i = 0; coin[pt]*i <= n; ++i){
    co.push_back(i);
    helper(res, co, coin, n-i*coin[pt], pt + 1);
    co.pop_back();
  }


}

vector<vector<int>> coin_combination(int n){
  vector<int> coin = {25, 10 , 5, 1};
  vector<vector<int>> res;
  vector<int> co;
  helper(res, co, coin, n, 0);
  return res;
}


int main(){
  int test = 30;
  vector<vector<int>> res = coin_combination(test);
  for(auto i: res){
    cout<<"res = [";
    for(auto j : i){
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }
  string s1 = ".";
  string str(4,'.');
  cout<<str<<endl;
  return 0;
}
