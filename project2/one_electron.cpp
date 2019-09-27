#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

ofstream outfile;

int main()
{

  vec N = regspace(100, 10, 400);
  vec infinity = regspace(10, 5, 80);

  string filename = "lambda=3.dat";
  outfile.open(filename);

  for (auto n : N) {
    for (auto rho_max : infinity) {

      double rho_min = 0;
      double h = (double) (rho_max - rho_min)/(n + 2);

      Mat<double> A(n, n);
      Mat<double> P(n, n);

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

      jacobi_eigensolver(n, A, P);
      vec eigvals = diagvec(A);
      eigvals = sort(eigvals);

      outfile << setw(15) << setprecision(15)
      << eigvals(0) << ' ';
    }
    outfile << endl;
  }
  outfile.close();
  cout << "Done!" << endl;

  return 0;
}
