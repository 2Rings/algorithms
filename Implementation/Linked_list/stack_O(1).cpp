#include "stack_O(1).h"

StackNode::StackNode(int data, StackNode* next){
  this->data = data;
  this->next = next;
  minimum = nullptr;
}
