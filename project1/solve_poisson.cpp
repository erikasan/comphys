#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <algorithm>

#include "solve_poisson.h"

using namespace std;


double* error(unsigned int,
              double*,
              double*,
              double*,
              bool);

ofstream outfile1;
ofstream outfile2;
ofstream outfile3;

int main()
{

  double input;                           // Variable where the input is stored

  unsigned int n;                         // Number of integration points

  double h;                               // Stepsize

  string filename2 = "errors.dat";
  string filename3 = "CPU_time_simple.dat";
  outfile2.open(filename2);
  outfile3.open(filename3);

  // Begin while-loop
  while (cin >> input) {

    n = (unsigned int) input;

    double *x = new double[n+2];          //Define array that holds the x values


    double *g = new double[n+2];          // Define array that will contain
                                          // the discretized g(x)

    double *f = new double[n+2];          // Define array to hold the analytical
                                          // solution

    double *u = new double[n+2];          // Define array that will contain
                                          // the solution to the differential equation

    double *err = new double[n+2];        // Define array to hold the relative error

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
      g[i] = 100*exp(-10*x[i]);
    }

    for (int i = 0; i != n+2; ++i) {
      f[i] = 1 - (1 - exp(-10))*x[i] - exp(-10*x[i]);
    }

    clock_t start, finish;
    start = clock();

    u = solve_poisson(g, x0, X, n, true);       // Solve differential equation

    finish = clock();

    err = error(n, u, f, err, true);

    string filename1 = "poisson-n=1e"
    + to_string((int) log10(n)) + ".dat";
    outfile1.open(filename1);

    for (int i = 0; i != n+2; ++i) {      // Write to file
      outfile1 << setw(20) << setprecision(16)
      << x[i] << ' ' << u[i] << endl;
    }

    outfile1.close();

    outfile2 << setw(20) << setprecision(16)
    << log10(h) << ' ' << *max_element(err + 1, err + n - 1) << endl;

    outfile3 << setw(20) << setprecision(16)
    << n << ' ' << (double) (finish - start)/CLOCKS_PER_SEC << endl;


  } // End while loop

  outfile2.close();
  outfile3.close();

  return 0;
}

double* error(unsigned int n,
              double *u,
              double *f,
              double *err,
              bool log = false)
{
  if (log) {
    for (int i = 0; i != n+2; ++i) {
      err[i] = log10(abs((u[i] - f[i])/f[i]));
    }
  }

  else {
    for (int i = 0; i != n+2; ++i) {
      err[i] = abs((u[i] - f[i])/f[i]);
  }


  }

  return err;
}
