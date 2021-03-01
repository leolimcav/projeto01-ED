/*
 *  Aluno: Leonardo Lima Cavalcante
 *  Matricula: 427665
*/

#include <iostream>
#include <climits>
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
  head = new (std::nothrow) Node();
  head->value = 77777777;
  head->next = head;
  head->prev = head;
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
    Node *newNode = new (std::nothrow) Node();
    newNode->value = key;
    newNode->next = head;
    newNode->prev = head;
    head->next = newNode;
    head->prev = newNode;
  }
  else
  {
    Node *newNode = new (std::nothrow) Node();
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
    Node *newNode = new (std::nothrow) Node();
    newNode->value = key;
    newNode->next = head;
    newNode->prev = head;
    head->next = newNode;
    head->prev = newNode;
  }
  else
  {
    Node *newNode = new (std::nothrow) Node();
    newNode->value = key;
    Node *aux = head->next;
    head->next = newNode;
    newNode->next = aux;
    newNode->prev = head;
    aux->prev = newNode;
  }
}

int List::pop_back()
{
  if (empty())
    return INT_MIN;
  else
  {
    Node *removeNode = head->prev;
    Node *aux = removeNode->prev;
    int value = removeNode->value;

    head->prev = aux;
    aux->next = head;
    delete removeNode;

    return value;
  }
}

int List::pop_front()
{
  if (empty())
    return INT_MIN;
  else
  {
    Node *removeNode = head->next;
    Node *aux = removeNode->next;
    int value = removeNode->value;

    head->next = aux;
    aux->prev = head;
    delete removeNode;

    return value;
  }
}

void List::insertAfter(int key, int k)
{
  if (size() < k)
    return;
  else
  {
    int count = 0;
    Node *aux = head->next;
    while (aux != head)
    {
      if (count == k)
        break;
      aux = aux->next;
      count++;
    }
    Node *nextNode = aux->next;
    Node *newNode = new (std::nothrow) Node();
    newNode->value = key;
    newNode->prev = aux;
    newNode->next = nextNode;
    aux->next = newNode;
    nextNode->prev = newNode;
  }
}

void List::remove(int key)
{
  if (empty())
    return;
  else
  {
    Node *aux = head;
    while (aux->next != head)
    {
      if (aux->next->value == key)
      {
        Node *removeNode = aux->next;
        Node *nextNode = removeNode->next;
        aux->next = nextNode;
        nextNode->prev = aux;

        delete removeNode;
      }
      aux = aux->next;
    }
    return;
  }
}

void List::removeAll(int key)
{
  if (empty())
    return;
  else
  {
    while (contains(key))
      remove(key);
  }
}

void List::concat(List *lst)
{
  if (lst->empty())
    return;
  else
  {
    Node *aux = lst->head;
    while (aux->next != lst->head)
    {
      aux = aux->next;
      push_back(aux->value);
    }
    lst->clear();
  }
}

List *List::copy()
{
  List *newList = new (std::nothrow) List();

  Node *aux = head->next;
  while (aux != head)
  {
    newList->push_back(aux->value);
    aux = aux->next;
  }

  return newList;
}

void List::copyArray(int n, int arr[])
{
  for (int i = 0; i < n; i++)
  {
    push_back(arr[i]);
  }
}

bool List::equal(List *lst)
{
  if (lst->size() != size())
    return false;
  else
  {
    Node *aux = head->next;
    Node *aux2 = lst->head->next;

    while (aux != head && aux2 != lst->head)
    {
      if (aux != aux2)
        return false;
      aux = aux->next;
      aux2 = aux2->next;
    }

    return true;
  }
}
