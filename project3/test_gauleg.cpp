#include <iostream>
#include <armadillo>
#include <cmath>

#include "lib.cpp"

using namespace std;
using namespace arma;

double f(double x);

int main()
{
  int n = 4;
  double x1 = 0, x2 = M_PI;
  double *x = new double[n], *w = new double[n];
  double int_gauleg = 0;
  gauleg(x1, x2, x, w, n);

  for (int i = 0; i != n; ++i) {
    int_gauleg += w[i]*f(x[i]);
  }

  cout << int_gauleg << endl;
  return 0;
}

double f(double x)
{
  return sin(x);
}
