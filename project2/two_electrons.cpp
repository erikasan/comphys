#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <armadillo>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;


int main()
{
  double omega_r; bool coloumb;

  cout << "omega_r = ";
  cin >> omega_r;

  cout << "Include Coloumb interaction?" << endl
  << "Yes = 1 No = 0" << endl
  << "Answer: ";
  cin >> coloumb;

  int n = 300;
  double rho_min = 0, rho_max = 5;
  double h = (double) (rho_max - rho_min)/(n + 1);

  mat A(n, n);
  mat P(n, n);

  vec rho = linspace<vec>(rho_min + h, rho_max - h, n);

  vec V;
  if (coloumb) {
    V = pow(omega_r*rho, 2) + 1/rho;
  }
  else {
    V = pow(omega_r*rho, 2);
  }

  double h2 = h*h;
  double e = -1/h2;

  A = diagmat(2/h2 + V);

  A(0, 1) = e; A(n-1, n-2) = e;
  for (int i = 1; i != n-1; ++i) {
    A(i, i-1) = e;
    A(i, i+1) = e;
  }

  jacobi_eigensolver(n, A, P);
  vec eigvals = diagvec(A);

  char o[20];
  sprintf(o, "%.2f", omega_r);
  P.save("eigstates-o=" + (string) o
  + "-c=" + to_string(coloumb) + ".dat", raw_ascii);

  eigvals.save("eigvals-o=" + (string) o
  + "-c=" + to_string(coloumb) + ".dat", raw_ascii);


  cout << "Done!" << endl;
  return 0;
}
