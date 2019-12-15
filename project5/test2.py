import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

plt.style.use('seaborn-darkgrid')

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x = np.linspace(0, 1, 100)
y = np.linspace(0, 1, 100)

def f(x, y, t):
    return np.sin(np.pi*x)*np.sin(np.pi*y)*np.exp(-2*np.pi**2*t)

x, y = np.meshgrid(x, y)

ax.set_zlim(0,1.1)
ax.plot_surface(x, y, f(x, y, 0.15))

ax.set_xlabel(r'$x$')
ax.set_ylabel(r'$y$')
ax.set_zlabel(r'$f(x, y)$')
plt.tight_layout()
plt.show()
