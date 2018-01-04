#include <iostream>

using namespace std;

struct TreeNode{
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  int val;
  TreeNode(int v):val(v),left(NULL),right(NULL),parent(NULL){}
};

TreeNode* leftMost(TreeNode* root){
  while(root->left != NULL){
    root = root -> left;
  }
  return root;
}

TreeNode* findSuccessor(TreeNode* root){
  if(root -> right != NULL){
    return leftMost(root->right);
  }
  TreeNode* child = root;
  TreeNode* ancester = child -> parent;
  while(ancester != NULL && ancester -> right == child){
    child = ancester;
    ancester = child -> parent;
  }
  return ancester;
}
