#ifndef MATRIX_H
#define MATRIX_H

#include <string>

struct Node;

class Matrix
{
private:
  Node *head;

public:
  // Constructor: Create a new sparse matrix by initializin an empty
  // circular linked list with head node.
  Matrix();

  // Destructor: Releases all allocated memory.
  ~Matrix();

  // readMatrix: This method reads, from a file input, the elements different
  // from zero of a matrix and creates a matrix with the values. The input
  // consists in a pair of L(lines) and C(columns) followed by three values
  // (i, j, value) for the elements different from zero of the matrix.
  // Ex:
  // 4, 4 (LxC)
  // 1, 1, 50,0 (i, j, value)
  // 2, 1, 10.0
  // 2, 3, 20.0
  // 4, 1, -30.0
  // 4, 3, -60.0
  // 4, 4, -5.0
  void readMatrix(std::string filename);

  // print: Prints the values on the stdout, the matrix line by line including
  // zeros.
  void print();

  // insert: Insert a value on the line 'i', column 'j' of the matrix.
  void insert(int i, int j, double value);

  // sum: This method sum two matrices and return a new matrix C as the result.
  Matrix *sum(Matrix *A, Matrix *B);

  // multiply: This method multiplies two matrices and return a new matrix C
  // as the result.
  Matrix *multiply(Matrix *A, Matrix *B);
};

#endif
