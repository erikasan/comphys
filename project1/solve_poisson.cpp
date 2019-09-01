#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

#include "solve_poisson.h"

using namespace std;

ofstream outfile;

int main()
{

  double input;                           // Variable where the input is stored

  unsigned int n;                         // Number of integration points

  double h;                               // Stepsize

  // Begin while-loop
  while (cin >> input) {

    n = (int) input;

    double *x = new double[n+2];          //Define array that holds the x values


    double *f = new double[n+2];          // Define array that will contain
                                          // the discretized f(x)

    double *u = new double[n+2];          // Define array that will contain
                                          // the solution to the differential equation


    int x0 = 0, X = 1;                    // Define the interval [x0, X]
    x[0] = x0; x[n+1] = X;                // where we will solve
                                          // the differential equation

    h = (double) (x[n+1] - x[0])/(n+1);            // Define Stepsize

    double *d = new double[n],            // Define arrays that will
    *a = new double[n-1],                 // hold the matrix elements
    *b = new double[n-1];

    for (int i = 1; i != n+1; ++i) {      // Fill arrays with elements
      x[i] = x[0] + i*h;
    }

    for (int i = 0; i != n+2; ++i) {
      f[i] = 100*exp(-10*x[i]);
    }

    u = solve_poisson(f, x0, X, n);       // Solve differential equation

    string outfilename = "poisson-n=1e"
    + to_string((int) log10(n)) + ".dat";
    outfile.open(outfilename);

    for (int i = 0; i != n+2; ++i) {      // Write to file
      outfile << setw(15) << setprecision(8)
      << x[i] << ' ' << u[i] << endl;
    }

    outfile.close();

  } // End while loop

  return 0;
}
