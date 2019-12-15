import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation


T = 0.15

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

plot = [ax.plot_surface(x, y, f[0:N, :], norm = norm)]

ani = FuncAnimation(fig, update_plot, np.arange(0, int(n), 3), fargs=(f, plot), interval=1)

plt.show()
