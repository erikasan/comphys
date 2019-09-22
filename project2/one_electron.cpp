#include <iostream>
#include <cmath>
#include <armadillo>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

int main()
{

  unsigned int n;
  cin >> n;

  double rho_min = 0, rho_max = 10;
  double h = (double) (rho_max - rho_min)/(n + 2);

  Mat<double> A(n, n);
  Mat<double> P(n, n);
  Col<double> u(n);

  Col<double> rho = linspace<Col<double>>(rho_min + h, rho_max - h, n);
  Col<double> V = pow(rho, 2);

  double h2 = h*h;
  double e = -1/h2;

  A = diagmat(2/h2 + V);

  A(0, 1) = e; A(n-1, n-2) = e;
  for (int i = 1; i != n-1; ++i) {
    A(i, i-1) = e;
    A(i, i+1) = e;
  }

  A(0, 0) = 10; A(0, 1) = 2;
  A(1, 0) = 2; A(1, 1) = 10;

  jacobi_eigensolver(n, A, P);

  cout << P << endl;


  return 0;
}
