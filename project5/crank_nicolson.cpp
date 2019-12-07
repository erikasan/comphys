#include <iostream>
#include <armadillo>

#include "sym_tridiag_solver.cpp"

using namespace std;
using namespace arma;

void diffusion_CN(mat &u, int N, int n, double T, vec v, rowvec w, rowvec z, bool save);

int main()
{

  int N = 100;
  int n = 100;

  double T = 0.4;

  mat u(N, n); vec v(N); rowvec w(n);

  diffusion_CN(u, N, n, T, v.zeros(), w.zeros(), w.ones(), 1);

  cout << "Done!" << endl;

  return 0;
}

void diffusion_CN(mat &u, int N, int n, double T, vec v, rowvec w, rowvec z, bool save = 0)
{
  double dx    = (double) 1/(N - 1);
  double dt    = (double) T/(n - 1);
  double alpha =         dt/(dx*dx);

  u.zeros();

  u(span::all, 0)     = v;
  u(0, span::all)     = w;
  u(N - 1, span::all) = z;

  vec V(N);
  vec Vtilde = u(span::all, 0);

  double d = 2*(1 - alpha);

  for (int j = 1; j < n; ++j) {
    V = u(span::all, j - 1);
    for (int i = 1; i < N - 1; ++i) {
      Vtilde(i) = alpha*(V(i+1) + V(i-1)) + d*V(i);
    }

    sym_tridiag_solver(V, Vtilde, N, -alpha, 2*(1 + alpha));
    u(span::all, j) = V;
  }

  if (save) { u.save("data.dat", raw_ascii) ;}

  return;
}
