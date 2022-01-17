// Doubly linked list
// Author : Arun Singh (arunsingh.wave2@gmail.com)

#include <iostream>

using namespace std;

class Node; // initialize later

class List {
private:
  // Doubly Linked list have head and tail info of list
  Node *head, *tail;

public:
  // Start with 0
  List (Node *h = 0): head(h), tail(h) {}
  virtual ~List(){}
  void display();
  void append(Node *a);
};

class Node {
private:
  // Node have 2 section (1. info, 2. address of next node)
  int info;
  Node *next;
  Node *prev;
public:
  // initialize the info for the particular node and set next address 0.
  Node (int i): info(i), next(0), prev(0) {}
  virtual ~Node(){}
  // friend function example
  // display and append member function of List class and now friend of Node class.
  // friend void List::display();
  // friend void List::append(Node *);
  // we can make friend directly to class also
  friend class List;
};

void List::display(){
  Node *ptr = head; // start from head |11|0x12x|
  while(ptr){
    // |11|0x12x|(head contains this address and this is 2nd node address),
    // |22|0x13x|(0x12x)(3rd node address),
    // |33|0| (0x13x) (no address, no next node)
    cout << ptr <<  "    |" << ptr -> prev << "       |" << ptr -> info;
    cout << "         |" << ptr -> next << "|" << endl;
    ptr = ptr -> next;
  }
}

void List::append(Node *new_node){
  if (!head){
    // |0|11|0| (info|address) (0x12x)
    head = tail = new_node; // First node will come in this senario (tail -> next = 0 only)
  }
  else{
    // new_node = 0x13x
    // |0|11|0x13x| (prev node address|info|next node address) first node contains new node address.
    // |0x12x|22|0| (prev node address|info|address) second node have no address.
    new_node -> prev = tail;
    tail -> next = new_node; // rest all node will append here.
    tail = tail -> next;
  }
}

int main(int argc, char const *argv[]) {
  List l;
  Node n1(11), n2(22), n3(33);
  l.append(&n1);
  l.append(&n2);
  l.append(&n3);
  cout << "Current Node Address |" << "Prev Node Address |" << " Node Data |";
  cout << " Next Node Address |" << endl;
  l.display();
  cout << endl;
  return 0;
}

/*
Current Node Address  |Prev Node Address    | Node Data | Next Node Address |
0x7ffee7c97788        |0x0                  |11         |0x7ffee7c97758|
0x7ffee7c97758        |0x7ffee7c97788       |22         |0x7ffee7c97738|
0x7ffee7c97738        |0x7ffee7c97758       |33         |0x0|
*/
