#include <iostream>
#include <cstdlib>

class FixedMultiStack{
public:
  FixedMultiStack(int stackCpacity);
  virtual ~FixedMultiStack();

  //push
  void push(int stackNum, int value);

  //pop
  void pop(int stackNum);

  //top
  int top(int stackNum) const;
  //const 修饰的成员函数，能访问对象const成员，但不能修改，其他成员函数不能这样。
  //限制了对const 对象的使用

  bool isEmpty(int stackNum) const;
  bool isFull(int stackNum) const;

private:
  int numOfStack = 3;
  int stackCpacity;
  int *stackArray;
  int *stackCpacityUsed;
  int indexOfTop(int stackNum) const;
};
