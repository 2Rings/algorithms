#include "min_stack.h"

Stack::Stack(){
  head = nullptr;
  StackSize = 0;
}

Stack::~Stack(){
  StackNode* discard;
  while(head != nullptr){
    discard = head;
    head = head->next;
    delete discard;
  }
}

void Stack::push(int item){
  if(isEmpty()){
    head = new StackNode(item, nullptr);
    head->minimum = head;
  }
  else if (item <= head->minimum -> data){
    head = new StackNode(item, head);
    head->minimum = head;
  }
  else{
    head = new StackNode(item, head);
    head->minimum = head->next->minimum;
  }
  StackSize++;
}

void Stack::pop(){
  if(StackSize == 0|| head == nullptr)
    return;

  StackNode* discard = head;
  head = head->next;
  delete discard;
  StackSize--;
}

int Stack::top() const{
  if(StackSize == 0|| head == nullptr){
    cout<< "Stack is empty.\n";
    exit(1);
  }
  return head->data;
}

int Stack::getMinimum() const{
  if(StackSize == 0 || head == nullptr){
    cout<< "Stack is empty.\n";
    exit(1);
  }
  return head->minimum->data;
}

bool Stack::isEmpty() const{
  return (StackSize == 0|| head == nullptr);
}

int Stack::getSize() const{
  return StackSize;
}
