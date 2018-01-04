#include "three_in_on.h"

using namespace std;

FixedMultiStack::FixedMultiStack(int stackCpacity){
  this->stackCpacity = stackCpacity;
  stackArray = new int[numOfStack*stackCpacity]();//加(),意味着有初始化
  stackCpacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack(){
  delete [] stackArray;
  delete [] stackCpacityUsed;
}

void FixedMultiStack::push(int stackNum, int value){
  if(isFull(stackNum))
    cout<< "Stack" << stackNum << " is full.\n";
  else{
    stackCpacityUsed[stackNum]++;
    stackArray[indexOfTop(stackNum)] = value;
  }
}

void FixedMultiStack::pop(int stackNum){
  if(isEmpty(stackNum))
    cout<< "Stack" << stackNum << " is empty.\n";
  else{
    int topIndex = indexOfTop(stackNum);
    stackArray[topIndex] = 0;
    stackCpacityUsed[stackNum]--;

  }
}

int FixedMultiStack::top(int stackNum) const{
  if(isEmpty(stackNum)){
    cout<< "stack" << stackNum << " is empty.\n";
    exit(1);
  }
  else
    return stackArray[indexOfTop(stackNum)];

}

bool FixedMultiStack::isEmpty(int stackNum) const{
  return (stackCpacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const{
  return (stackCpacityUsed[stackNum] == stackCpacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const{
  int startIndex = stackNum* stackCpacity;
  int capacity = stackCpacityUsed[stackNum];
  return (startIndex + capacity -1);
}
