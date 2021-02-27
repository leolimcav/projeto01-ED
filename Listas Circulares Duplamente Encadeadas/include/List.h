#ifndef LISTCIRC_H
#define LISTCIRC_H

struct Node;

class List
{
public:
  // Constructor: creates a circular doubly linked list with a head node.
  List();

  // Destructor: free all allocated memory
  ~List();

  // contains: returns true if the list contains a node with value equals to x.
  // returns false if can't find the value.
  bool contains(int key);

  // empty: returns true if the list is empty.
  // returns false if there is any node in the list.
  bool empty();

  // size: returns the amount of nodes in the list.
  int size();

  // clear: remove all nodes of the list and leaves the head node.
  void clear();

  // push_back: insert an node in the end of the list.
  void push_back(int key);

  // push_front: insert an node in the beginning of the list.
  void push_front(int key);

  // pop_front: remove an node in the beginning of the list.
  // return the value of the removed node.
  // if there is no removed node returns INT_MIN.
  int pop_front();

  // pop_back: remove o elemento que esta no final da lista
  // retorna o valor do no caso ele exista;
  // ou retorna INT_MIN caso não exista ultimo elemento
  int pop_back();

  // insertAfter: insert a node after the k-th node of the list.
  void insertAfter(int key, int k);

  // remove: remove the first node with value equals to key.
  void remove(int key);

  // removeAll: removes all the nodes with values equals to key.
  void removeAll(int key);

  // print: print the nodes of the list.
  void print();

  // printReverse: print the nodes of the list in reverse.
  void printReverse();

  // concat: concatenate the current list with the list passed by parameter
  // and leave the lst with only the head node.
  void concat(List *lst);

  // copy: returns a pointer the a copy of the list.
  List *copy();

  // copyArray: copy the elements of the array and add to the end of the list.
  // the array has 'n' elements.
  void copyArray(int n, int arr[]);

  // equal: check if the list passed by parameter is equal to the current list.
  // equal lists has the same number of nodes and the k-th node of one
  // list is equal to the k-th node of the other list.
  bool equal(List *lst);

private:
  // Pointer to the list head node.
  Node *head;
};

#endif
