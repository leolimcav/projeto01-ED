#include <iostream>
#include "../include/List.h"

using namespace std;

int main()
{
  List *lista = new List();

  lista->push_front(10);
  lista->push_back(20);
  lista->push_front(40);
  lista->push_back(30);

  if (lista->empty())
    cout << "Lista vazia" << endl;
  else
    cout << "Lista possui " << lista->size() << " elemento(s)" << endl;

  cout << "Print normal" << endl;
  lista->print();

  cout << "Print reverso" << endl;
  lista->printReverse();

  if (lista->contains(10))
    cout << "tem" << endl;
  else
    cout << "não tem" << endl;

  lista->clear();
  cout << "Lista possui " << lista->size() << " elemento(s)" << endl;
  lista->print();
  lista->~List();
}
