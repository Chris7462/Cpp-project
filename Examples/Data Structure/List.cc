#include "List.h"

using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node* new_node(const int& a){
  Node* ptr = new Node;
  ptr->data = a;
  ptr->next = NULL;
  return ptr;
}

List::List(){
  head = NULL;
  tail = NULL;
}

List::~List(){
  Node *ptr;
  while ( head != NULL ){
    ptr = head->next;
    delete head;
    head = ptr;
  }
}

void List::push_back( const int& a ){
  if ( head == NULL ){
    head = new_node(a);
    tail = head;
  } else {
    tail->next = new_node(a);
    tail = tail->next;
  }
}

void List::push_front( const int& a ){
  if ( head == NULL ){
    head = new_node(a);
    tail = head;
  } else {
    Node* ptr = new_node(a);
    ptr->next = head;
    head = ptr;
  }
}

void List::pop_back(){
  if ( head != NULL ){
    if ( head == tail ){
      delete tail;
      head = NULL;
      tail = NULL;
    } else {
      Node *ptr = head;
      while ( ptr->next != tail ){
        ptr = ptr->next;
      }
      delete tail;
      tail = ptr;
      ptr->next = NULL;
    }
  }
}

void List::pop_front(){
  if ( head != NULL ){
    Node *ptr = head->next;
    delete head;
    head = ptr;
    if ( head == NULL ){ 
      tail = NULL;
    }
  }
}

int List::node_no() const {
  int no = 0;
  Node *ptr = head;
  while ( ptr != NULL ){
    ++no;
    ptr = ptr->next;
  }
  return no;
}

ostream& operator<<( ostream& out, const List& foo ){
  for( Node* ptr = foo.head ; ptr != NULL ; ptr = ptr->next ){
    out << ptr->data << " ";
  }
  return out;
}
