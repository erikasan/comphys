#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 );

int main()
{
  int N = 10000000;

  const double     pi = 3.14159265358979323846,
               two_pi = 2*pi;

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  double     r1,     r2,
           phi1,   phi2,
         theta1, theta2;

  double I = 0;
  double u;
  for (int i = 0; i != N; ++i) {

    u = RandomNumberGenerator(gen); r1     = -log(1 - u);
    u = RandomNumberGenerator(gen); r2     = -log(1 - u);
    u = RandomNumberGenerator(gen); phi1   =   two_pi*u ;
    u = RandomNumberGenerator(gen); phi2   =   two_pi*u ;
    u = RandomNumberGenerator(gen); theta1 =       pi*u ;
    u = RandomNumberGenerator(gen); theta2 =       pi*u ;

    I += f(r1, r2, phi1, phi2, theta1, theta2)/(exp(-(r1 + r2)));
  }

  I *= 2*2*pi*pi*pi*pi;

  I /= N;

  cout << I << endl;

  return 0;
}

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 )
{

  double cosbeta = cos(theta1)*cos(theta2)
                 + sin(theta1)*sin(theta2)*cos(phi1 - phi2);

  double r12     = sqrt(pow(r1, 2) + pow(r2, 2) - 2*r1*r2*cosbeta);


  if (r12 <= 0 || isnan(r12)) { return 0 ;}

  else { return r1*r1*r2*r2*sin(theta1)*sin(theta2)*exp(-4*(r1 + r2))/r12 ;}

}
