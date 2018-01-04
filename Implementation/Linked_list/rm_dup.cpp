#include <iostream>
#include <unoredered_map>
#include <random>

struct Node {
  int data = 0;
  Node* next = nullptr;
};

void insert(Node* &head, int data){
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}
//algo1
//no buffer
void romove_Duplicate(Node* head){
  if(head == nullptr || (head && (head->next == nullptr))){
    return;
  }

  Node* curr = head;
  while(curr){
    Node* runner = curr;
    while(runner->next != nullptr){
      if(runner->next->data == curr->data){
        runner->next = runner->next->next;
      }
      else
        runner = runner->next;
    }
    curr = curr->next;
  }

}

//algo2
//hashtable

void remove_Duplicates_hash(Node* head){
  if(head == nullptr || (head && (head->next == nullptr))){
    return;
  }

  unoredered_map<int,int> node_map;
  Node* prev = head;
  Node* curr = head->next;
  node_map[head->data] = 1;
  while(curr != nullptr){
    while(curr&& node_map.find(curr->data)!= node_map.end()){
      curr = curr->next;
    }
    prev->next = curr;
    prev = curr;
    if(curr){
      node_map[curr->data] = 1;
      curr = curr->next;
    }
  }
}
