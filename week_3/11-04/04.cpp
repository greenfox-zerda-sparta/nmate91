//============================================================================
// Name        : 04.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node {
  double data;
  Node* next;
};

Node* list_construct_one(double value);
unsigned int list_length(Node& head);
Node* list_get_last(Node& head);
void list_append(Node& head, double value);
Node* list_at(Node& head, unsigned int index);
void list_insert(Node& head, unsigned int index, double value);
unsigned int list_find(Node& head, double value);
void list_remove(Node& head, double value);
void list_concat(Node& head, Node& other_list);

int main() {
  double a = 1.2;
  Node* my_list = list_construct_one(a);
  cout << "Length: " << list_length(*my_list) << endl;
  list_get_last(*my_list);
  list_append(*my_list, 7.6);
  list_append(*my_list, 6.9);
  list_append(*my_list, 6.1);
  cout << "Length: " << list_length(*my_list) << endl;
  cout << "At: "<< list_at(*my_list, 2) << endl;
  list_insert(*my_list, 2, 3.5);
  cout << "Length: " << list_length(*my_list) << endl;
  cout << "Index of 7.6: " << list_find(*my_list, 7.6) << endl;
  cout << "Index of 6.9: " << list_find(*my_list, 6.9) << endl;
  list_remove(*my_list, 6.9);
  cout << "Length after remove: " << list_length(*my_list) << endl;
  Node* my_list_two = list_construct_one(a);
  list_concat(*my_list, *my_list_two);
  delete my_list;
  delete my_list_two;
  return 0;
}

Node* list_construct_one(double value) {
  Node* new_node = new Node;
  new_node->data = value;
  new_node->next = nullptr;
  return new_node;
}

unsigned int list_length(Node& head) {
  Node* temp = &head;
  unsigned int length = 0;
  do {
    temp = temp->next;
    length++;
  } while (temp != nullptr);
  return length;
}

Node* list_get_last(Node& head) {
  Node* temp = &head;
  Node* last;
  while (temp != nullptr) {
    last = temp;
    temp = temp->next;
  }
  return last;
} // amig nem vezettem be egy last valtozot, nem futott le...why?

void list_append(Node& head, double value) {
  Node* new_node = list_construct_one(value);
  Node* last_node = list_get_last(head);
  last_node->next = new_node;
}

Node* list_at(Node& head, unsigned int index) { //nem igazan mukodik a cout, mert az addresst dobja ki...
  Node* temp = &head;
  for (unsigned int i = 0; i <= index; i++) { //kurvara ledobta az ekszijat itt az indexes logika, ez a legkozelebbi megoldas ami beugrott
    temp = temp->next;
    if (i == index) {
      return temp;
    }
  }
  return temp; //ekkor az utolsoval ter vissza (nullptr)
}

void list_insert(Node& head, unsigned int index, double value) {
  Node* new_node = list_construct_one(value);
  new_node->next = list_at(head, index);
  Node* last_node = list_at(head, index - 1);
  last_node->next = new_node;
}

unsigned int list_find(Node& head, double value) {  //not good enough
  Node* temp = &head;
  unsigned int counter = 0;
  for (; counter < list_length(head); counter++) {
    if (temp->data == value){
      return counter;
    }
  temp = temp->next;
  }
  return counter + 1;
}

void list_remove(Node& head, double value) {
  unsigned int remove_index = list_find(head, value);
  Node* remove_node = list_at(head, remove_index);
  if (remove_node == &head) { //kell mert maskent viselkednek a node-ok
    Node* temp = list_at(head, 1);
    head = *temp;
    delete temp;
    return;
  } else if (list_get_last(head) == remove_node) {
    Node* temp = list_at(head, remove_index - 1);
    temp->next = nullptr;
  } else {
    Node* before_node = list_at(head, remove_index - 1);
    Node* after_node = list_at(head, remove_index + 1);
    before_node->next = after_node;
  }
  delete remove_node;
}

void list_concat(Node& head, Node& other_list) {
  Node* list1_last_node = list_get_last(head);
  list1_last_node->next = &other_list;
}

