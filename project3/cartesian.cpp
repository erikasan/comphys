#include <iostream>
#include <cmath>

#include "gauquad.cpp"

using namespace std;

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2,
                                            double alf);

int main()
{
  int N = 16;
  double lam = 2;
  double *x = new double[N], *w = new double[N];

  double I = 0;

  gauleg(-lam, lam, x, w, N);

  for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j) {
            for (int k = 0; k != N; ++k) {
            for (int l = 0; l != N; ++l) {
            for (int m = 0; m != N; ++m) {
            for (int n = 0; n != N; ++n) {
  I += w[i]*w[j]*w[k]*w[l]*w[m]*w[n]
    *f(x[i],x[j],x[k],x[l],x[m],x[n], 2);
            }}}}}}

  cout << I << endl;
  return 0;
}

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2,
                                            double alf)
{

  double sqrt1 = sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2));
  double sqrt2 = sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2));

  double sqrt3 = sqrt(pow(x2 - x1, 2)
                    + pow(y2 - y1, 2)
                    + pow(z2 - z1, 2));

  double tol = 1e-5;
  if ( abs(sqrt3) < tol ) { return 0 ;}
  else { return exp(-2*alf * (sqrt1 + sqrt2))/sqrt3 ;}

}
