#include<iostream>
#include<vector>

using namespace std;

// int find_pivot(vector<int>&  nums){
//   int le = 0, ri = nums.size()-1;
//   int mid = 0;
//   while(le<=ri){
//     mid = le + ((ri-le)>>1);
//     if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1]){
//       return mid;
//     }
//     else if(nums[mid]<nums[mid+1]&&nums[mid]>nums[mid-1])
//       ri = mid - 1;
//     else
//       le = mid + 1;
//   }
// }
int find_pivot_2(vector<int>&  nums){
  if(nums.size()==1)
    return nums[0];
  if(nums.size()==2)
    return nums[0]>nums[1] ? nums[1] : nums[0];
  int le = 0, ri = nums.size()-1;
  int mid = 0;
  while(le<ri){
    mid = le + ((ri-le)>>1);
    if(nums[mid]<nums[mid+1])
      ri = mid;
    else
      le = mid+1;
  }
  return le;
}

bool find_target_a(vector<int>& nums, int target, int le, int ri){
  if(nums.size()==0)
    return false;
  while(le<=ri){
    int mid = le + ((ri-le)>>1);
    if(nums[mid]>=target)
      ri = mid-1;
    else
      le = mid+1;
  }
  if(le<nums.size()&&nums[le]==target)
    return true;
  else
    return false;
}

bool find_target_d(vector<int>& nums, int target, int le, int ri){
  if(nums.size()==0)
    return false;
  while(le<=ri){
    int mid = le + ((ri-le)>>1);
    if(nums[mid]>=target)
      le = mid+1;
    else
      ri = mid-1;
  }
  if(ri>0&&nums[ri]==target)
    return true;
  else
    return false;
}

int main(){
  // vector<int> nums = {3,2,1,3,5,6,7};
  int target= 4;
  vector<int> nums = {7,6,5,4,3,2,1,3,5,6,7,9,10,11,12};
  int idx = find_pivot_2(nums);
  bool res = find_target_d(nums, target, 0, idx)||find_target_a(nums,target, idx, nums.size());
  cout<<idx<<" "<<nums[idx]<<endl;
  if(res)
    cout<<1<<endl;
  else
    cout<<-1<<endl;

  return 0;
}
