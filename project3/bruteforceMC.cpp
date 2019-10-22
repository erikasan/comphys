#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>

using namespace std;

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2 );

ofstream outfile;

int main()
{

  bool append = 1;

  int N;
  double lam = 3;

  double x1, y1, z1,
         x2, y2, z2;

  double I, u, sigma, F;

  const double    pi = 3.14159265358979323846;
  const double exact = 5*pi*pi/(16*16);

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  clock_t start, stop;

  string filename = "bruteforceMC.dat";

  if (append) { outfile.open(filename, ofstream::app) ;}
  else        { outfile.open(filename)                ;}

  while (cin >> N) {

    I = 0; sigma = 0;

    start = clock();

    for (int i = 0; i != N; ++i) {

      u = RandomNumberGenerator(gen); x1 = lam*(2*u - 1);
      u = RandomNumberGenerator(gen); x2 = lam*(2*u - 1);
      u = RandomNumberGenerator(gen); y1 = lam*(2*u - 1);
      u = RandomNumberGenerator(gen); y2 = lam*(2*u - 1);
      u = RandomNumberGenerator(gen); z1 = lam*(2*u - 1);
      u = RandomNumberGenerator(gen); z2 = lam*(2*u - 1);

      F = f(x1, y1, z1, x2, y2, z2);
      I += F;
      sigma += F*F;

    }

    I *= pow(2*lam, 6);
    I /= N;

    stop = clock();

    sigma *= pow(2*lam, 12)/N;
    sigma -= I*I;
    sigma = sqrt(sigma);

    outfile << setw(8) << setprecision(10)

    << N << ' ' << I << ' '

    << abs(I - exact) << ' ' << (double) (stop - start)/CLOCKS_PER_SEC

    << ' ' << sigma << endl;

  }

  outfile.close();

  return 0;

}

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2)
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
