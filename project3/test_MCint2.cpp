#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double f(double x);

int main()
{
  int N = 20000;

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  double x, u;
  double I = 0;

  for (int i = 0; i != N; ++i) {
    u = RandomNumberGenerator(gen);
    x = -log(1 - u);
    I += f(x);
  }
  I /= N;

  cout << I << endl;

  return 0;
}

double f(double x)
{
  return exp(-x);
}
