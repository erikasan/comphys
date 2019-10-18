#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f(double x, double y);

int main()
{
  int N = 700000;
  double lam = 5;

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  double I = 0;
  double x, y, u;

  const double two_pi = 2*3.14159265358979323846;

  for (int i = 0; i != N; ++i) {
    u = RandomNumberGenerator(gen);
    x = -lam + (lam  - (-lam))*u;
    u = RandomNumberGenerator(gen);
    y = -lam + (lam  - (-lam))*u;

    I += f(x, y)/(1/(2*lam*2*lam));
  }

  I /= N;

  cout << I << ' ' << two_pi << endl;

  return 0;
}

double f(double x, double y)
{
  return exp(-(x*x + y*y)/2);
}
