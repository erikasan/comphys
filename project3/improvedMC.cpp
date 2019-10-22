#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>

using namespace std;

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 );

ofstream outfile;

int main()
{

  bool append = 1;

  int N;

  const double     pi = 3.14159265358979323846,
               two_pi = 2*pi;
  const double exact  = 5*pi*pi/(16*16);

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  double     r1,     r2,
           phi1,   phi2,
         theta1, theta2;

  double I, u, sigma, F;

  clock_t start, stop;

  string filename = "improvedMC.dat";

  if (append) { outfile.open(filename, ofstream::app) ;}
  else        { outfile.open(filename)                ;}

  while (cin >> N) {

    I = 0; sigma = 0;

    start = clock();

    for (int i = 0; i != N; ++i) {

      u = RandomNumberGenerator(gen); r1     = -log(1 - u);
      u = RandomNumberGenerator(gen); r2     = -log(1 - u);
      u = RandomNumberGenerator(gen); phi1   =   two_pi*u ;
      u = RandomNumberGenerator(gen); phi2   =   two_pi*u ;
      u = RandomNumberGenerator(gen); theta1 =       pi*u ;
      u = RandomNumberGenerator(gen); theta2 =       pi*u ;

      F = r1*r1 * r2*r2
        *  sin(theta1)*sin(theta2)
        *  exp(r1 + r2)
        *  f(r1,  r2, phi1, phi2, theta1, theta2);

      I += F;
      sigma += F*F;

    }

    I *= 4*pi*pi*pi*pi;
    I /= N;

    stop = clock();

    sigma *= 16*pow(pi, 8)/N;
    sigma -= I*I;
    sigma = sqrt(sigma);

    outfile << setw(8) << setprecision(10)

    << N << ' ' << I << ' '

    << abs(I - exact) << ' ' << (double) (stop - start)/CLOCKS_PER_SEC

    << ' ' << sigma << endl;
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


  if (r12 <= 1e-4 || isnan(r12)) { return 0                     ;}
  else                           { return exp(-4*(r1 + r2))/r12 ;}

}
