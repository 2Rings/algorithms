#include <iostream>

using namespace std;

struct Node {
  char data;
  Node* next;
  Node(char d): data(d), next(nullptr){}
};


void printList(Node* head){
  while(head){
    cout<<head->data<<"--->";
    head = head->next;
  }
  cout<<"nullptr"<<endl;
}

//TODO
//删除任意node，这是看别人的写的代码，我没搞懂，要删除
//当前node的时候，不需要知道node前面的节点，然后像我在delete_mid中那样连接起来，
//这里是直接把node->next 的data和next重新赋值给node,这是什么原理呢？
//我大概能懂他的意思，就是我不确定这样做的依据。
void delete_node(Node* node){
  if(node == nullptr|| node->next == nullptr)
    return;

  Node* nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}
int find_mid(Node* head){
  Node* slow = head;
  Node* fast = head->next;
  int cnt=0;
  while(fast&&fast->next){
    slow = slow->next;
    fast = fast->next->next;
    ++cnt;
  }
  return cnt;
}

void delete_mid(Node* head){
  if(head == nullptr)
    return;
  int mid = find_mid(head);
  Node* tmp = head;
  if(mid==0)
    head = head->next;

  while(mid>1){
    tmp = tmp->next;
    --mid;
  }

  //TODO
  //释放内存的问题
  //问题？？？跳过了一个node,如何delete掉原来的tmp->next
  tmp->next = tmp->next->next;

}


int main(){
  Node* head = new Node('a');
  head->next = new Node('b');
  head->next->next = new Node('c');
  head->next->next->next = new Node('d');
  head->next->next->next->next = new Node('e');
  cout<<"Deleting node";
  delete_mid(head);
  cout<<"List after deletion:\n";
  printList(head);
  return 0;

}
