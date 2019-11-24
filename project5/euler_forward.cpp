#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
  double L = 1;
  double N = 100;
  double n = 10000;

  mat u(N, n); u.zeros();
  vec v(N); rowvec w(n);

  double dx = L/(N - 1);
  double dt = dx*dx/2;
  double T  = n*dt;
  double alpha = dt/(dx*dx);
  // Initial condition
  u(span::all, 0) =  v.zeros();

  // Boundary conditions
  u(0, span::all) =  w.zeros(); u(N - 1, span::all) = w.ones();

  for (int j = 1; j < n - 1; ++j) {
  for (int i = 1; i < N - 1; ++i) {

    u(i, j+1) = alpha*(u(i+1, j) + u(i-1, j)) + (1 - 2*alpha)*u(i, j);

  }}

  //cout << u(span::all, n - 1) << endl;
  u.save("data.dat", raw_ascii);
  cout << "Done!" << endl;
  return 0;
}
