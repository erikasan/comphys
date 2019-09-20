#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void find_a_pq(unsigned int, mat, double*, unsigned int*, unsigned int*);

int main()
{
  unsigned int n = 10;
  unsigned int p, q;
  double a_pq;
  Mat<double> A(n, n);
  A.randu();
  A(1, 0) = 10;
  find_a_pq(n, A, &a_pq, &p, &q);
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
    for (unsigned int j = 0; j != n; ++j) {
      if (i != j) {
        if (abs(A(i, j) > *a_pq)) {
          *a_pq = abs(A(i, j));
          if (i < j) {
            *p = i;
            *q = j;
          }
          else {
            *p = j;
            *q = i;
          }
        }
      }
    }
  }
  return;
}
