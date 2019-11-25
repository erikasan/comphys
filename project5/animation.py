import numpy as np, matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('seaborn-darkgrid')


font = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }


data = np.loadtxt('data.dat')

fig, ax = plt.subplots()

ax.set_xlim(0, 1)
ax.set_ylim(-0.1, 1.1)

x = np.linspace(0, 1, len(data[:, 0]))

line, = ax.plot(x, data[:, 0])

def animation_frame(i):

    line.set_xdata(x)
    line.set_ydata(data[:, i])

    return line,

plt.xlabel(r'$x$', fontdict = None)
plt.ylabel(r'$u(x, t)$', fontdict = None)

animation = FuncAnimation(fig, func = animation_frame, frames = range(len(data[0, :])), interval = 1)

plt.show()
