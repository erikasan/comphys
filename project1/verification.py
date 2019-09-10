import numpy as np, matplotlib.pyplot as plt

def exact(x):
    return 1 - (1 - np.exp(-10))*x - np.exp(-10*x)

n = 1e3
data = np.loadtxt('poisson-n=1e%d.dat' % np.log10(n))

x = data[:, 0]; u = data[:, 1]; err = data[:, 2]

fig, ax = plt.subplots(3)

ax[0].plot(x, u, 'blue')
ax[1].plot(x, exact(x), 'green')
ax[2].plot(x[1:-1], err[1:-1], 'red')
ax[0].grid()
ax[1].grid()
ax[2].grid()
plt.tight_layout()
plt.show()
