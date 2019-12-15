#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

void diffusion_FE2D(cube &u, int N, int n, double T, mat v, rowvec q, vec r, rowvec s, vec t, bool save);
double f(double x, double y);

int main()
{

  int N = 101;
  int n = 8000;
  double T = 0.2;

  cube   u(N, N, n);
  mat       v(N, N);
  rowvec q(N), s(N);
  vec    r(N), t(N);

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {
    v(i, j) = f((double) i/(N - 1), (double) j/(N - 1));
  }}

  diffusion_FE2D(u, N, n, T,
                 v, q.zeros(), r.zeros(), s.zeros(), t.zeros(), 1);

  cout << "Done!" << endl;

  return 0;
}

double f(double x, double y)
{
  double pi = 4*atan(1);
  return sin(pi*x)*sin(pi*y);
}

void diffusion_FE2D(cube &u, int N, int n, double T, mat v, rowvec q, vec r, rowvec s, vec t, bool save = 1)
{
  /*

  Solves the two-dimensional diffusion equation
  on the interval 0 <= x <= 1, 0 <= y <= 1 for t >= 0
  using Forward Euler

  cube u   : N x N x n
  int  N   : # of grid points in x & y directions
  int  n   : # of time steps
  double T : Simulation time
  mat  v   : N x N, Initial condition u(x, y, t=0)
  vec  q   : Boundary condition u(x=0, y, t)
  vec  r   : Boundary condition u(x, y=0, t)
  vec  s   : Boundary condition u(x=1, y, t)
  vec  t   : Boundary condition u(x, y=1, t)

  */

  double h     = (double) 1/(N - 1);
  double dt    = (double) T/(n - 1);
  double alpha =         dt/( h*h );

  u.slice(0) = v;

  for (int k = 0; k < n; ++k) {

    u.slice(k)(0, span::all)     = q;
    u.slice(k)(span::all, 0)     = r;
    u.slice(k)(N - 1, span::all) = s;
    u.slice(k)(span::all, N - 1) = t;

  }

  for (int k = 0; k < n - 1; ++k) {
  for (int j = 1; j < N - 1; ++j) {
  for (int i = 1; i < N - 1; ++i) {

    u(i,j,k+1) = u(i,j,k) + alpha*(u(i+1,j,k)
                          + u(i-1,j,k) + u(i,j+1,k)
                          + u(i,j-1,k) - 4*u(i,j,k));

  }}}

  if (save) { u.save("data2d.dat", raw_ascii) ;}

  return;
}
