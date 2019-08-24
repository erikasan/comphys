#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
  double N;
  double sup = 0, sdown = 0;

  cin >> N;

  for (double n = 1; n <= N; ++n) {
    sup += 1/n;
  }

  for (double n = N; n >= 1; --n) {
    sdown += 1/n;
  }

  cout << "sup = " << sup << endl;
  cout << "sdown = " << sdown << endl;

  return 0;
}
