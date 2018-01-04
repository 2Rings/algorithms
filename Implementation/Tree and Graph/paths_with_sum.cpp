#include <iostream>

using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v):val(v), left(NULL), right(NULL){}
};

void dfs(int& res, TreeNode* root, int sum, const int target){
  if(root == NULL)
    return;
  if(root->val == sum){
    res++;
    return;
  }
  dfs(res, root->left, sum - root->val, target);
  dfs(res, root->right, sum - root->val, target);
  sum = target;
  dfs(res, root->left, target, target);
  dfs(res, root->right, target, target);
}

int pathSum(TreeNode* root, int sum){
  int res = 0;
  dfs(res, root, sum, sum);
  return res;
}

int main(){
  TreeNode* head = new TreeNode(1);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(2);
  TreeNode* node5 = new TreeNode(3);
  TreeNode* node6 = new TreeNode(3);

  head->left = node1;
  head->right = node2;
  node1->left = node3;
  node2->right = node4;
  node1->right = node5;
  node2->left = node6;
  int res = pathSum(head,5);
  cout<<"res: "<<res<<endl;
  return 0;
}
