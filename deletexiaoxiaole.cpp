#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  void triplen(std::vector<int>& nums){
    if(nums.size()<3)
      return;
    int slow=0,fast=1,cnt=1,j=0;
    while(slow<nums.size()){
      while(fast<nums.size()&&nums[slow]==nums[fast]){
        fast++;
        cnt++;
      }

      if(cnt<3){
        nums[j++] = nums[slow];
        if(cnt==2){
          if(nums[slow]==nums[slow+1])
            nums[j++] = nums[slow+1];
          else
            nums[j++] = nums[fast-1];
        }
        slow = fast;
        fast++;
        cnt=1;
      }
      else {
        slow = j - 1;
        cnt = 1;
        if(slow-1>=0&&nums[slow]==nums[slow-1]&&fast<nums.size()){
          slow = slow - 1;
          cnt++;
        }
        if(slow <= j){
          j = slow;
        }
        if(slow < 0){
          slow = fast;
          fast++;
          j = 0;
        }

      }
    }
    nums.resize(j);
  }
};


int main(){
  vector<int> nums = {1,1,2,2,1,1,3,3,3,1,2,1,4};
  Solution().triplen(nums);
  for(auto n:nums){
    cout<<n<<" ";
  }
  return 0;
}
