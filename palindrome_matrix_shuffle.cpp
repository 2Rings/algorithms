#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isPalindromeMatrix(vector<vector<int>> & matrix){
  int m = matrix.size();
  int n = matrix[0].size();
  unordered_map<int, int> mp;
  for(int i=0;i<m;++i)
    for(int j=0; j<n;++j){
      mp[matrix[i][j]]++;
    }
  int cnt=0;
  int block = (m/2) * (n/2);
  bool flag=true;
  bool odd = false;
  if(m%2==1&&n%2==1)
    flag = false;
  if(n%2==1||m%2==1)
    odd = true;
  for(auto m:mp){
    if(m.second%2==1){
      if(flag)
        return false;
      else
        flag = true;
    }
    while(m.second>=4){
      m.second-=4;
      cnt++;
    }
    if(cnt==block){
      break;
    }
  }
  if(odd){
    for(auto m:mp){
      if(m.second%2==1){
        if(flag)
          return false;
        else
          flag = true;
      }
    }
  }
  return true;
}

int main(){
  vector<vector<int>> matrix(10, vector<int>(10));
  vector<vector<int>> matrix_2={ {2,2,2,2,2},{2,2,2,2,2},{3,3,3,3,3},{3,3,3,3,3}};
  for(int i=0;i<10;++i){
    for(int j = 0;j<10;++j){
      matrix[i][j] = i+j;
    }
  }

  bool res = isPalindromeMatrix(matrix_2);
  if(res)
    cout<<1<<endl;
  else
    cout<<-1<<endl;

  return 0;
}
