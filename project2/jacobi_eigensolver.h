/*

  Reduces a real symmetric n x n -
  matrix A into a diagonal matrix with
  its eigenvalues along the diagonal.
  Also builds an n x n - matrix P with
  the normalized eigenvectors of A as its columns.

  Make sure to include Armadillo
  and cmath in the main program

*/

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

void rotate(unsigned int n,
            arma::mat& A,
            arma::mat& P,
            unsigned int p,
            unsigned int q)

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

  double c2 = c*c, s2 = s*s;
  double a_pp, a_qq, two_a_pq_cs, a_ip, a_iq, c_p_ip, s_p_iq;

  a_pp = A(p, p); a_qq = A(q, q); two_a_pq_cs = 2*A(p, q)*c*s;

  A(p, q) = 0; A(q, p) = 0;
  A(p, p) = a_pp*c2 - two_a_pq_cs + a_qq*s2;
  A(q, q) = a_qq*c2 + two_a_pq_cs + a_pp*s2;

  for (int i = 0; i != n; ++i) {
    if ((i != p) & (i != q)) {
      a_ip = A(i, p); a_iq = A(i, q);
      A(i, p) = a_ip*c - a_iq*s;
      A(i, q) = a_iq*c + a_ip*s;
      A(p, i) = A(i, p); A(q, i) = A(i, q);

    }
    c_p_ip = c*P(i, p); s_p_iq = s*P(i, q);
    P(i, p) = c_p_ip - s_p_iq;
    P(i, q) = c_p_ip + s_p_iq;
  }

  return;
}

void jacobi_eigensolver(unsigned int n,
                        arma::mat& A,
                        arma::mat& P)

{
  double a_pq, tol = 1e-10;
  unsigned int p, q;

  P = arma::eye(n, n);

  find_a_pq(n, A, &a_pq, &p, &q);
  while (tol < a_pq){
    rotate(n, A, P, p, q);
    find_a_pq(n, A, &a_pq, &p, &q);
  }

  return;
}
