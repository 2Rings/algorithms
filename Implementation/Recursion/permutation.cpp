#include<iostream>
#include<vector>

using namespace std;

//numbers
void helper(vector<vector<int>>& res, vector<int>& nums, int begin){

      if(begin == nums.size()){
          res.push_back(nums);
          return;
      }

      for(int i = begin; i< nums.size(); ++i){
          swap(nums[begin], nums[i]);
          helper(res, nums, begin + 1);
          swap(nums[begin], nums[i]);
      }
  }
vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      helper(res, nums, 0);
      return res;
  }

//string
void helper(vector<string>& res, string str, int begin){

  if(begin == str.size()){
    res.push_back(str);
    return;
  }

  for(int i = begin; i< str.size(); ++i){
    swap(str[begin], str[i]);
    helper(res, str, begin + 1);
    swap(str[begin], str[i]);
  }
}

vector<string> permute(string str){
  vector<string> res;
  helper(res, str, 0);
  return res;
}

int main(){
  // vector<int>  test_case = {1,2,3,4,5,6};
  string test_case1 = "str";
  // vector<vector<int>> res = permute(test_case);
  vector<string> res = permute(test_case1);
  for(auto i: res){
    cout<<"res = [";
    for(auto j : i){
      cout<<j<<",";
    }
    cout<<"]"<<endl;
  }


  return 0;
}
