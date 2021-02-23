#include <iostream>
#include "../include/Matrix.h"

using namespace std;

int main()
{
  Matrix *matriz = new (std::nothrow) Matrix();

  if (matriz != nullptr)
    matriz->print();
  cout << "Matriz criada com sucesso!" << endl;
}
