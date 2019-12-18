#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <armadillo>

using namespace std;
using namespace arma;

double f(double x, double t);
double calc_error(vec u, int N, int n, double T);

ofstream outfile;

int main()
{

  ivec N = {11, 101};
  ivec n = {81, 8001};

  vec times = regspace(0, 0.01, 0.4);

  mat                FE,             BE,             CN;
  vec                 u,              v,              w;
  double         eps_FE,         eps_BE,         eps_CN;
  char   filename1 [20], filename2 [20], filename3 [20];


  for (int i = 0; i < 2; ++i) {

    sprintf(filename1, "errors-N=%d.dat", (int) N(i));
    outfile.open(filename1);

    sprintf(filename1, "FE-N=%d.dat", (int) N(i));
    sprintf(filename2, "BE-N=%d.dat", (int) N(i));
    sprintf(filename3, "CN-N=%d.dat", (int) N(i));

    FE.load(filename1);
    BE.load(filename2);
    CN.load(filename3);

    for (double t : times) {

      int j = (int) (n(i) - 1)*t/0.4;

      u = FE(span::all, j);
      v = BE(span::all, j);
      w = CN(span::all, j);

      eps_FE = calc_error(u, N(i), n(i), t);
      eps_BE = calc_error(v, N(i), n(i), t);
      eps_CN = calc_error(w, N(i), n(i), t);

      outfile << eps_FE << ' ' << eps_BE << ' ' << eps_CN << endl;

    }

    outfile.close();

  }

  cout << "Done!" << endl;

  return 0;
}

double f(double x, double t)
{
  double u  = 0        ;
  double pi = 4*atan(1);

  for (int n = 1; n < 10; ++n) {
    u += pow(-1, n)*2/pi*sin(n*pi*x)*exp(-n*n*pi*pi*t);
  }

  return x + u;

}

double calc_error(vec u, int N, int n, double t)
{


  double numerator = 0;
  double norm      = 0;

  double x;
  double F;

  for (int i = 0; i < N; ++i) {

    x = (double) i/(N - 1);
    F = f(x, t);

    numerator += (u(i) - F)*(u(i) - F);
    norm      +=  F*F;                ;

  }

  return sqrt(numerator/norm);

}
