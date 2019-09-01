import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('poisson-n=1e3.dat')

x = data[:, 0]; u = data[:, 1]

def exact(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

plt.subplot(2, 1, 1)
plt.plot(x, u)
plt.subplot(2, 1, 2)
plt.plot(x, exact(x))
plt.tight_layout()
plt.show()
