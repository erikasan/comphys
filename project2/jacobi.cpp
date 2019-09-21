#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

void find_a_pq(unsigned int, mat, double*, unsigned int*, unsigned int*);
void rotate(unsigned int, mat&, unsigned int, unsigned int);

int main()
{
  unsigned int n = 2;
  unsigned int p, q;
  double a_pq;
  Mat<double> A(n, n);
  vec row = randi<vec>(n);
  A = toeplitz(row, row);
  cout << A << endl;
  cout << endl;
  find_a_pq(n, A, &a_pq, &p, &q);
  rotate(n, A, p, q);
  cout << A << endl;
  return 0;
}

void find_a_pq(unsigned int n,
               mat A,
               double *a_pq,
               unsigned int *p,
               unsigned int *q)

{
  *a_pq = 0;
  for (unsigned int i = 0; i != n; ++i) {
    for (unsigned int j = i + 1; j != n; ++j) {
      if (abs(A(i, j) > *a_pq)) {
        *a_pq = abs(A(i, j));
        *p = i;
        *q = j;
      }
    }
  }
  return;
}

void rotate(unsigned int n, mat& A, unsigned int p, unsigned int q)
{
  double tau, t, c, s;
  mat S = eye(n, n);
  if (A(p, q) != 0) {
    tau = (A(q, q) - A(p, p))/(2*A(p, q));

    if (tau >= 0) {
      t = 1/(tau + sqrt(1 + tau*tau));
    }
    else {
      t = 1/(tau - sqrt(1 + tau*tau));
    }
    c = 1/sqrt(1 + t*t);
    s = c*t;
  }
  else {
    c = 1; s = 0;
  }

  S(p, p) = c; S(p, q) = s;
  S(q, p) = -s; S(q, q) = c;

  A = trans(S)*(A*S);

  return;
}
