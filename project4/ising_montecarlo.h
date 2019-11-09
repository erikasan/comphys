#include <iostream>
#include <armadillo>
#include <cmath>
#include <cstdio>
#include <string>
#include <random>

using namespace std;
using namespace arma;

void initialize(int N, double &E, double &M, double T, imat &spins, vec &w);
void metropolis(int N, double &E, double &M, imat &spins, vec w);
inline int periodic(int index, int limit);
void ising(int N, vec T, int mcs);
