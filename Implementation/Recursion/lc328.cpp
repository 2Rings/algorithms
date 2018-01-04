#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
      if(head == NULL)
          return head;
      ListNode* new_head = new ListNode(0);
      new_head -> next = head;
      ListNode* p = new_head;
      ListNode* q = new_head->next;
      while(q&&q->next){
          //if even
          while(q->next&&!(q->next->val&1)){
              q = q->next;
          }
          if(q->next == NULL) break;
          ListNode* tmp2 = q;
          //now q is the start of odd
          q = q->next;
          while(q->next &&q->next->val&1){
              q= q->next;
          }

          // ListNode* node1 = p->next;
          ListNode* node1 = tmp2->next;
          ListNode* node2 = tmp2;
          ListNode* node3 = q;
          tmp2->next = q->next;
          q->next = p->next;
          p->next = node1;
          //renew
          q = node2;
          p = node3;
      }

      return new_head -> next;
  }
};

int main(){
  Solution sol;
  ListNode* root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(2);
  root->next->next->next = new ListNode(4);
  root->next->next->next->next = new ListNode(5);
  root->next->next->next->next->next = new ListNode(7);
  root->next->next->next->next->next->next = new ListNode(8);
  root->next->next->next->next->next->next->next = new ListNode(9);
  root->next->next->next->next->next->next->next->next = new ListNode(10);


  ListNode* res = sol.oddEvenList(root);
  while(res){
    cout<<res->val<<",";
    res = res -> next;
  }
  return 0;
}
