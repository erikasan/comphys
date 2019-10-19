#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2, double alpha );

int main()
{
  int N = 5000000;
  double lam = 3;

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  double x1, y1, z1,
         x2, y2, z2;

  double I = 0; double u;
  for (int i = 0; i != N; ++i) {

    u = RandomNumberGenerator(gen); x1 = lam*(2*u - 1);
    u = RandomNumberGenerator(gen); x2 = lam*(2*u - 1);
    u = RandomNumberGenerator(gen); y1 = lam*(2*u - 1);
    u = RandomNumberGenerator(gen); y2 = lam*(2*u - 1);
    u = RandomNumberGenerator(gen); z1 = lam*(2*u - 1);
    u = RandomNumberGenerator(gen); z2 = lam*(2*u - 1);

    I += f(x1, y1, z1, x2, y2, z2, 2);

  }

  I *= pow(2*lam, 6);
  I /= N;

  cout << I << endl;
  return 0;
}

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2, double alpha )
{

  double r1  = sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2));
  double r2  = sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2));

  double r12 = sqrt(pow(x2 - x1, 2)
                  + pow(y2 - y1, 2)
                  + pow(z2 - z1, 2));

  double eps = 1e-4;
  if ( abs(r12) < eps ) { return 0 ;}
  else                  { return exp(-2*alpha*(r1 + r2))/r12 ;}

}
