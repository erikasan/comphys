#include <iostream>
#include "tridgausselim.h"
#include <vector>

using namespace std;

int main()
{
  int n = 3;

  double *y = new double[n], *d = new double[n],
  *a = new double[n-1], *b = new double[n-1];

  double *x = new double[n];

  vector<int> v1{1, 2, 3};
  vector<int> v2{10, 20, 30};
  vector<int> v3{4, 5};
  vector<int> v4{6, 7};

  for (int i = 0; i != n; ++i) {
    d[i] = v1[i];
    y[i] = v2[i];
  }

  for (int i = 0; i != n - 1; ++i) {
    a[i] = v3[i];
    b[i] = v4[i];
  }

  fwdsbst(n, y, d, a, b);
  bwdsbst(n, x, y, d, b);

  for (int i = 0; i != n; ++i) {
    cout << x[i] << endl;
  }
  return 0;
}
