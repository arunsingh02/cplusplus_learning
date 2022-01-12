#include <iostream>

using namespace std;

class Node; // initialize later

class List {
private:
  // Linked list have head and tail info of list
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
public:
  // initialize the info for the particular node and set next address 0.
  Node (int i): info(i), next(0) {}
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
    cout << ptr << "       |" << ptr -> info;
    cout << "         |" << ptr -> next << "|" << endl;
    ptr = ptr -> next;
  }
}

void List::append(Node *a){
  if (!head){
    // |11|0| (info|address)
    head = tail = a; // First node will come in this senario (tail -> next = 0 only)
  }
  else{
    // a = 0x12x
    // |11|0x12x| (info|next node address) first node contains new node address.
    // |22|0| (info|address) second node have no address.
    tail -> next = a; // rest all node will append here.
    tail = tail -> next;
  }
}

int main(int argc, char const *argv[]) {
  List l;
  Node n1(11), n2(22), n3(33);
  l.append(&n1);
  l.append(&n2);
  l.append(&n3);
  cout << "Current Node Address |" << " Node Data |" << " Next Node Address |" << endl;
  l.display();
  cout << endl;
  return 0;
}

/*
Current Node Address | Node Data | Next Node Address |
0x7ffee0e84790       |11         |0x7ffee0e84768|
0x7ffee0e84768       |22         |0x7ffee0e84750|
0x7ffee0e84750       |33         |0x0|
*/
