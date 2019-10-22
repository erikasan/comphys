#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

#include "gauquad.cpp"

using namespace std;

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2 );

ofstream outfile;

int main()
{

  bool append = 1;

  int      N    ;
  double lam = 3;

  const double    pi = 3.14159265358979323846;
  const double exact = 5*pi*pi/(16*16);

  double *x = new double [N],
         *w = new double [N];

  string filename = "cartesian_gauleg.dat";

  if (append) { outfile.open(filename, ofstream::app) ;}
  else        { outfile.open(filename)                ;}

  double I;

  clock_t start, stop;

  while (cin >> N) {

    start = clock();

    gauleg(-lam, lam, x, w, N);

    I = 0;

    for (int i = 0; i != N; ++i) {
              for (int j = 0; j != N; ++j) {
              for (int k = 0; k != N; ++k) {
              for (int l = 0; l != N; ++l) {
              for (int m = 0; m != N; ++m) {
              for (int n = 0; n != N; ++n) {

    I += w[i]*w[j]*w[k]*w[l]*w[m]*w[n]
      *f(x[i],x[j],x[k],x[l],x[m],x[n]);

    }}}}}}

    stop = clock();

    outfile << setw(8) << setprecision(10)

    << 6*N << ' ' << I << ' '

    << abs(I - exact) << ' ' << (double) (stop - start)/CLOCKS_PER_SEC

    << endl;

  }

  outfile.close();

  delete [] x;
  delete [] w;

  return 0;

}

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2 )
{

  double r1  = sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2));
  double r2  = sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2));

  double r12 = sqrt(pow(x2 - x1, 2)
                  + pow(y2 - y1, 2)
                  + pow(z2 - z1, 2));

  double eps = 1e-4;
  if ( abs(r12) < eps ) { return 0                     ;}
  else                  { return exp(-4*(r1 + r2))/r12 ;}

}
