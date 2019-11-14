import numpy as np, matplotlib.pyplot as plt

energy = np.loadtxt('energy.dat')
mcs = np.arange(1,len(energy)+1)

plt.style.use('fivethirtyeight')
plt.plot(np.cumsum(energy)/mcs, linewidth = 1.3)
#plt.plot(energy, linewidth = 1.3)
plt.xlabel(r'$ \mathrm{MC sweeps}$')
plt.ylabel(r'$E \hspace{1} / \hspace{1} [J]$')
plt.tight_layout()
plt.show()
