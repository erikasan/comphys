#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void find_a_pq(unsigned int, mat, double*, unsigned int*, unsigned int*);
void rotate();

int main()
{
  unsigned int n = 3;
  unsigned int p, q;
  double a_pq;
  Mat<double> A(n, n);
  A.randu();
  A(0, 1) = 69;
  find_a_pq(n, A, &a_pq, &p, &q);
  cout << A << endl;
  cout << p << ' ' << q << endl;
  cout << a_pq << endl;
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
