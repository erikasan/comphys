import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

def f(x, y, t):
    return np.sin(np.pi*x)*np.sin(np.pi*y)*np.exp(-2*np.pi**2*t)

T = 0.3

N = 10

x = np.linspace(0, 1, N)
x, y = np.meshgrid(x, x)

t = np.linspace(0, T, 100)

norm = plt.Normalize(vmin = 0, vmax = 1)

def update_plot(frame_number, zarray, plot):
    plot[0].remove()
    plot[0] = ax.plot_surface(x, y, f(x, y, t[frame_number]), cmap="inferno", norm = norm)
    plt.title(r'$t = %.2f$' % t[frame_number])

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_zlim(0,1.1)

ax.set_xlabel(r'$x$')
ax.set_ylabel(r'$y$')
ax.set_zlabel(r'$u(x,y,t)$')

plot = [ax.plot_surface(x, y, f(x, y, 0), norm = norm)]
plot[0]._facecolors2d=plot[0]._facecolors3d
plot[0]._edgecolors2d=plot[0]._edgecolors3d
plt.legend([r'Analytical solution'], loc = 'upper left')
plt.tight_layout()

animation = FuncAnimation(fig, update_plot, np.arange(0, len(t)), fargs=(f, plot), interval=1, repeat_delay = 1000)

#animation.save('2d_Forward_euler_h=0.01.gif', writer='imagemagick', fps=2)

plt.show()
