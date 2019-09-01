/*
Using forward and backward substitution
to solve the matrix equation Ax=y
for a tridiagonal n x n matrix A
*/

// Forward substitution
void fwdsbst(unsigned int n, double *y, double *d, double *a, double *b)
{

  for (int i = 1; i != n; ++i) {
    d[i] -= a[i-1]*b[i-1]/d[i-1];
    y[i] -= a[i-1]*y[i-1]/d[i-1];
  }

  delete [] a;
  return;
}

// Backward substitution
double* bwdsbst(unsigned int n, double *y, double *d, double *b)
{
  double *x = new double[n];

  x[n-1] = y[n-1]/d[n-1];

  for (int i = n - 2; i >= 0; --i) {
    x[i] = (y[i] - b[i]*x[i+1])/d[i];
  }

  delete [] d;
  delete [] y;
  delete [] b;

  return x;
}

// Both backward and forward substitution
double* tridgausselim(unsigned int n, double *y, double *d, double* a, double *b)
{
  fwdsbst(n, y, d, a, b);
  double *x = bwdsbst(n, y, d, b);

  return x;
}
