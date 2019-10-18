#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f( double     r1, double     r2,
          double   phi1, double   phi2,
          double theta1, double theta2 );

int main()
{
  int N = 1000;


  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);



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
  else                        { return sin(theta1)*sin(theta2)*exp(-4*(r1 + r2))/r12 ;}
}
