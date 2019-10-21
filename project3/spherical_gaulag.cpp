#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>

#include "gauquad.cpp"

using namespace std;

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 );

ofstream outfile;

int main()
{

  bool append = 1;

  int N;
  int Nr, Nphi, Ntheta;

  double alpha = 2;

  const double     pi = 3.14159265358979323846,
               two_pi = 2*pi;

  double exact = 5*pi*pi/(16*16);

  string       filename = "spherical_gaulag.dat";

  if (append) { outfile.open(filename, ofstream::app) ;}
  else        { outfile.open(filename)                ;}

  double I;

  clock_t start, stop;

  while (cin >> N) {

    Nr = Nphi = Ntheta = N/3;

    double *      r = new double [Nr + 1],
           *    phi = new double [ Nphi ],
           *  theta = new double [Ntheta],

           *     wr = new double [Nr + 1],
           *   wphi = new double [ Nphi ],
           * wtheta = new double [Ntheta];

    start = clock();

    gaulag(r, wr, Nr, alpha);

    gauleg(0, two_pi, phi, wphi, Nphi);

    gauleg(0, pi, theta, wtheta, Ntheta);

    I = 0;

    for (int i = 1; i != Nr+1; ++i) {
              for (int j = 1; j != Nr+1;   ++j) {
              for (int k = 0; k != Nphi;   ++k) {
              for (int l = 0; l != Nphi;   ++l) {
              for (int m = 0; m != Ntheta; ++m) {
              for (int n = 0; n != Ntheta; ++n) {

    I +=  wr[i]*wr[j]*wphi[k]*wphi[l]*wtheta[m]*wtheta[n]
      *  f(r[i], r[j], phi[k], phi[l], theta[m], theta[n]);

    }}}}}}

    I /= pow(2*alpha, 5);

    stop = clock();

    outfile << setw(8) << setprecision(10)

    << Nr+Nphi+Ntheta << ' ' << I << ' '

    << abs(I - exact) << ' ' << (double) (stop - start)/CLOCKS_PER_SEC

    << endl;

    delete []      r;
    delete []    phi;
    delete []  theta;

    delete []     wr;
    delete []   wphi;
    delete [] wtheta;

  }

  return 0;

}

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 )
{

  double cosbeta = cos(theta1)*cos(theta2)
                 + sin(theta1)*sin(theta2)*cos(phi1 - phi2);

  double r12     = sqrt(pow(r1, 2) + pow(r2, 2) - 2*r1*r2*cosbeta);

  if (r12 <= 1e-4 || isnan(r12)) { return 0 ;}
  else                           { return sin(theta1)*sin(theta2)/r12 ;}

}
