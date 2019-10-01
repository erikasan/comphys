import numpy as np

A = np.zeros((3, 3))

A[0, 0] = 5; A[1, 1] = 3; A[2, 2] = 2
A[0, 1] = -2; A[1, 0] = A[0, 1]
A[0, 2] = 4; A[2, 0] = 4;
eigvals, eigvecs = np.linalg.eig(A)
