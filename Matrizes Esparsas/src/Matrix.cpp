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
  head = new Node;
  head->right = nullptr;
  head->down = nullptr;
  head->line = 0;
  head->column = 0;
  head->value = 0;
}

void Matrix::print()
{
  cout << "Printando" << head->value << endl;
}
