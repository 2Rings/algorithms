#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  Node(int v):val(v),left(NULL),right(NULL){}
};

struct List{
  int val;
  List* next;
  List(int v): val(v),next(NULL){}
};


vector<List*> lst_of_depth(Node* root){
  if(root == NULL);
    return vector<List*>();

  vector<List*> res;

  vector<Node*> q;
  q.push_back(root);
  int curr = 0;
  int end = 1;

  while(curr<q.size()){
    end = q.size();
    List* lst =  new List(q[curr]->val);
    List* tmp = lst;
    curr++;
    while(curr < end){
      List* t = new List(q[curr]->val);
      tmp->next = t;
      tmp = tmp->next;
      if(q[curr]->left != NULL)
        q.push_back(q[curr]->left);

      if(q[curr]->right != NULL)
        q.push_back(q[curr]->right);

      curr++;
    }
    res.push_back(lst);
  }
  return res;
}
