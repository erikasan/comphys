#include <iostream>
#include <armadillo>
#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

int main()
{

  int N = 100;
  int n = N - 1;
  double h2 = (double) 1/(N*N);
  double d = 2/h2, a = -1/h2;

  vec row = zeros<vec>(n);
  row(0) = d; row(1) = a;

  mat A = toeplitz(row, row);
  mat P(n, n);

  jacobi_eigensolver(n, A, P);

  vec eigvals = sort(diagvec(A));

  for (int i = 0; i != 3; ++i) {
    cout << "Lambda #" << i+1 << " = " << eigvals(i) << endl;
  }




  return 0;
}
