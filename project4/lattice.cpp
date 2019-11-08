#include <iostream>
#include <armadillo>
#include <cmath>
#include <random>

using namespace std;
using namespace arma;

void initialize(int N, double &E, double T, imat &spins, vec w);
void metropolis(int N, double &E, imat &spins, vec w);
inline int periodic(int index, int limit);

int main()
{

  int N = 5; double E = 0;
  double T = 2;

  imat spins(N, N); vec w(17);

  int MC = 100000;

  vec energy(MC);

  initialize(N, E, T, spins, w);

  for (int mc = 0; mc < MC; ++mc) {

    metropolis(N, E, spins, w);

    energy(mc) = E;

  }

  cout << spins << endl;

  energy.save("energy.dat", raw_ascii);

  cout << "Done" << endl;

  return 0;
}

void initialize(int N, double &E, double T, imat &spins, vec w)
{

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {

      if (RandomNumberGenerator(gen) > 0.5) {spins(i, j) =  1;}
      else                                  {spins(i, j) = -1;}

    }}

  int im1 = N - 1;
  int jm1 = N - 1;

  for (int i = 0; i != N; ++i) {
  for (int j = 0; j != N; ++j) {

    E += spins(i, j)*(spins(im1, j) + spins(i, jm1));

    jm1 = j; }
    im1 = i; }

  E *= -1;

  for (int dE = -8; dE <= 8; dE += 4) w(dE + 8) = exp(-dE/T);
  cout << w << endl;
  return;

}

void metropolis(int N, double &E, imat &spins, vec w)
{

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  int l, k;

  int dE;

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {

    l = (int) (RandomNumberGenerator(gen) * (double) N);
    k = (int) (RandomNumberGenerator(gen) * (double) N);

    dE = 2*spins(l, k)* (   spins(periodic(l - 1, N), k)
                          + spins(periodic(l + 1, N), k)
                          + spins(l, periodic(k - 1, N))
                          + spins(l, periodic(k + 1, N))
                        );

    if (RandomNumberGenerator(gen) <= w(dE + 8)) {
      cout << "lol" << endl;
      spins(l, k) *= -1;
      E += dE;
    }

    }}

 return;

}

inline int periodic(int index, int limit){
  // Thanks to Daniel Heinesen!!
  return (index + limit)%(limit);
}
