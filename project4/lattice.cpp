#include <iostream>
#include <armadillo>
#include <random>

using namespace std;
using namespace arma;

int main()
{

  int N = 0; int E = 0;
  imat spins = ones<imat>(N, N);

  spins(0, 0) = -1;
  spins(1, 1) = -1;

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
