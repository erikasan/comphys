#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void LUdcmp(double* A, double* L, double* U);

int main()
{

  int n;
  cout << "Type in the dimension n of the matrix: n = ";
  cin >> n;

  Mat<double> A(n, n), L(n, n), U(n, n);



  cout << "Success!" << endl;
  return 0;
}

void LUdcmp(double* A, double* L, double* U)
{
  // Step one
  for (auto j = 0; j != A.n_cols; ++j) {
    U(1, j) = A(1, j);
  }

  // Step two

}
