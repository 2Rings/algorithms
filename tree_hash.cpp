#include<iostream>
#include<vector>
#include<pair>
#include<unordered_map>
#include<unordered_set>

struct TreeNode {
  TreeNode* pa;
  int id;
  TreeNode(x):id(x),pa(NULL){}
};

class Solution {
public:
  //找父母
  TreeNode* parent(TreeNode* node){
    if(node->pa)
      return node->pa->id;
    else return node->id;
  }
  // 同父母
  bool sharepa(TreeNode* node1, TreeNode* node2){
    if(node1->pa==NULL||node2->pa==NULL)
      return false;
    return node1->pa->id==node2->pa->id;
  }
//判断叔叔
  bool isUncle(TreeNode* node1, TreeNode* node2){
    if(node1->pa==NULL||node1->pa->pa==NULL||node2->pa==NULL)
      return false;
    return node1->pa->pa->id==node2->pa->id;
  }
}

int main(){
  //假设数据是vector<pair<int,int>>
  vector<pair<int,int>> data={(1,2),(1,3),(1,4),(2,5),(3,6),(4,7)};
  //接下来想把数据存在hashmap<int,set>中。
  unordered_map<int,set<TreeNode*>> mp;
  for(auto ele:data){
    TreeNode* par= new TreeNode(ele->first);
    TreeNode* ch = new TreeNode(ele->second);
    ch->pa=par;
    mp[ele->first].insert(ch);
  }
  // todo
  //怎么调用函数。 输入数据处理需要放到solution class里面吗？
  //怎么让这个程序work起来？


}
