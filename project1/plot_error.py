import numpy as np, matplotlib.pyplot as plt

data = np.loadtxt('errors.dat')

log10h = data[:, 0]; log10err = data[:, 1]

plt.plot(log10h, log10err)
plt.xlabel('log10(h)'); plt.ylabel('log10(ε)')
plt.grid()
plt.show()
