
void find_a_pq(unsigned int n,
               arma::mat A,
               double *a_pq,
               unsigned int *p,
               unsigned int *q)

{

  *a_pq = 0;
  for (unsigned int i = 0; i != n; ++i) {
    for (unsigned int j = i + 1; j != n; ++j) {
      if (std::abs(A(i, j)) > *a_pq) {
        *a_pq = std::abs(A(i, j));
        *p = i;
        *q = j;
      }
    }
  }
  return;
}

void rotate(arma::mat& A, arma::mat S, unsigned int p, unsigned int q)
{
  double tau, t, c, s;
  if (A(p, q) != 0) {
    tau = (A(q, q) - A(p, p))/(2*A(p, q));

    if (tau >= 0) {
      t = 1/(tau + std::sqrt(1 + tau*tau));
    }
    else {
      t = 1/(tau - std::sqrt(1 + tau*tau));
    }
    c = 1/std::sqrt(1 + t*t);
    s = c*t;
  }
  else {
    c = 1; s = 0;
  }

  S(p, p) = c; S(p, q) = s;
  S(q, p) = -s; S(q, q) = c;

  A = arma::trans(S)*(A*S);

  return;
}

void jacobi_eigensolver(unsigned int n, arma::mat A, arma::mat& eigvals)
{
  double a_pq, tol = 1e-10;
  unsigned int p, q;

  arma::Mat<double> S = arma::eye(n, n);

  find_a_pq(n, A, &a_pq, &p, &q);
  while (tol < a_pq){
    rotate(A, S, p, q);
    find_a_pq(n, A, &a_pq, &p, &q);
  }

  eigvals = arma::diagvec(A);

  return;
}
