#include<iostream>
#include<vector>
using namespace std;


void hel(vector<vector<int>>& res, vector<int>& A, vector<int> vec,int idx){
  res.push_back(vec);
  if( idx == A.size()){
    return;
  }

  for(int i = idx; i< A.size();++i){
    vec.push_back(A[i]);
    hel(res, A, vec, i + 1);
    vec.pop_back();
  }
}

vector<vector<int>> subset(vector<int>& A){
  vector<vector<int>> res;

  for(int i = 0; i < A.size(); ++i){
    vector<int> vec;
    vec.push_back(A[i]);
    hel(res, A, vec, i+1);
  }
  return res;
}



int main(){
  vector<int> test_case = {1,2,3,4,5,6};
  vector<vector<int>> res = subset(test_case);
  for(auto i: res){
    cout<<"res = [";
    for(auto j : i){
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }
  return 0;
}
