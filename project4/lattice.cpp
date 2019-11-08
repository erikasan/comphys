#include <iostream>
#include <armadillo>
#include <random>

using namespace std;
using namespace arma;

void initialize(int N, imat &spins, vec w);
void metropolis(int N, imat spins);
inline int periodic(int index, int limit);

int main()
{

  int N = 100; int E = 0;
  //imat spins(N, N); spins.ones();

  imat spins(N, N); vec w(17);

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

void initialize(int N, imat &spins, vec w)
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

void metropolis(imat spins, int N)
{

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  int l, k;

  double dE;

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {

    l = (int) RandomNumberGenerator(gen)*N;
    k = (int) RandomNumberGenerator(gen)*N;

    dE = 2*spins(l, k)* (   spins(periodic(l - 1, N), k)
                          + spins(periodic(l + 1, N), k)
                          + spins(l, periodic(k - 1, N))
                          + spins(l, periodic(k + 1, N))
                        )
    }}



}

inline int periodic(int index, int limit){
  // Thanks to Daniel Heinesen!!
  return (index + limit)%(limit);
}
