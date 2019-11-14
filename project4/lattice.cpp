#include <iostream>
#include <armadillo>
#include <cmath>
#include <random>

#include "ising_montecarlo.cpp"

using namespace std;
using namespace arma;

int main()
{

  int N = 40;
  vec T = regspace(2.2, 0.02, 2.31);
  int mcs = 1000000;

  ising(N, T, mcs);

  cout << "Done!" << endl;

  return 0;
}
