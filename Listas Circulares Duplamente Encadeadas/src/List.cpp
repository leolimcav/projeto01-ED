#include <iostream>
#include "../include/List.h"

using namespace std;

struct Node
{
  Node *next;
  Node *prev;
  int value;
  ~Node() { cout << "Node with value " << value << " removed!" << endl; }
};

List::List()
{
  head = new Node();
  head->next = head;
  head->prev = head;
  head->value = 77777777;
};

List::~List()
{
  clear();
  delete head;
  cout << "List removed" << endl;
}

void List::clear()
{
  if (head->next != head)
  {
    Node *aux = head->next;
    while (aux != head)
    {
      Node *removeNode = aux;
      aux = aux->next;
      delete removeNode;
    }
    head->next = head;
    head->prev = head;
  }
}

void List::print()
{
  if (empty())
    cout << "[]" << endl;
  else
  {
    Node *aux = head;
    cout << "[";
    while (aux->next != head)
    {
      aux = aux->next;
      cout << aux->value;
      if (aux->next != head)
        cout << ", ";
    }
    cout << "]" << endl;
  }
}

void List::printReverse()
{
  if (empty())
    cout << "[]" << endl;
  else
  {
    Node *aux = head;
    cout << "[";
    while (aux->prev != head)
    {
      aux = aux->prev;
      cout << aux->value;
      if (aux->prev != head)
        cout << ", ";
    }
    cout << "]" << endl;
  }
}

bool List::contains(int key)
{
  if (empty())
    return false;
  else
  {
    Node *aux = head;
    while (aux->next != head)
    {
      aux = aux->next;
      if (aux->value == key)
        return true;
    }
    return false;
  }
}

bool List::empty()
{
  if (head->next == head && head->prev == head)
    return true;
  else
    return false;
}

int List::size()
{
  if (empty())
    return 0;
  else
  {
    Node *aux = head;
    int count = 0;
    while (aux->next != head)
    {
      aux = aux->next;
      count++;
    }
    return count;
  }
}

void List::push_back(int key)
{
  if (empty())
  {
    Node *newNode = new Node();
    newNode->value = key;
    newNode->next = head;
    newNode->prev = head;
    head->next = newNode;
    head->prev = newNode;
  }
  else
  {
    Node *newNode = new Node();
    newNode->value = key;
    Node *aux = head->prev;
    newNode->next = head;
    newNode->prev = aux;
    aux->next = newNode;
    head->prev = newNode;
  }
}

void List::push_front(int key)
{
  if (empty())
  {
    Node *newNode = new Node();
    newNode->value = key;
    newNode->next = head;
    newNode->prev = head;
    head->next = newNode;
    head->prev = newNode;
  }
  else
  {
    Node *newNode = new Node();
    newNode->value = key;
    Node *aux = head->next;
    head->next = newNode;
    newNode->next = aux;
    newNode->prev = head;
    aux->prev = newNode;
  }
}

int List::pop_back() {}

int List::pop_front() {}

void List::insertAfter(int key, int k) {}

void List::remove(int key) {}

void List::removeAll(int key) {}

void List::concat(List *lst) {}

List *List::copy() {}

void List::copyArray(int n, int arr[]) {}

bool List::equal(List *lst) {}
