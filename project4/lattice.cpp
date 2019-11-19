/*

  Compile with

  "g++ lattice.cpp ising_montecarlo.cpp -o yournamehere -fopenmp"

  Check if openmp works with htop



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

  int N = 20;
  //vec T = regspace(2, 0.05, 2.31);
  vec T = {1};
  int mcs = 1000000;

  ising(N, T, mcs);

  cout << "Done!" << endl;

  return 0;
}
