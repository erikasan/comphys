/*
Solves the one-dimensional Poisson equation u''(x) = -f(x)
on the interval [x0, X] with Dirichlet boundary conditions
u(x0) = u(X) = 0 and stepsize h = (X - x0)/(n + 1)
as an n x n tridiagonal matrix equation Av=y using
forward and backward substitution

Note that f must be of size n+2
*/

#include "tridgausselim.h"


double* solve_poisson(double* f,
                      int x0,
                      int X,
                      unsigned int n,
                      bool simplify = true)

{
  double h = (double) (X - x0)/(n + 1);     // Stepsize

  double *d = new double[n],                // Define arrays that will hold
         *u = new double[n+2],              // Define array that will
         *y = new double[n],                // contain the solution
         *v = new double[n];                          // to the differential equation

            // Define array to hold the right-hand
                                                                                      // side of the matrix equation
  /*
  u[0] = 0; u[n+1] = 0;                     // Dirichlet boundary conditions
                                            // Note that u[0] = u[n+1] = 0 by default
  */

  double hsquared = h*h;

  if (!simplify) {
    for (int i = 0; i != n; ++i) {          // Fill arrays with matrix elements
      y[i] = -hsquared*f[i+1];
      d[i] = -2;

    }

    double *a = new double[n-1],            // the diagonal matrix elements
           *b = new double[n-1];

    for (int i = 0; i != n-1; ++i) {
      a[i] = 1;
      b[i] = 1;

    }

    v = tridgausselim(n, y, d, a, b);

  }

  else {

    for (int i = 0; i != n; ++i) {            // Fill arrays with matrix elements
      y[i] = -hsquared*f[i+1];

    }

    d[0] = -2;
    for (int i = 1; i != n; ++i) {
      d[i] = -2 - 1/d[i-1];
      y[i] -= y[i-1]/d[i-1];

    }

    v[n-1] = y[n-1]/d[n-1];

    for (int i = n - 2; i >= 0; --i) {
      v[i] = (y[i] - v[i+1])/d[i];

    }

    delete [] d;
    delete [] y;

  }

  for (int i = 0; i != n; ++i) {
    u[i+1] = v[i];
  }

  delete [] v;

  return u;
}
