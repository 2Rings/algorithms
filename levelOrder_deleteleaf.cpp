#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };


class Solution{
public:
   void levelOrder(TreeNode* root){
       vector<int> res;
       vector<TreeNode*> vec;
       vec.push_back(root);
       int curr=0;
       int end=1;
       while(curr<vec.size()){
           end=vec.size();
           while (curr<end) {
               //cout<<vec[curr]->val;
               if(vec[curr]->left!=NULL)
                   vec.push_back(vec[curr]->left);
               if(vec[curr]->right!=NULL)
                   vec.push_back(vec[curr]->right);
               if(vec[curr]->left==NULL&&vec[curr]->right==NULL){
                   //res.push_back(vec[curr]->val);
                   cout<<vec[curr]->val<<endl;
                   vec[curr]= NULL;
               }

               curr++;
           }
       }
      //  return res;
   }

};

int main(){
   TreeNode *root= new TreeNode(3);
   root->left = new TreeNode(1);
   root->left->right = new TreeNode(2);
   root->right=new TreeNode(4);
   root->right->right=new TreeNode(5);
   //vector<int> res=Solution().levelOrder(root);
   Solution().levelOrder(root);
    // cout<<res<<endl;
    return 0;
}
