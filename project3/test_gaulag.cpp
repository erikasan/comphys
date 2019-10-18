#include <iostream>
#include <cmath>
#include <armadillo>

#include "gauquad.cpp"

using namespace std;
using namespace arma;

double f(double x);

int main()
{
  int n = 6;
  double x1 = 0, x2 = 10;
  double *x = new double[n+1], *w = new double[n+1];
  double int_gaulag = 0;
  gaulag(x, w, n, 0);

  for (int i = 1; i != n+1; ++i) {
    int_gaulag += w[i]*f(x[i]);
  }

  cout << int_gaulag << endl;
  return 0;
}

double f(double x)
{
  return 1;
}
