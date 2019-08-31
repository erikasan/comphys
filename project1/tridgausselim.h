void fwdsbst(int n, double*, double*, double*, double*);
void bwdsbst(int n, double*, double*, double*, double*);

void fwdsbst(int n, double *y, double *d, double *a, double *b)
{

  for (int i = 0; i != n - 1; ++i) {
    d[i+1] -= a[i]*b[i]/d[i];
    y[i+1] -= a[i]*y[i]/d[i];
  }

  delete [] a;
  return;
}

void bwdsbst(int n, double *x, double *y, double *d, double *b)
{
  x[n-1] = y[n-1]/d[n-1];
  for (int i = n - 2; i >= 0; --i) {
    x[i] = (y[i] - b[i]*x[i+1])/d[i];
  }

  delete [] d;
  delete [] y;
  delete [] b;

  return;
}
