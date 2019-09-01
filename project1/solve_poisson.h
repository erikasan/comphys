/*
Solves the one-dimensional Poisson equation u''(x) = -f(x)
on the interval [x0, X] with Dirichlet boundary conditions
u(x0) = u(X) = 0 and stepsize h = (X - x0)/(n + 1)
as an n x n tridiagonal matrix equation Av=y using
forward and backward substitution

Note that f must be of size n+2
*/

#include "tridgausselim.h"


double* solve_poisson(double* f, int x0, int X, unsigned int n)
{

  double h = (X - x0)/(n + 1);      // Stepsize

  double *d = new double[n],        // Define arrays that will hold
  *a = new double[n-1],             // the diagonal matrix elements
  *b = new double[n-1];

  double *u = new double[n+2];      // Define array that will
                                    // contain the solution
                                    // to the differential equation
  /*
  u[0] = 0; u[n+1] = 0;             // Dirichlet boundary conditions
                                    // Note that u[0] = u[n+1] by default
  */

  double *y = new double[n];        // Define array to hold the right-hand
                                    // side of the matrix equation

  double hsquared = h*h;
  for (int i = 0; i != n; ++i) {    // Fill arrays with matrix elements
    y[i] = -hsquared*f[i+1];
    d[i] = -2;
  }

  for (int i = 0; i != n-1; ++i) {
    a[i] = 1;
    b[i] = 1;
  }

  double *v = tridgausselim(n, y, d, a, b);

  for (int i = 0; i != n; ++i) {
    u[i+1] = v[i];
  }

  return u;
}
