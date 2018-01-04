#include <iostream>
#include <random>

using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int d):data(d),next(nullptr){}
};

void printList(Node* head){
  while(head){
    cout<<head->data<<"--->";
    head = head->next;
  }
  cout<<"nullptr"<<endl;
}
void insert(Node* & head, int data){
  Node * newNode = new Node(data);
  if(head == nullptr){
    head = newNode;
  }
  else{
    Node* curr = head;
    while(curr->next){
      curr = curr->next;
    }
    curr->next = newNode;
  }
}
void delete_node(Node* node){
  if(node == nullptr || node->next == nullptr)
    return;

  Node* nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}

Node* partition_1(Node* head,int v){
  Node* res=new Node(0);
  Node* tmp = res;
  Node* cp = head;
  while(cp){
    if(cp->data<v){
      Node* next = cp->next;
      Node* t;
      t->data = cp->data;
      t->next = nullptr;
      tmp->next = t;
      delete_node(cp);
      cp = next;
      tmp = tmp->next;
    }
  }

  tmp->next = head;

  return res;

}

Node* partition(Node* listhead, int x){
  Node* head = nullptr;
  Node* tail = nullptr;
  Node* headInit = nullptr;
  Node* tailInit = nullptr;
  Node* curr = listhead;
  while(curr!= nullptr){
    Node* nextNode = curr->next;
    if(curr->data < x){
      if(head == nullptr){
        head = curr;
        headInit = head;
      }
      head->next = curr;
      head = curr;
    }
    else{
      if(tail == nullptr){
        tail = curr;
        tailInit = tail;
      }
      tail->next = curr;
      tail = curr;
    }
    curr = nextNode;
  }

  head->next = tailInit;
  tail->next = nullptr;
  return headInit;
}

int main() {
  Node * head = nullptr;
  for ( int i = 0; i < 10; ++i ) {
		insert(head, rand() % 9);
	}
  std::cout << "List before partition around 5:\n";
  printList(head);
  std::cout << "List after partition around 5:\n";
  printList(partition_1(head, 5));
  return 0;
}
