#include <iostream>

using namespace std;

int main()
{
  int i; int N = 10;
  double sum = 0;
  double a = 1;
  double b = 1;

  #pragma omp parallel for default(shared) private(i) reduction(+:sum)
  for (i=0; i<N; i++) sum += a*b;

  return 0;
}
