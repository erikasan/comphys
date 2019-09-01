#include <iostream>
#include "tridgausselim.h"
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

  // Number of integration points
  int n;

  // Stepsize
  double h;

  // Begin while-loop
  while (cin >> n) {

    //Define array that holds the x values
    double *x = new double[n+2];

    //Define array that will contain the discretized f(x)
    double *f = new double[n+2];

    //Define array that will contain the solution to the differential equation
    double *u = new double[n+2];

    // Define interval where we will solve the differential equation
    x[0] = 0; x[n+1] = 4;

    // Define Stepsize
    h = (x[n+1] - x[0])/(n+1);

    // Define arrays that will hold the matrix elements
    double *d = new double[n], *a = new double[n-1], *b = new double[n-1];

    // Dirichlet boundary conditions
    u[0] = 0; u[n+1] = 0;


    // Fill arrays with elements
    for (int i = 1; i != n+1; ++i) {
      x[i] = x[0] + i*h;
    }

    for (int i = 0; i != n+2; ++i) {
      f[i] = 100*exp(-10*x[i]);
    }

    for (int i = 0; i != n; ++i) {
      d[i] = -2;
    }

    for (int i = 0; i != n-1; ++i) {
      a[i] = 1;
      b[i] = 1;
    }



  } // End while loop
  return 0;
}
