#include <iostream>
#include <armadillo>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

int main()
{
  mat A(3, 3);
  A(0, 0) = 5; A(1, 1) = 3; A(2, 2) = 2;
  A(0, 1) = -2; A(1, 0) = A(0, 1);
  A(0, 2) = 4; A(2, 0) = 4;

  cout << A << endl;
  mat P(3, 3);

  jacobi_eigensolver(3, A, P);

  cout << A << endl;
  cout << endl;
  cout << P << endl;
  return 0;
}
