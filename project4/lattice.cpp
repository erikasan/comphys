/*

  Compile with

  "g++ lattice.cpp ising_montecarlo.cpp -o yournamehere -fopenmp"

*/

#include <iostream>
#include <armadillo>
#include <cmath>
#include <random>

#include "ising_montecarlo.h"

using namespace std;
using namespace arma;

int main()
{

  int N = 2;
  vec T = regspace(2.20, 0.01, 2.31);
  int mcs = 1000000;

  ising(N, T, mcs);

  cout << "Done!" << endl;

  return 0;
}
