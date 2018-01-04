#include <iostream>
#include <vector>
// include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int v):val(v),left(NULL),right(NULL){}
};

void preOrder(Node* root){
  if(root == NULL)
    return;

  cout<< root->val <<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root){
  if(root == NULL)
    return;

  preOrder(root->left);
  cout<< root->val <<" ";

  preOrder(root->right);
}

Node* minimal_tree(vector<int>& array, int left, int right){
  if((right - left) < 0)
    return NULL;

  int mid = left + ((right-left)>>1);

  Node* root = new Node(array[mid]);

  root->left = minimal_tree(array, left, mid-1);
  root->right = minimal_tree(array, mid+1, right);

  return root;
}

int main(){
  int A[] = {1,2,3,4,5,6,7};

  vector<int> arr(A,A+sizeof(A)/sizeof(A[0]));
  Node* root = minimal_tree(arr, 0, 6);
  cout<<"\nPreOrder Traversal of constructed BST : ";
  preOrder(root);
  cout<<"\nInOrder Traversal of constructed BST : ";

  inOrder(root);

  return 0;
}
