#include <iostream>
#include <armadillo>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;
using namespace arma;

ofstream outfile;

int main()
{
  string outfilename = "CPU_time_LU.dat";
  int n;

  outfile.open(outfilename);
  while (cin >> n) {
    Mat<double> A(n, n);
    Mat<double> L, U;
    Col<double> u, z;
    vec x = zeros<vec>(n), y = zeros<vec>(n);
    vec row1 = zeros<vec>(n);
    row1[0] = -2; row1[1] = 1;

    double h = (double) 1/(n + 1);

    double hsquared = h*h;
    for (int i = 1; i != n+1; ++i) {
      x[i-1] = i*h;
      y[i-1] = -hsquared*100*exp(-10*x[i-1]);
    }

    A = toeplitz(row1, row1);

    lu(L, U, A);

    clock_t start, finish;
    start = clock();
    solve(z, L, y);
    solve(u, U, z);
    finish = clock();

    outfile << setw(20) << setprecision(16)
    << n << ' ' << (double) (finish - start)/CLOCKS_PER_SEC << endl;

  }

  outfile.close();

  return 0;
}
