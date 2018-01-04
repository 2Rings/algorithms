#include<iostream>
#include<vector>

using namespace std;


//mergesort start:
void merge(vector<int>& nums, vector<int>& helper, int left, int mid, int right){
  for(int i = left; i<=right; ++i){
    helper[i] = nums[i];
  }

  int helper_left = left;
  int helper_right = right;
  int current = left;

  while(helper_left <= mid && helper_right <= right){
    if(helper[helper_left] <= helper[helper_right])
      nums[current++] = helper[helper_left++];
    else
      nums[current++] = helper[helper_right++];
  }

  while(helper_left<=mid){
    nums[current++] = helper[helper_left++];
  }
}
void mergesort(vector<int>& nums, vector<int>& helper, int left, int right){
  if(left < right){
    int mid = left + ((right - left) >> 1);
    mergesort(nums, helper, left, mid);
    mergesort(nums, helper, mid + 1, right);
    merge(nums, helper, left, mid, right);
  }
}
void mergesort(vector<int> & nums){
  vector<int> helper(nums.size());
  mergesort(nums, helper, 0 , nums.size() - 1);
}

//mergesort end

//Insertion sort_list
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* sort_list(ListNode* head){
  ListNode* new_head = new ListNode(0);
  new_head->next = head;
  ListNode* pre = new_head;
  ListNode* cur = head;
  while(cur){
    if(cur->next && cur->next->val < cur->val){
      while(pre -> next && pre->next->val < cur->next->val)
        pre = pre->next;
      ListNode* temp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = temp;
    }
    else cur = cur->next;
  }
  ListNode* res = new_head->next;
  delete new_head;
  return res;
}
//sort_list end
int main(){
  vector<int> nums = {0,2,1};
  mergesort(nums);
  for(auto n:nums){
    cout<<n;
  }
}
