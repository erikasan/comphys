#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;



int main()
{
  int N = 10;
  int a = 1, b = -2;
  Mat<double> A(N, N);
  Mat<double> L, U;
  vec row1 = zeros<vec>(N);
  row1[0] = -2; row1[1] = 1;

  A = toeplitz(row1, row1);

  lu(L, U, A);

  for (int i = 0; i != N; ++i) {
    for (int j = 0; j != N; ++j) {
      cout << L(i, j) << ' ';
    }
    cout << endl;
  }

  return 0;
}
