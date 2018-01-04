#include<iostream>
using namespace std;

struct TreeNode {
  TreeNode* pa;
  TreeNode* ch;
  TreeNode* nextsibling;
}

class Solution {
  TreeNode* parent(TreeNode* node){
    if(node->pa!=NULL)
      return node->pa;
    else
      return node;
  }
  TreeNode* gradparent(TreeNode* node){
    if(node->pa)
      return node->pa->pa;
    else return node->pa;
  }
  TreeNode* root(TreeNode* node){
    if(node->pa!=NULL)
      return root(node->pa);
    else
      return node;
  }
  bool isSamePa(TreeNode* node1, TreeNode* node2){
    TreeNode* pa = root(node1);
    TreeNode* pb = root(node2);
    return pa==pb;
  }

  bool isUncle(TreeNode* node1, TreeNode* node2){
    TreeNode* gp1 = gradparent(node1);
    TreeNode* gp2 = gradparent(node2);
    TreeNode* pa1 = parent(node1);
    TreeNode* pa2 = parent(node2);
    return (gp1==pa2&&gp1&&pa2)||(gp2==pa1&&gp2&&pa1)
  }

};
