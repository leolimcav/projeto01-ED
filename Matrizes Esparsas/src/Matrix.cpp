/*
 *  Aluno: Leonardo Lima Cavalcante
 *  Matricula: 427665
*/

#include <iostream>
#include <string>
#include "../include/Matrix.h"

using namespace std;

struct Node
{
  Node *right;
  Node *down;
  int line;
  int column;
  double value;
};

Matrix::Matrix()
{
  head = new (std::nothrow) Node();
  head->right = head;
  head->down = head;
  head->line = -1;
  head->column = -1;
  head->value = 0;
}

void Matrix::print()
{
  cout << "Printando" << head->value << endl;
}
