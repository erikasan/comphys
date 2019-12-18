#include <iostream>
#include <armadillo>

#include "sym_tridiag_solver.cpp"

using namespace std;
using namespace arma;

void diffusion_BE(mat &u, int N, int n, double T, vec v, rowvec w, rowvec z, bool save);

int main()
{
  int N = 101;
  int n = 8001;

  double T = 0.4;

  mat u(N, n); vec v(N); rowvec w(n);

  diffusion_BE(u, N, n, T, v.zeros(), w.zeros(), w.ones(), 1);

  cout << "Done!" << endl;
  return 0;
}

void diffusion_BE(mat &u, int N, int n, double T, vec v, rowvec w, rowvec z, bool save = 0)
{

  double dx    = (double) 1/(N - 1);
  double dt    = (double) T/(n - 1);
  double alpha =         dt/(dx*dx);


  u.zeros();

  u(span::all, 0)     = v;
  u(0, span::all)     = w;
  u(N - 1, span::all) = z;

  vec x(N);

  for (int j = 1; j < n; ++j) {

    sym_tridiag_solver(x, u(span::all, j - 1), N, -alpha, 1 + 2*alpha);
    u(span::all, j) = x;

  }

  if (save) {
    char filename [20];
    sprintf(filename, "BE-N=%d.dat", N);
    u.save(filename, raw_ascii);
  }

  return;
}
