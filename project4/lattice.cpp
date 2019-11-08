#include <iostream>
#include <armadillo>
#include <random>

using namespace std;
using namespace arma;

void initialize(imat &spins, int N);

int main()
{

  int N = 100; int E = 0;
  //imat spins(N, N); spins.ones();

  imat spins(N, N);

  initialize(spins, N);

  cout << spins << endl;

  int im1 = N - 1;
  int jm1 = N - 1;

  for (int i = 0; i != N; ++i) {
  for (int j = 0; j != N; ++j) {

    E += spins(i, j)*(spins(im1, j) + spins(i, jm1));

    jm1 = j; }
    im1 = i; }

  E *= -1;

  cout << E << endl;

  return 0;
}

void initialize(imat &spins, int N)
{

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {

      if (RandomNumberGenerator(gen) > 0.5) {spins(i, j) =  1;}
      else                                  {spins(i, j) = -1;}

    }}

  cout << spins << endl;
  return;
}
