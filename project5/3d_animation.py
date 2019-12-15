import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation


T = 0.2

f = np.loadtxt('data2d.dat')
n, N = f.shape
n /= N

x = np.linspace(0, 1, N)
x, y = np.meshgrid(x, x)

norm = plt.Normalize(vmin = 0, vmax = 1)

def update_plot(frame_number, zarray, plot):
    plot[0].remove()
    plot[0] = ax.plot_surface(x, y, zarray[frame_number*N:N*(frame_number+1), :], cmap="inferno", norm = norm)
    plt.title(r'$t = %.2f$' % (frame_number*T/(n - 1)))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_zlim(0,1.1)

ax.set_xlabel(r'$x$')
ax.set_ylabel(r'$y$')
ax.set_zlabel(r'$u(x,y,t)$')
plot = [ax.plot_surface(x, y, f[0:N, :], norm = norm)]
plot[0]._facecolors2d=plot[0]._facecolors3d
plot[0]._edgecolors2d=plot[0]._edgecolors3d
plt.legend([r'2D Forward Euler $h=0.01$'], loc = 'upper left')
plt.tight_layout()

animation = FuncAnimation(fig, update_plot, np.arange(0, int(n), 600), fargs=(f, plot), interval=1, repeat_delay = 1000)

animation.save('2d_Forward_euler_h=0.01.gif', writer='imagemagick', fps=2)

#plt.show()
