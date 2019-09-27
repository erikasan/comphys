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

N = np.arange(100, 401, 10)
infinity = np.arange(10, 81, 5)

X, Y = np.meshgrid(infinity, N)

# Plot the surface.
surf = ax.plot_surface(X, Y, error, cmap=cm.coolwarm)
ax.set_ylabel('N')
ax.set_xlabel('rho_max')
ax.set_zlabel('Error')

fig.colorbar(surf, shrink=0.5, aspect=5)
plt.tight_layout()
plt.show()
