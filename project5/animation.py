import numpy as np, matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('seaborn-darkgrid')


def f(x, t):
    u = 0
    for n in range(1, 20):
        u += (-1)**n*2/(n*np.pi)*np.sin(n*np.pi*x)*np.exp(-(n*np.pi)**2*t)
    return x + u


data = np.loadtxt('CN-N=101.dat')

fig, ax = plt.subplots()

ax.set_xlim(0, 1)
ax.set_ylim(-0.1, 1.1)

T = 0.5
x = np.linspace(0, 1, len(data[:, 0]))
t = np.linspace(0, T, len(data[0, :]))
t = np.linspace(0, T, 8000)

#line1, = ax.plot(x, data[:, 0])
line2, = ax.plot(x, f(x, t[0]), color = 'darkslategray', linewidth = 5, alpha = 0.3)

def animation_frame(i):

    #line1.set_xdata(x)
    line2.set_xdata(x)
    #line1.set_ydata(data[:, i])
    line2.set_ydata(f(x, t[i]))
    plt.title(r'$t = %.2f$' % t[i])

    #return line1, line2
    return line2

plt.xlabel(r'$x$', fontdict = None)
plt.ylabel(r'$u(x, t)$', fontdict = None)
#plt.legend([r'Crank-Nicolson $\Delta x = 1/100$', 'Analytical solution'], loc = 'upper left')
plt.legend([r'Analytical solution'], loc = 'upper left')

animation = FuncAnimation(fig, func = animation_frame, frames = np.arange(1, len(data[0, :]), 20), interval = 1, repeat_delay = 1000)

animation.save('analyticalsolution_1D.gif', writer='imagemagick', fps=20)

#plt.show()
