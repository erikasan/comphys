import numpy as np, matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('seaborn-darkgrid')

def f(x, t):
    u = 0
    for n in range(1, 20):
        u += (-1)**n*2/(n*np.pi)*np.sin(n*np.pi*x)*np.exp(-(n*np.pi)**2*t)
    return x + u


fig, ax = plt.subplots()

ax.set_xlim(0, 1)
ax.set_ylim(-0.1, 1.1)

T = 0.3
x = np.linspace(0, 1, 100)
t = np.linspace(0, T, 100)



line2, = ax.plot(x, f(x, t[0]), color = 'darkslategray', linewidth = 5, alpha = 0.3)

def animation_frame(i):

    line2.set_xdata(x)
    line2.set_ydata(f(x, t[i]))
    plt.title(r'$t = %.2f$' % t[i])

    return line2

plt.xlabel(r'$x$', fontdict = None)
plt.ylabel(r'$u(x, t)$', fontdict = None)
plt.legend(['Analytical solution'], loc = 'upper left')


animation = FuncAnimation(fig, func = animation_frame, frames = np.arange(1, len(t)), interval = 1, repeat_delay = 1000)


#animation.save('analytical.gif', writer='imagemagick', fps=10)

plt.show()
