#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int d): data(d), next(nullptr){}
};

void removeLoop(Node* loopNode, Node* head){
  Node* ptr1 = head;
  Node* ptr2 = loopNode;
  while(ptr1->next != ptr2->next){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  ptr2->next = nullptr;
}

bool loop_detect(Node* head){
  if(head == nullptr)
    return false;

  Node* fast = head;
  Node* slow = head;

  while(head && head->next){
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow){
      removeLoop(slow, head);
      return true;
    }
  }
  return false;
}

void insert(Node* & head, int data){
  Node* newNode = new Node(data);
  if(head == nullptr){
    head = newNode;
  }
  else{
    Node* tmp = head;
    while(tmp -> next != nullptr){
      tmp = tmp -> next;
    }
    tmp -> next = newNode;
  }
}

void printList( Node * head )
{
  while( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "NULL" << std::endl;
}


int main()
{
    Node * head = nullptr;
    insert( head , 1 );
    insert( head , 2 );
    insert( head , 3 );
    insert( head , 4 );
    insert( head , 5 );
    insert( head , 3 );
    std::cout << "Current List:\n";
    printList( head );
    std::cout << "Inserting loop, connecting 5 to 2 \n";
    head->next->next->next->next->next = head->next;
    std::cout << "Detecting and deleting loop\n";
    loop_detect(head);
    std::cout << "Back to the same old list\n";
    printList( head );
    return 0;
}
