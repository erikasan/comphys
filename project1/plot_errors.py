import numpy as np, matplotlib.pyplot as plt

def exact(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

def error(u, exact):
    return np.abs((u - exact)/exact)

#N = np.array([1e2, 1e3, 1e4, 1e5, 1e6])
N = np.array([1e3])
h = 1/(N + 1)

eps = []

for n in N:
    data = np.loadtxt('poisson-n=1e%d.dat' % np.log10(n))

    x = data[:, 0]; u = data[:, 1]

    max_error = np.max(error(u[1:-1], exact(x[1:-1])))

    eps.append(max_error)

#plt.plot(np.log10(N), np.log10(eps), 'o-')
plt.plot(x, u)
plt.show()
