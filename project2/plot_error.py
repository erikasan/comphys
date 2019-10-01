import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter

plt.style.use('fivethirtyeight')
fig = plt.figure()
ax = fig.gca(projection='3d')

exact = 3
lam = np.loadtxt('lambda=%d.dat' % exact)
error = np.abs(exact - lam)

N = np.arange(100, 201, 10)
infinity = np.arange(5, 21, 2)

X, Y = np.meshgrid(infinity, N)

# Plot the surface.
surf = ax.plot_surface(X, Y, error, cmap=cm.coolwarm)
ax.set_ylabel(r'$N$')
ax.set_xlabel(r'$\rho_{max}$')
ax.set_zlabel(r'$\varepsilon_{abs}$')

fig.colorbar(surf, shrink=0.7, aspect=5)
plt.tight_layout()
plt.show()
