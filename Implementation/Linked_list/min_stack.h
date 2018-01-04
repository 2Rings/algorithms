#ifndef STACK_H
#define STACK_H

#include "stack_O(1).h"
#include <iostream>
#include <cstdlib>

class Stack{
public:
  Stack();
  virtual ~Stack();
  void push(int item);
  void pop();
  int top() const;
  int getMinimum() const;

  bool isEmpty() const;
  int getSize() const;

private:
  StackNode* head;
  int StackSize;
};

#endif //STACK_H
