#include <iostream>
#include <cmath>

#include "gauquad.cpp"

using namespace std;

double f ( double x1, double y1, double z1,
           double x2, double y2, double z2, double alpha );

int main()
{
  int    N   = 30;
  double lam = 4;
  double *x  = new double[N], *w = new double[N];

  double I   = 0;

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
           double x2, double y2, double z2, double alpha )
{

  double r1  = sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2));
  double r2  = sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2));

  double r12 = sqrt(pow(x2 - x1, 2)
                  + pow(y2 - y1, 2)
                  + pow(z2 - z1, 2));

  double eps = 1e-10;
  if ( abs(r12) < eps ) { return 0 ;}
  else                  { return exp(-2*alpha*(r1 + r2))/r12 ;}

}
