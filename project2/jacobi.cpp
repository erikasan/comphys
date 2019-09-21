#include <iostream>
#include <cmath>
#include <armadillo>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

int main()
{
  unsigned int n = 3;
  Mat<double> A(n, n);
  Mat<double> S = eye(n, n);
  Col<double> eigvals(n);
  vec row = zeros<vec>(n);
  row(0) = -2; row(1) = 1;
  A = toeplitz(row, row);

  jacobi_eigensolver(n, A, eigvals);

  cout << A << endl;
  cout << endl;
  cout << eigvals << endl;

  return 0;
}
