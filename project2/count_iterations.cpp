#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

#include "jacobi_eigensolver.h"

using namespace std;
using namespace arma;

ofstream outfile;

int main()
{
  vec N = regspace(10, 10, 100);
  string filename = "cnt_iterations.dat";
  outfile.open(filename);
  for (auto n : N) {
    Mat<double> A(n, n);
    Mat<double> P(n, n);

    double rho_min = 0, rho_max = 10;
    double h = (double) (rho_max - rho_min)/(n + 2);

    double h2 = h*h;
    double e = -1/h2;

    Col<double> d = 2/h2*ones(n);
    A = diagmat(d);

    A(0, 1) = e; A(n-1, n-2) = e;
    for (int i = 1; i != n-1; ++i) {
      A(i, i-1) = e;
      A(i, i+1) = e;
    }

    int iterations;
    int *p_iterations = &iterations;

    clock_t start, finish;
    start = clock();
    jacobi_eigensolver(n, A, P, true, p_iterations);
    finish = clock();

    outfile << setw(10) << setprecision(10)
    << n << ' ' << iterations << ' '
    << (double) (finish - start)/CLOCKS_PER_SEC << endl;

  }
  outfile.close();

  return 0;
}
