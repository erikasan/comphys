#include "ising_montecarlo.h"

void ising(int N, vec Temps, int mcs)
{

  //vec mcsrange = regspace(1, mcs);

  //ivec imprange = regspace<ivec>(((int) 4e5) + 1, mcs); // Improved method. Wait 4e5 mc cycles before sampling
  ivec imprange = regspace<ivec>(1, (int) (mcs - 4e5));

  #pragma omp parallel for
  for (int i = 0; i < Temps.n_elem; ++i) {

    double E = 0, M = 0;

    char filename [16];

    imat spins(N, N); vec w(17);

    //mat data(mcs, 7);
    mat data((int) mcs - (int) 4e5, 7);

    double T = Temps[i];

    initialize(N, E, M, T, spins, w);

    for (int mc = 0; mc < (int) 4e5; ++mc) {

      metropolis(N, E, M, spins, w);

      //data(mc, 0) = E; data(mc, 2) = M;
    }

    for (int mc = 0; mc < (int) (mcs - 4e5); ++mc) {

      metropolis(N, E, M, spins, w);

      data(mc, 0) = E; data(mc, 2) = M;

    }

    /*
    // Calculate <E>
    data(span::all, 1) = cumsum(       data(span::all, 0)) /mcsrange;

    // Calculate <M> and <|M|>
    data(span::all, 3) = cumsum(       data(span::all, 2)) /mcsrange;
    data(span::all, 4) = cumsum(   abs(data(span::all, 2)))/mcsrange;

    // Calculate Cv and X
    data(span::all, 5) = (cumsum(square(data(span::all, 0)))/mcsrange
                               - square(data(span::all, 1)))/(T*T);

    data(span::all, 6) = (cumsum(square(data(span::all, 2)))/mcsrange
                               - square(data(span::all, 3)))/T;
    */

    // Calculate <E>
    data(span::all, 1) = cumsum(       data(span::all, 0)) /imprange;

    // Calculate <M> and <|M|>
    data(span::all, 3) = cumsum(       data(span::all, 2)) /imprange;
    data(span::all, 4) = cumsum(   abs(data(span::all, 2)))/imprange;

    // Calculate Cv and X
    data(span::all, 5) = (cumsum(square(data(span::all, 0)))/imprange
                               - square(data(span::all, 1)))/(T*T);

    data(span::all, 6) = (cumsum(square(data(span::all, 2)))/imprange
                               - square(data(span::all, 3)))/T;

    // Scale by # of spins

    data /= (N*N);

    sprintf  (filename, "data-N=%d-T=%.2f.dat", N, T);
    data.save(filename, raw_ascii);

  }

  return;
}

void initialize(int N, double &E, double &M, double T, imat &spins, vec &w)
{

  E = M = 0; // Never forget

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

  for (int i = 0; i < N; ++i) {
  for (int j = 0; j < N; ++j) {

    E -= spins(i, j)*(spins(im1, j) + spins(i, jm1));

    M += spins(i, j);

    jm1 = j; }
    im1 = i; }

  for (int dE = -8; dE <= 8; dE += 4) w(dE + 8) = exp(-dE/T);

  return;

}

void metropolis(int N, double &E, double &M, imat &spins, vec w)
{

  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> RandomNumberGenerator(0.0,1.0);

  int l, k;

  int dE;

  for (int i = 0; i < (int) N*N; ++i) {

    l = (int) (RandomNumberGenerator(gen) * (double) N);
    k = (int) (RandomNumberGenerator(gen) * (double) N);

    dE = 2*spins(l, k) * (   spins(periodic(l - 1, N), k)
                           + spins(periodic(l + 1, N), k)
                           + spins(l, periodic(k - 1, N))
                           + spins(l, periodic(k + 1, N))
                         ) ;

    if (RandomNumberGenerator(gen) <= w(dE + 8)) {
      spins(l, k) *= -1;
      E += (double) dE;
      M += (double) 2*spins(l, k);

    }
  }

 return;

}

inline int periodic(int index, int limit){
  // Thanks to Daniel Heinesen!!
  return (index + limit)%(limit);
}
